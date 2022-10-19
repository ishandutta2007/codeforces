#include <iostream>

#define long long long

using namespace std;

long n,m;

long pow(void){
    long a=1,b=3;
    while (n>0){
        if (n%2==1)
        a*=b;
        a%=m;
        b*=b;
        b%=m;
        n>>=1;
    }
    return a;
}

int main()
{
    cin>>n>>m;
    cout<<(pow()+m-1)%m<<"\n";
    return 0;
}