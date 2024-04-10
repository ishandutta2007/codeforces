#include <bits/stdc++.h>
using namespace std;
const int N=6000006;
const long long M=998244353;

long long ast(long long x,long long n)
{
    if(n==0)
        return 1;
    if(n%2==0)
    {
        long long res=ast(x,n/2);
        return (res*res)%M;
    }
    else
    {
        long long res=ast(x,n-1);
        return (x*res)%M;
    }
}

int n;
long long a[N];

long long b[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;
    b[0]=1;
    for(int i=1;i<=n;++i)
    {
        b[i]=(ast(2,i)+(i*ast(2,i-1))%M)%M;
    }
    long long ans=0;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        ans=(ans+(b[n-i]*a[i])%M)%M;
    }
    cout<<ans<<endl;
    return 0;
}