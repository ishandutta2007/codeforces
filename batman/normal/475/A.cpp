#include <iostream>
using namespace std;
#define N 34
int main() {
    int n;
    cin>>n;
    cout<<"+------------------------+"<<endl;
    ////////////////////////////////////////////
    cout<<"|";
    if(n>0)
        cout<<"O.";
    else
        cout<<"#."; 
    for(int i=5;i<34;i+=3)
    {
        if(i<=n)
            cout<<"O";
        else
            cout<<"#";
        cout<<".";      
    }
    cout<<"|D|)"<<endl;
    ////////////////////////////////////////
    cout<<"|";
    if(n>1)
        cout<<"O.";
    else
        cout<<"#."; 
    for(int i=6;i<34;i+=3)
    {
        if(i<=n)
            cout<<"O";
        else
            cout<<"#";
        cout<<".";      
    }   
    cout<<"|.|"<<endl;
    /////////////////////////////////////////////
    
    cout<<"|";
    if(n>2)
        cout<<"O";
    else
        cout<<"#";  
    cout<<".......................|"<<endl;
    ////////////////////////////////////////////
    cout<<"|";
    
    for(int i=4;i<=34;i+=3)
    {
        if(i<=n)
            cout<<"O";
        else
            cout<<"#";
        cout<<".";      
    }
    cout<<"|.|)"<<endl; 
    cout<<"+------------------------+"<<endl;
    return 0;
}