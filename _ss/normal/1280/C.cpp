#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=3e5+10,mod=1e9+7,inf=1e18;
vector<pii> G[N];
ll n,p[N],slc[N],root,d[N];

void read()
{
    cin>>n;
    n*=2;
    for (int i=1;i<=n;i++) G[i].clear();
    for (int i=1,u,v,w;i<n;i++)
    {
        cin>>u>>v>>w;
        G[u].pb(mp(v,w));
        G[v].pb(mp(u,w));
    }
}

void dfs(int u)
{
    slc[u]=1;
    for (pii v : G[u])
        if (v.fi!=p[u])
        {
            p[v.fi]=u;
            dfs(v.fi);
            slc[u]+=slc[v.fi];
        }
}

void dfs2(int u)
{
    slc[u]=1;
    for (pii v : G[u])
        if (v.fi!=p[u])
        {
            p[v.fi]=u;
            d[v.fi]=d[u]+v.se;
            dfs2(v.fi);
            slc[u]+=slc[v.fi];
        }
}

void process()
{
    for (int i=1;i<=n;i++) p[i]=0;
    dfs(1);
    for (int i=1;i<=n;i++)
    {
        int check=1;
        for (pii v : G[i])
            if (v.fi!=p[i])
            {
                if (slc[v.fi]>n/2) check=0;
            }
        if (n-slc[i]>n/2) check=0;
        if (check) root=i;
    }
    for (int i=1;i<=n;i++) p[i]=0,d[i]=0;
    dfs2(root);
    ll res1=0,res2=0;
    for (int i=1;i<=n;i++) res2+=d[i];
    res1=res2;
    for (int i=1;i<=n;i++)
    {
        ll t=1;
        for (pii v : G[i])
            if (v.fi!=p[i]) t+=(slc[v.fi]&1);
        res1-=(t-(t&1))*d[i];
    }
    cout<<res1<<" "<<res2<<"\n";
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        read();
        process();
    }
    return 0;
}