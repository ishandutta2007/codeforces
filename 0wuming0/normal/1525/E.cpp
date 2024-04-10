#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll mod=998244353;
ll pows(ll a,ll b)
{
    ll ans=1;
    for(;b;b>>=1,a=a*a%mod)
    {
        if(b&1)ans=ans*a%mod;
    }
    return ans;
}
ll inv(ll n)
{
    return pows(n,mod-2);
}
ll dev[1000006];
int a[25][50006];
int b[25];
ll ans;
int n,m;
ll d;
void solve()
{
    sort(b+1,b+1+n);
    ll now=1;
    //for(int i=1;i<=n;i++)printf("%d%c",b[i]," \n"[i==n]);
    for(int i=1;i<=n;i++)
    {//cout<<b[i]<<" ";
        if(b[i]<=i)
        {
            ans++;
            ans%=mod;//cout<<ans<<endl;
            return;
        }
        now=now*(b[i]-i)%mod;
    }//cout<<"<<<"<<now<<endl;
    now=now*d%mod;
    now=1-now;
    now%=mod;
    if(now<0)now+=mod;
    ans+=now;//cout<<ans<<" "<<now<<endl;
    ans%=mod;
}
int main()
{
    for(int i=1;i<1000006;i++)dev[i]=inv(i);
    //for(int i=1;i<1000006;i++)if(dev[i]*i%mod!=1)return 1;
    cin>>n>>m;
    d=1;
    for(int i=1;i<=n;i++)d=d*i%mod;//cout<<d<<endl;
    d=inv(d);//cout<<d<<endl;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
    for(int j=1;j<=m;j++)
    {
        for(int i=1;i<=n;i++)b[i]=a[i][j];
        solve();//cout<<"!!!!!"<<j<<endl;
    }
    cout<<ans<<endl;
    return 0;
}