#include <iostream>

using namespace std;

int main()
{
    long n,k;
    cin>>n;
    k=n/2;
    cout<<k*(n-k)<<"\n";
    for (long i=1; i<=k; ++i)
    for (long j=k+1; j<=n; ++j)
    cout<<i<<" "<<j<<"\n";
    return 0;
}