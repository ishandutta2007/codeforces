#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=2e5+1;
vector<ll> G[maxn];
ll a[maxn],n,val[maxn],sl[maxn],visit[maxn];

void read()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int u,v;
    for (int i=1;i<n;i++)
    {
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
}

void dfs(int u)
{
    visit[u]=1;
    for (int i=0;i<G[u].size();i++)
        if (!visit[G[u][i]])
        {
            ll v=G[u][i];
            dfs(v);
            sl[u]+=sl[v];
            val[u]+=val[v]+sl[v];
        }
}

void dfs2(int u)
{
    visit[u]=1;
    for (int i=0;i<G[u].size();i++)

        if (!visit[G[u][i]])
        {
            ll v=G[u][i];
            val[v]+=val[u]-val[v]-sl[v]+sl[u]-sl[v];
            sl[v]+=sl[u]-sl[v];
            dfs2(v);
        }
}

void process()
{
    for (int i=1;i<=n;i++) sl[i]=a[i];
    dfs(1);
    for (int i=1;i<=n;i++) visit[i]=0;
    dfs2(1);
    ll ans=0;
    for (int i=1;i<=n;i++) ans=max(ans,val[i]);
    cout<<ans;
    //for (int i=1;i<=n;i++) cout<<val[i]<<" ";
}
int main()
{
    //freopen("ss.inp","r",stdin);
    read();
    process();
    return 0;
}