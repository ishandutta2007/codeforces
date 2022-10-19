#include <iostream>

#define M 100100
#define long long long

using namespace std;

long n,a[M],b[M];

int main()
{
    long t=1;
    cin>>n;
    for (long i=1; i<=n; ++i)
    cin>>a[i];
    while (t<=n)
    t<<=1;
    for (long i=1; i<n;  ++i){
        while (t>n-i)
        t>>=1;
        b[i]=b[i-1]+a[i];
        a[i+t]+=a[i];
    }
    for (long i=1; i<n; ++i)
    cout<<b[i]<<"\n";
    return 0;
}