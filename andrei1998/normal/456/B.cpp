#include <iostream>
#include <string>

using namespace std;

int main()
{
    string x;
    cin>>x;
    int nr=0;
    if(x.size()==1){
        nr=(x[0]-'0')%4;
    }
    else{
        int a=x[x.size()-1]-'0';
        int b=x[x.size()-2]-'0';

        nr=(10*b+a)%4;
    }

    if(!nr)
        cout<<"4\n";
    else
        cout<<"0\n";

    return 0;
}