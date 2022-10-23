#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
const ll maxn=2e5+1;
vector<pii> G[maxn];
ll n,f[maxn][2],visit[maxn];

void read()
{
    cin>>n;
    int u,v,c;
    for (int i=1;i<=n;i++)
    {
        cin>>u>>v>>c;
        G[u].pb({v,c});
        G[v].pb({u,c});
    }
}

void dfs(int u)
{
    visit[u]=1;
    for (int i=0;i<G[u].size();i++)
        if (!visit[G[u][i].fi])
        {
            ll v=G[u][i].fi,c=G[u][i].se;
            dfs(v);
            f[u][c]+=f[v][c]+1;
        }
}

void dfs2(int u)
{
    visit[u]=1;
    for (int i=0;i<G[u].size();i++)
        if (!visit[G[u][i].fi])
        {
            ll v=G[u][i].fi,c=G[u][i].se;
            f[v][c]+=f[u][c]-f[v][c];
            dfs2(v);
        }
}

void process()
{
    dfs(1);
    for (int i=1;i<=n;i++) visit[i]=0;
    dfs2(1);
    ll ans=0;
    for (int i=1;i<=n;i++) ans+=f[i][0]+f[i][1]+f[i][0]*f[i][1];
    cout<<ans;
}
int main()
{
    //freopen("ss.inp","r",stdin);
    read();
    process();
    return 0;
}