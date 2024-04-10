#include <iostream>

using namespace std;
const int maxn=int(10e5)+1;
long long n,a[maxn],b[maxn],d=0;
int main()
{
    cin>>n;
    for (int i=1;i*i<=n;i++)
    if (n%i==0)
    {
        d++;
        a[d]=n/i;
        b[d]=i;
    }
    for (int i=1;i<=d;i++) cout<<n*(n/a[i]-1)/2+n/a[i]<<" ";
    if (a[d]!=b[d])  cout<<n*(n/b[d]-1)/2+n/b[d]<<" ";
    for (int i=d-1;i>=1;i--) cout<<n*(n/b[i]-1)/2+n/b[i]<<" ";
    return 0;
}