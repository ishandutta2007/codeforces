#include <iostream>

using namespace std;

inline void print(int n)
{
    if(!n)
        return;

    //Afisam n%10
    int cifra=n%10;
    n/=10;

    if(cifra>=5){
        cout<<"-O|";
        cifra-=5;
    }
    else
        cout<<"O-|";

    if(!cifra)
        cout<<"-OOOO\n";
    else if(cifra==1)
        cout<<"O-OOO\n";
    else if(cifra==2)
        cout<<"OO-OO\n";
    else if(cifra==3)
        cout<<"OOO-O\n";
    else
        cout<<"OOOO-\n";

    print(n);
}

int main()
{
    int n;
    cin>>n;

    if(!n){
        cout<<"O-|-OOOO\n";
        return 0;
    }

    print(n);
    return 0;
}