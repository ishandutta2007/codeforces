#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
const ll maxn=1e5+1,msiz=2,mod=1e9+7,inf=1e9;
vector<int> G[maxn],d[101];
int n,m,a[maxn],s,k,f[maxn][101];

void bfs(int st)
{
    queue<int> q;
    for (int i=0;i<d[st].size();i++) q.push(d[st][i]);
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        for (int i=0;i<G[u].size();i++)
            if (f[G[u][i]][st]==inf)
            {
                f[G[u][i]][st]=f[u][st]+1;
                q.push(G[u][i]);
            }
    }
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k>>s;
    int u,v;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=k;j++) f[i][j]=inf;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        d[a[i]].pb(i);
        f[i][a[i]]=0;
    }
    for (int i=1;i<=m;i++)
    {
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
    for (int i=1;i<=k;i++) bfs(i);
    for (int i=1;i<=n;i++)
    {
        vector<int> tmp;
        for (int j=1;j<=k;j++) tmp.pb(f[i][j]);
        sort(tmp.begin(),tmp.end());
        ll res=0;
        for (int j=0;j<s;j++) res+=tmp[j];
        cout<<res<<" ";
    }
    return 0;
}