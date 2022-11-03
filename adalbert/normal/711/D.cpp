#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define fir first
#define sec second
using namespace std;
typedef double ld;
typedef long long ll;
const ll md=1e9+7;
///--------------------------------------------------------------///
ll type[300000],len[300000],cukl[300000],way[300000],start[300000],cnt[300000];
vector <ll> vec[300000];





///-------------------------------------------------------------///
ll bpow (ll u , ll step)
{
    u=(u+md)%md;
    if (step==0) return(1); else
    if (step%2==1) return((bpow(u,step-1)*u+md)%md); else
    {
        ll d=bpow(u,step/2);
        d=(d+md)%md;
        return((d*d+md)%md);
    }
}
void dfs(ll u, ll typ)
{
    type[u]=typ;
    for (int i=0;i<vec[u].size();i++)
        if (type[vec[u][i]]==0)
        dfs(vec[u][i],typ);
}
void dfs2(ll u, ll typ, ll w)
{
   // cout<<u<<'\n';
    len[u]=w;
    if (len[way[u]]==-1) dfs2(way[u],typ,w+1); else
        cukl[typ]=w-len[way[u]]+1;
}
///---program start---///
main()
{
    ll n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>way[i];
        vec[i].push_back(way[i]);
        vec[way[i]].push_back(i);
    }
    ll kilk=0;
    for (int i=1;i<=n;i++)
        if (type[i]==0)
    {
        kilk++;
        start[kilk]=i;
        dfs(i,kilk);
    }
    for (int i=1;i<=n;i++)
        len[i]=-1;
    for (int i=1;i<=kilk;i++)
    {
        dfs2(start[i],i,0);
    }
    for (int i=1;i<=n;i++)
        cnt[type[i]]++;
        ll ans=1;
    for (int i=1;i<=kilk;i++)
    {


        ans*=((bpow(2,cnt[i]-cukl[i])+md)%md);
        ans=(ans+md)%md;
        if (cukl[i]>1)
        {
            ans*=(((bpow(2,cukl[i])-2)+md)%md);
        }
        ans=(ans+md)%md;
    }
    cout<<ans;

}