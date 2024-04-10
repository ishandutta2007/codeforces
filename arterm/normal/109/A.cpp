#include <iostream>

using namespace std;

int main()
{
    long n,a,b;
    cin>>n;
    a=n/7;
    for (;a>=0;--a)
    if ((n+a)%4==0){
        b=(n-7*a)/4;
        for (long i=0; i<b; ++i)
        cout<<4;
        for (long j=0; j<a; ++j)
        cout<<7;
        return 0;
    }
    cout<<-1;
    return 0;
}