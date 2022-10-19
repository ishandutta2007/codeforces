#include <iostream>

#define M 100100

using namespace std;

long n,a[M],b[M];

int main()
{
    cin>>n;
    for (long i=1; i<=n; ++i)
    cin>>a[i];
    for (long i=1,t; i<n;  ++i){
        t=1;
        while (t<=n-i)
        t<<=1;
        t>>=1;
        b[i]=b[i-1]+a[i];
        a[i+t]+=a[i];
    }
    for (long i=1; i<n; ++i)
    cout<<b[i]<<"\n";
    return 0;
}