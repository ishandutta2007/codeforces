#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll mod=998244353;
ll pows(ll x,ll y)
{
    ll ans=1;
    ll now=x;
    for(;y;y/=2,now=now*now%mod)
    {
        if(y%2)ans=ans*now%mod;
        //cout<<now<<endl;
    }
    return ans;
}
ll dev(ll ans)
{
    return pows(ans,mod-2);
}
struct _
{
    int x;
    int y;
    ll k;
}p[1000005];int nn;
bool cmp(_ x,_ y)
{
    return x.k<y.k;
}
ll ans[1000005];
int main()
{
    //cout<<"!!"<<pows(2,10)<<endl;;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
    {
        scanf("%lld",&p[nn].k);
        p[nn].x=i;
        p[nn].y=j;
        nn++;
    }
    //ll val=0;
    ll nowx1=0,nowx2=0,nowy1=0,nowy2=0,nown=0,sumans=0;
        ll rx,cy;
        scanf("%lld",&rx);
        scanf("%lld",&cy);
    sort(p,p+nn,cmp);
    for(int i=0;i<nn;)
    {
        //if(p[i].k==val)
        {
            //
            //return 0;
        }
        int j;
        for(j=i;j<nn;j++)
        {
            if(p[i].k!=p[j].k)break;
        }
        for(int t=i;t<j;t++)
        {
            //cout<<p[t].x<<" "<<p[t].y<<" "<<ans[t]<<endl;
            if(nown>0)
            {
                ans[t]+=sumans*dev(nown)%mod;
                ans[t]+=nowx2*dev(nown)%mod;
                ans[t]-=2*p[t].x%mod*nowx1%mod*dev(nown)%mod;
                ans[t]+=p[t].x%mod*p[t].x%mod;
                ans[t]+=nowy2*dev(nown)%mod;
                ans[t]-=2*p[t].y%mod*nowy1%mod*dev(nown)%mod;
                ans[t]+=p[t].y%mod*p[t].y%mod;
                ans[t]%=mod;
                if(ans[t]<0)ans[t]+=mod;
            }
            //agggaw:;;
            //cout<<p[t].x<<" "<<p[t].y<<" "<<ans[t]<<endl;
            //cout<<nowx1<<"  "<<nowx2<<"  "<<nowy1<<"  "<<nowy2<<"  "<<nown<<endl;
            if(rx==p[t].x&&cy==p[t].y)
            {
                cout<<ans[t]<<endl;
                //return 0;
            }
        }//nowx1=0,nowx2=0,nowy1=0,nowy2=0,nown=0,sumans=0;
        for(int t=i;t<j;t++)
        {
            nowx1+=p[t].x;
            nowx2+=p[t].x*p[t].x%mod;
            nowy1+=p[t].y;
            nowy2+=p[t].y*p[t].y%mod;
            nown++;
            sumans+=ans[t];
            //
            nowx1%=mod;
            nowx2%=mod;
            nowy1%=mod;
            nowy2%=mod;
            nown%=mod;
            sumans%=mod;
        }
        i=j;
    }
    for(int i=0;i<nn;i++)
    {
        //cout<<ans[i]<<endl;
    }
    return 0;
}