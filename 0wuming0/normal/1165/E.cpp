#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll mod=998244353;
ll a[200005],b[200005];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%lld",a+i);
        a[i]=a[i]*(i+1)*(n-i);
    }
    for(int i=0;i<n;i++)scanf("%lld",b+i);
    sort(a,a+n);
    sort(b,b+n);
    ll ans=0;
    for(int i=0,j=n-1;i<n;i++,j--)
    {
        ans+=a[i]%mod*b[j]%mod;
        ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
}