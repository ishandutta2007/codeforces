#include <iostream>

#define long long long

using namespace std;

long k,b,n,t;

long val(long p){
    if (k==1)
    return 1+p*b;
    long a=1;
    for (long i=1; i<=p; ++i)
    a*=k;
    return a+(a-1)/(k-1)*b;
}


int main()
{
    long d=0;
    cin>>k>>b>>n>>t;
    while (d<=n && val(d)<=t)
    ++d;
    cout<<n-d+1;

    return 0;
}