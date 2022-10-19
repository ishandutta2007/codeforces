#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll a[105];
ll q[105];
ll n,k;
ll ans;
ll now;
void check(ll d)
{
    now=0;
    for(int i=0;i<n;i++)
    {
        int t=a[i]/d*d;
        if(t<a[i])t+=d;
        now+=t-a[i];
    }
    if(now<=k)ans=max(ans,d);
}
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(ll d=1;d<=100000;d++)
    {
        check(d);
    }
    for(ll d=100001;;d++)
    {
        ll dm=2e9,add=0;
        for(int i=0;i<n;i++)
        {
            q[i]=a[i]/d;
            if(q[i])
            {
                dm=min(a[i]/q[i],dm);
            }
            add+=q[i]+1;
        }
        check(d);
        if(dm==2e9)
        {
            d+=(k-now)/add;
            check(d);
            break;
        }
        if(now<=k)
        {
            d+=(k-now)/add;
            d=min(d,dm);
            check(d);
        }
        d=dm;
    }
    cout<<ans<<endl;
    return 0;
}