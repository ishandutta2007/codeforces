#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll a[300005],b[300005];
ll sa[300005],sb[300005];
ll ssa[300005],ssb[300005];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)scanf("%lld",a+i);
    for(int i=0;i<n;i++)scanf("%lld",b+i);
    for(int i=n;i>0;i--)
    {
        sa[i-1]=sa[i]+a[i-1];
        sb[i-1]=sb[i]+b[i-1];
    }
    for(int i=n;i>0;i--)
    {
        ssa[i-1]=ssa[i]+sa[i-1];
        ssb[i-1]=ssb[i]+sb[i-1];
    }
    ll ans=0,now,save=0;
    for(int i=0;i<n;i++)
    {
        ll t=i+n-1;
        ll re=n-i;
        if(i%2)
        {
            now=sb[i]*(t-re)+ssb[i];
            now+=sa[i]*(t+re+1)-ssa[i];
        }
        else
        {
            now=sa[i]*(t-re)+ssa[i];
            now+=sb[i]*(t+re+1)-ssb[i];
        }
        ans=max(ans,now+save);
        if(i%2)save+=2*i*b[i]+(2*i+1)*a[i];
        else save+=2*i*a[i]+(2*i+1)*b[i];
    }
    cout<<ans<<endl;
    return 0;
}