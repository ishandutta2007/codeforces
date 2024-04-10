#include<bits/stdc++.h>
 
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=3e5+10;
ll val[maxn],mask[maxn],check[64],n,s=0;
 
void read()
{
    cin>>n;
    for (int i=1;i<=n;i++) scanf("%I64d %I64d",&val[i],&mask[i]),s+=val[i];
}
 
ll getv(ll x)
{
    ll kq=s;
    for (int i=1;i<=n;i++)
        if ((mask[i]>>x)&1) kq-=2*val[i];
    return kq;
}
 
void change(ll x)
{
    for (int i=1;i<=n;i++)
        if ((mask[i]>>x)&1) s-=2*val[i],val[i]=-val[i];
}
 
void process()
{
    if (s<0)
    {
    for (int i=1;i<=n;i++) val[i]=-val[i];
    s=-s;
    }
    ll ans=0,tt=1;
    while (s>=0)
    {
        ll tmp=1e18,t;
        for (int i=61;i>=0;i--)
        if (!check[i])
        {
            ll kd=getv(i);
            if (kd<tmp)
            {
                tmp=kd;
                t=i;
            }
        }
        change(t);
        check[t]=1;
        ans+=tt<<t;
    }
    cout<<ans;
}
 
int main()
{
    //freopen("ss.inp","r",stdin);
    read();
    process();
    return 0;
}