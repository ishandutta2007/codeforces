#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=3e3+100,mod=1e9+7,inf=1e18;

vector<int> G[N];
vector<pii> path[N];
ll n,dis[N][N],sl[N],p[N][N],val[N][N],dp[N][N];

void read()
{
    cin>>n;
    for (int i=1,u,v;i<n;i++)
    {
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
}

void dfs(int x,int u)
{
    sl[u]=1;
    for (int v : G[u])
        if (!sl[v])
        {
            dis[x][v]=dis[x][u]+1;
            p[x][v]=u;
            dfs(x,v);
            sl[u]+=sl[v];
        }
}

void dfs2(int x,int u,ll ssl)
{
    val[x][u]=ssl*sl[u];
    for (int v : G[u])
        if (dis[x][v]>dis[x][u]) dfs2(x,v,ssl);
}

ll getv(int u,int v)
{
    if (u>v) swap(u,v);
    return dp[u][v];
}

void build()
{
    for (int i=1;i<=n;i++)
    {
        for (int i=1;i<=n;i++) sl[i]=0;
        dfs(i,i);
        for (int v : G[i]) dfs2(i,v,n-sl[v]);
    }
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++) path[dis[i][j]].pb(mp(i,j));
    ll res=0;
    for (int i=1;i<=n;i++)
        for (pii x : path[i])
        {
            int u=x.fi,v=x.se;
            int pv=p[u][v],pu=p[v][u];
            dp[u][v]=val[u][v]+max(getv(u,pv),getv(v,pu));
            res=max(res,dp[u][v]);
        }
    cout<<res;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    read();
    build();
    return 0;
}