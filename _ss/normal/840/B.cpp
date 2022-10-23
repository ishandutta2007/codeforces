#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
#define mp make_pair
const ll maxn=3e5+10,msiz=2,mod=1e9+7,inf=1e18;
vector<pii> G[maxn];
int n,m,d[maxn],edge[maxn],visit[maxn],flag=0,root=1,p[maxn],sl=0;
void read()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>d[i];
        if (d[i]==-1) flag=1,root=i;
    }
    int u,v;
    for (int i=1;i<=m;i++)
    {
        cin>>u>>v;
        G[u].pb(mp(v,i));
        G[v].pb(mp(u,i));
    }
}

void dfs(int u,int st)
{
    visit[u]=1;
    for (int i=0;i<(int)(G[u].size());i++)
        if (!visit[G[u][i].fi])
        {
            p[G[u][i].fi]=u;
            dfs(G[u][i].fi,G[u][i].se);
        }
    if (u!=root && d[p[u]]!=-1 && d[u]==1) d[p[u]]^=d[u];
    if (u!=root && d[u]==1) edge[st]=1,sl++;
}

void process()
{
    if (!flag)
    {
        for (int i=1;i<=n;i++) flag^=d[i];
        if (flag)
        {
            cout<<-1;
            return;
        }
    }
    dfs(root,0);
    cout<<sl<<endl;
    for (int i=1;i<=m;i++)
        if (edge[i]) cout<<i<<endl;
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