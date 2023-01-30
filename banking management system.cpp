#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>
using namespace std;

class Transaction
{
private:
    //attributes
    int transactionID;
    string transactionName;
    string transactionDate;

public:
    //constructors
    Transaction()
    {
        transactionID = 0;
        transactionName = "";
        transactionDate = "";
    }

    Transaction(int id, string name, string date)
    {
        transactionID = id;
        transactionName = name;
        transactionDate = date;
    }

    //setters
    void set_transactionID(int id)
    {
        transactionID = id;
    }
    void set_transactionName(string name)
    {
        transactionName = name;
    }
    void set_transactionDate(string date)
    {
        transactionDate = date;
    }

    //getters
    int get_transactionID()
    {
        return transactionID;
    }
    string get_transactionName()
    {
        return transactionName;
    }
    string get_transactionDate()
    {
        return transactionDate;
    }

    //display function
    void printTransactions()
    {
        cout << "Transaction ID:\t\t" << get_transactionID() << endl;
        cout << "Transaction Name:\t" << get_transactionName() << endl;
        cout << "Transaction Date:\t" << get_transactionDate() << endl;
    }


};

class Client
{
private:
    //attributes
    string clientName;
    string clientEmail;
    string clientPhone;
    string clientAddress;
    string clientPassword;
    int clientID;
    Transaction* clientTransactions;
    int maxSizeTran;
    int counterTran;

public:
    //constructors
    Client()
    {
        clientName = "";
        clientEmail = "";
        clientPhone = "";
        clientAddress = "";
        clientPassword = "";
        clientID = 0;
        maxSizeTran = 5;
        clientTransactions = new Transaction[maxSizeTran];
        counterTran = 0;

    }

    Client(string name, string email, string phone, string address, string password, int id)
    {
        clientName = name;
        clientEmail = email;
        clientPhone = phone;
        clientAddress = address;
        clientPassword = password;
        clientID = id;
        maxSizeTran = 5;
        clientTransactions = new Transaction[maxSizeTran];
        counterTran = 0;
    }

    bool isFull()//check if the transactions array is full or not
    {
        return counterTran == maxSizeTran;
    }

    //setter methods
    void set_clientName(string name)
    {
        clientName = name;
    }
    void set_clientEmail(string email)
    {
        clientEmail = email;
    }
    void set_clientPhone(string phone)
    {
        clientPhone = phone;
    }
    void set_clientAddress(string address)
    {
        clientAddress = address;
    }
    void set_clientPassword(string password)
    {
        clientPassword = password;
    }
    void set_clientID(int id)
    {
        clientID = id;
    }
    void set_counterTran(int num){
        counterTran = num;
    }
    void set_Transaction(Transaction trans)
    {
        if (isFull())
        {
            cout<<"Cannot add Transaction. Transactions array is full."<<endl;
            return;
        }
        for (int index = 0; index < counterTran; index++)
        {
            if (clientTransactions[index].get_transactionID() == trans.get_transactionID())
            {
                cout<<"Transaction already exists."<<endl;
                return;
            }

        }
        clientTransactions[counterTran] = trans;
        counterTran++;
        cout<<"\nTransaction added successfully."<<endl;
    }

    //getter methods
    string get_clientName()
    {
        return clientName;
    }
    string get_clientEmail()
    {
        return clientEmail;
    }
    string get_clientPhone()
    {
        return clientPhone;
    }
    string get_clientAddress()
    {
        return clientAddress;
    }
    string get_clientPassword()
    {
        return clientPassword;
    }
    int get_clientID()
    {
        return clientID;
    }
    int get_counterTran()
    {
        return counterTran;
    }
    Transaction get_Transaction(int i)
    {
        return clientTransactions[i];
    }

    //delete a transaction method
    void deleteTransaction(Transaction& tempTran){
        if(counterTran==0){//if no transactions in array
            cout<<"\nThis client has no transactions"<<endl;
            return;
        }
        for (int index = 0; index < counterTran; index++) {
            if(get_Transaction(index).get_transactionID() == tempTran.get_transactionID()){
                clientTransactions[index] = clientTransactions[index+1]; //delete element
                counterTran--;
                }
            }
        }

    //display client info
    void displayClientInfo()
    {
        cout << "--------Client info-----" << endl;
        cout << "Client name: " << get_clientName() << endl;
        cout << "Client email: " << get_clientEmail() << endl;
        cout << "Client phone: " << get_clientPhone() << endl;
        cout << "Client Address: " << get_clientAddress() << endl;
        cout << "Client ID: " << get_clientID() << endl;
        if(counterTran==0){//if no transactions in array
            cout<<"\nThis client has no transactions"<<endl;
            return;
        }
        cout << "Client Transactions: " << endl;
        for (int index = 0; index < counterTran; index++) {
            get_Transaction(index).printTransactions();//printing each transaction
            cout << endl;
        }

    }
};

class LinkedListNode
{
    private:
        //attributes
        Client data;
        LinkedListNode* next;
    public:
        //constructor
        LinkedListNode(Client data)
        {
        this->data = data;
        next = nullptr;
        }

        //setters
        void setData(Client c)
        {
            data = c;
        }
        void setNext(LinkedListNode* n)
        {
            next = n;
        }

        //getters
        Client getData()
        {
            return data;
        }
        LinkedListNode* getNext()
        {
            return next;
        }
};

class ClientsLinkedList
{
private:
    //attributes
    LinkedListNode* head;
    int listSize;

public:
    //constructor
    ClientsLinkedList()
    {
        head = NULL;
        listSize = 0;
    }

    //to get list size
    int getListSize(){
        return listSize;
    }

    //this Function appends new Clients
    void insertClient(Client value)
    {
        //create and allocate new Node
        LinkedListNode* newNode = new LinkedListNode(value);
        LinkedListNode* temp = head; //to traverse
        listSize++; //increase list size
        if (!head) //if list is empty
        {
            head = newNode;
            head->setNext(nullptr);
            cout<<"\nClient is added successfully"<<endl;
            return ;
        }

        // Traverse till end of list
        while (temp->getNext()!= nullptr)
        {
            temp = temp->getNext();
        }

        // append
        temp->setNext(newNode);
        newNode->setNext(nullptr);
        cout << "New Client is added successfully"<<endl;
        return;
    }

    //check if CLient is inserted
    LinkedListNode *isInserted(string email)
    {
        LinkedListNode *temp = head;//create temp to traverse
        //traversing
        while(temp && temp->getData().get_clientEmail()!=email)
        {
        temp = temp->getNext();
        }
        return temp;
    }

    //to get the client's password for the forgotPassword() function
    string getClientPassword(string email)
    {
        LinkedListNode *temp = head;//create temp to traverse
        //traversing
        while(temp && temp->getData().get_clientEmail()!=email)
        {
            temp = temp->getNext();
        }
        //if temp != NULL
        if(temp)
        {
           return temp->getData().get_clientPassword();
        }
        return "";
    }

    //displays linked list for the bonus part
    void displayList()
    {
        LinkedListNode* temp = head; //to traverse
        //in case of Empty list
        if(!temp)
        {
            cout<<"\nList is Empty"<<endl;
            return;
        }

        //traversing
        while(temp)
        {
            cout<<"\n";
            temp->getData().displayClientInfo(); //display each node
            temp = temp->getNext();
            cout<<"---------------------------------------------------------------------------"<<endl;
        }
    }

    int counter(){
        int cnt = 0;
        LinkedListNode* temp=head; //to traverse
        if(!temp) {
            return 0;
        }
        //traversing
        while(temp){
            cnt++;
            temp = temp->getNext();
        }
        return cnt;
    }

    void sortLinkedList()//to sort the linked list
    {
        LinkedListNode *current = head, *temp = NULL;
        Client tempClient;
        if (!head ) {//if linked list is empty
            return ;
        }
        while (current) {
            temp = current->getNext();
            while (temp ) {
                if (current->getData().get_clientID() > temp->getData().get_clientID()) {
                    tempClient = current->getData();
                    current->getData() = temp->getData();
                    temp->getData() = tempClient;
                }
            temp = temp->getNext();
            }
        current = current->getNext();
        }
    }
};


//Global variables and Function prototypes
ClientsLinkedList clientArray[10];
void mainMenu();
void forgetPassword();
void loginMenu();
void newClientMenu();
string Password();
void hashing(Client c);
void transactionsMenu(Client c);
void clientHome(Client c);
void SortEachLinkedList();
void swap(ClientsLinkedList* a, ClientsLinkedList* b);
int partition( int low, int high);
void quickSort(int low, int high);
void display_clientsArr();

int main()
{
    mainMenu();
}

void mainMenu(){
    cout<<"\n========================================================================="<<endl;
    cout<<"+++++++++++++++++++ Welcome to the Banking System +++++++++++++++++++++++"<<endl;
    cout<<"\nCHOOSE ONE OF THE FOLLOWING OPTIONS:"<<endl;
    cout<<"1. Login to your account"<<endl;
    cout<<"2. New client?"<<endl;
    cout<<"3. Forgot your password?"<<endl;
    cout<<"4. Sort clients by linked list size using the Quick Sort Algorithm"<<endl;
    cout<<"5. Sort clients by ID number"<<endl;
    cout<<"6. Exit the program\n>>";
    int choice;
    cin>>choice;
    cout<<"========================================================================="<<endl;
    switch (choice)
    {
    case 1:
        loginMenu();
        break;
    case 2:
        newClientMenu();
        break;
    case 3:
        forgetPassword();
        break;
    case 4:
        quickSort(0,9);
        display_clientsArr();
        break;
    case 5:
        SortEachLinkedList();
        break;
    case 6:
        cout<<"\nProgram terminating..."<<endl;
        exit(0);
    }
}

void forgetPassword(){
    cout<<"Please write Your Email\n>>";
    string email; cin>>email;
    for(int i = 0; i < 10 ; i++)
    {
        if(clientArray[i].isInserted(email))//find the client in the arry
        {
            cout<<"The password\n>>";
            cout<<clientArray[i].getClientPassword(email)<<endl;//return the client's password
            cout<<"\nNow you can login..."<<endl;
            loginMenu();
        }
    }
    cout<<"Client does not exist. Please try again."<<endl;
    mainMenu();
}

void loginMenu()
{
    cout<<"\n========================================================================="<<endl;
    cout<<"++++++++++++++++++++ Welcome to the Banking System ++++++++++++++++++++++"<<endl;
    cout<<"+++++++++++++++++++++++ Welcome back dear client ++++++++++++++++++++++++"<<endl;
    string email, password;
    cout<<"Please write your email\n>>";
    cin>>email;
    cout<<"Please write your password\n>>";
    cin>>password;
    cout<<"========================================================================="<<endl;
    for(int i=0; i<10; i++)
    {
        LinkedListNode *check;
        if(check = clientArray[i].isInserted(email))
        {
            if(password == check->getData().get_clientPassword())//go to client's home iff correct password
            {
                clientHome(check->getData());
                return;
            }
            else{//if the password is incorrect
                int choice;
                cout<<"Password is incorrect. Choose from the following options:"<<endl;
                cout<<"1. Forgot password"<<endl;
                cout<<"2. Try again"<<endl;
                cout<<"3. Back to main menu\n>>";
                cin>>choice;
                switch (choice)
                {
                case 1:
                    forgetPassword();
                    break;
                case 2:
                    cout<<"Reenter password\n>>";
                    cin>>password;
                    if(password == check->getData().get_clientPassword())
                    {
                        clientHome(check->getData());
                    }
                    break;
                case 3:
                    cout<<"\nReturning to Main Menu..."<<endl;
                    mainMenu();
                    break;
                }

            }
        }
    }

    string choice;//if the email is incorrect
    cout<<"Client's email is incorrect."<<endl;
    cout<<"Try again? (yes/no) ";
    cin>>choice;
    if(choice=="yes")
        loginMenu();
    else
    {
        cout<<"Returning to Main Menu..."<<endl;
        mainMenu();
    }
}

void newClientMenu(){
    cout<<"\n========================================================================="<<endl;
    cout<<"+++++++++++++++++++ Welcome to the Banking System +++++++++++++++++++++++"<<endl;
    cout<<"++++++++++++++++++++ Create a new Client Account ++++++++++++++++++++++++"<<endl;
    cout<<"\nPlease write your email\n>>";
    string email; cin>>email;
    for(int i = 0; i < 10 ; i++){
        if(clientArray[i].isInserted(email)){//make sure the client is not already in the array
            cout<<"\nThis Client is already Inserted. Login instead."<<endl;
            loginMenu();
        }
    }
    cout<<"Please write Your Name\n>>";
    string name; cin.ignore(); getline(cin,name);
    cout<<"please write your phone\n>>";
    string phone; cin>>phone;
    cout<<"please write your password\n>>";
    string password = Password();
    cout<<endl;
    cout<<"Please write your address\n>>";
    string adderess; cin>>adderess;
    cout<<"========================================================================="<<endl;

    // create a random id
    int id = rand();
    // insert Client info in client class
    Client client(name, email,phone,adderess, password,id);
    hashing(client);
    cout<<"Returning to Main Menu..."<<endl;
    mainMenu();
}

string Password(){
    string password;
    char character;
    character = getch();
    while(character != 13 ){ // ASCI code of Enter is 13
        password += character;
        cout<<'*';
        character = getch();
    }
    return password;
}

void hashing(Client c)
{
    int index_id = c.get_clientID() % 10;//get index
    clientArray[index_id].insertClient(c);//insert the client in the array
}

void transactionsMenu(Client c)
{
    cout<<"\n========================================================================="<<endl;
    cout<<"++++++++++++++++++ Welcome to the Banking System ++++++++++++++++++++++++"<<endl;
    cout<<"++++++++++++++++ Welcome to the transactions system +++++++++++++++++++++"<<endl;
    cout << "CHOOSE ONE OF THE FOLLOWING OPTIONS:" << endl;
    cout << "1. Create a new transaction" << endl;
    cout << "2. View your transactions" << endl;
    cout << "3. Delete a transaction by its ID\n>>";
    int choice;
    cin>> choice;
    cout<<"========================================================================="<<endl;
    if (choice == 1)
    {
        cout << "Create a new transaction:-" << endl;
        cout<<"Enter Transaction ID\n>>";
        int ID; cin>>ID;
        cout<<"Enter Transaction name\n>>";
        string name; cin>>name;
        cout<<"Enter Transaction date in DD/MM/YY form\n>>";
        string date;
        cin.ignore();
        getline(cin,date);
        Transaction temp(ID,name,date);
        c.set_Transaction(temp);//add transaction
        cout<<"\nReturning to Home Page..."<<endl;
        clientHome(c);
    }
    else if (choice == 2)
    {
        cout << "View your transactions:-" << endl;
        for(int j = 0; j < c.get_counterTran() ; j++){
            c.get_Transaction(j).printTransactions();
            cout<<endl;
        }
        cout<<"\nReturning to Home Page..."<<endl;
        clientHome(c);
    }
    else if (choice == 3)
    {
        cout<<"Delete a transaction by its ID:-"<<endl;
        Transaction temp;
        int id;
        cout<<"Please enter Transaction ID:\n>>";
        cin>>id;
        temp.set_transactionID(id);
        c.deleteTransaction(temp);
        cout<<"\nTransaction Deleted successfully"<<endl;
        cout<<"\nReturning to Home Page..."<<endl;
        clientHome(c);
    }
    else
    {
        cout << "Invalid choice.\nPlease try again." << endl;
        transactionsMenu(c);
    }
}

void clientHome(Client c){
    int choice;
    cout<<"\n========================================================================="<<endl;
    cout<<"++++++++++++++++++++ Welcome to the Banking System ++++++++++++++++++++++"<<endl;
    cout<<"++++++++++++++++++++++ Welcome to the Home Page +++++++++++++++++++++++++"<<endl;
    cout<<"\nCHOOSE ONE OF THE FOLLOWING OPTIONS:"<<endl;
    cout<<"1. Transactions menu"<<endl;
    cout<<"2. View personal info"<<endl;
    cout<<"3. Logout\n>>";
    cin>>choice;
    cout<<"========================================================================="<<endl;
    switch (choice)
    {
    case 1:
        transactionsMenu(c);
        break;
    case 2:
        c.displayClientInfo();
        cout<<"\nReturning to Home Page..."<<endl;
        clientHome(c);
        break;
    case 3:
        cout<<"\nLogging out..."<<endl;
        mainMenu();
        break;
    }
}

void swap(ClientsLinkedList* a, ClientsLinkedList* b)
{
    ClientsLinkedList t = *a;
    *a = *b;
    *b = t;
}

int partition( int low, int high){
    int pivot = clientArray[high].getListSize();
    int smallIndex= low-1;

    for (int i= low; i <high; i++) {
        if (clientArray[i].getListSize() < pivot) {
            smallIndex++;
            swap(clientArray[smallIndex], clientArray[i]);
        }
    }
    swap(clientArray[smallIndex+ 1], clientArray[high]);
    return smallIndex+ 1;
}

void quickSort(int low, int high)
{
    if (low < high)
    {
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi+ 1,high);
    }
}

void SortEachLinkedList(){
    for(int i = 0;i<10;i++){
        cout<<"----------------------------------------------------------------------"<<endl;
        cout<<"Linked list Number "<<i+1<<" "<<"has "<<clientArray[i].counter()<<" Clients"<<endl;
        cout<<"Index: "<<i;
        clientArray[i].sortLinkedList();
        clientArray[i].displayList();
    }
    cout<<"\nReturning to Main Menu..."<<endl;
    mainMenu();
}

void display_clientsArr()
{
    for(int i=0; i<10; i++)
    {
        cout<<"Index #"<<i<<" has "<<clientArray[i].getListSize()<<" clients."<<endl;
        if(clientArray[i].getListSize()!=0)
        {
            cout<<"clients of index #"<<i<<endl;
            clientArray[i].displayList();
        }
    }
    cout<<endl<<"Returning to Main Menu..."<<endl;
    mainMenu();
}
