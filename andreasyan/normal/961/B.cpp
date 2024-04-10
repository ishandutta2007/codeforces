#include <bits/stdc++.h>
using namespace std;
const int N=100005;

long long ans;

int n,k;
int a[N];
long long p[N];

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        if(x==1)
        {
            ans+=a[i];
            a[i]=0;
        }
    }
    for(int i=1;i<=n;++i)
        p[i]=p[i-1]+a[i];
    long long maxu=0;
    for(int i=k;i<=n;++i)
    {
        maxu=max(maxu,p[i]-p[i-k]);
    }
    cout<<ans+maxu<<endl;
    return 0;
}