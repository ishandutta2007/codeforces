#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(),vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N=1e3+10;
struct edge {int u,v,w;};
const ll inf=1e18;
vector<pii> G[N];
ll d[N][N],n,m,q,vis[N][N],dist[N][N];
edge E[N*N];

void read()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) dist[i][j]=inf;
    for (int i=1,u,v,w;i<=m;i++)
    {
        cin>>u>>v>>w;
        G[u].eb(mp(v,w));
        G[v].eb(mp(u,w));
        dist[u][v]=dist[v][u]=w;
        E[i]={u,v,w};
    }
    cin>>q;
    for (int i=1,u,v,w;i<=q;i++)
    {
        cin>>u>>v>>w;
        d[u][v]=d[v][u]=w;
    }
}

void process()
{
    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++) dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
    for (int u=1;u<=n;u++)
    {
        for (int i=1;i<n;i++)
        {
            int v=0;
            for (int j=1;j<=n;j++)
                if (!vis[u][j] && d[u][j]>d[u][v]) v=j;
            vis[u][v]=1;
            for (pii p : G[v])
            {
                int r=p.fi,w=p.se;
                d[u][r]=max(d[u][r],d[u][v]-w);
            }
        }
    }
    int res=0;
    for (int i=1;i<=m;i++)
    {
        int u=E[i].u,v=E[i].v,w=E[i].w;
        if (w<=max(d[u][v],d[v][u]))
        {
            res++;
            continue;
        }
        for (int r=1;r<=n;r++)
            if (dist[v][r]+w<=d[r][u] || dist[u][r]+w<=d[r][v])
            {
                res++;
                break;
            }
    }
    cout<<res;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    read();
    process();
    return 0;
}