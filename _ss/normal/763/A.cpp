#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
const ll maxn=1e5+1,msiz=2,mod=1e9+7,inf=1e18;
vector<int> G[maxn];
int c[maxn],n,visit[maxn],check;

void dfs(int u)
{
    visit[u]=1;
    for (int i=0;i<G[u].size();i++)
        if (!visit[G[u][i]])
        {
            if (c[u]!=c[G[u][i]]) check=1;
            dfs(G[u][i]);
        }
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int u,v;
    cin>>n;
    for (int i=1;i<n;i++)
    {
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
    for (int i=1;i<=n;i++) cin>>c[i];
    int flag=0;
    for (int i=1;i<=n;i++)
        for (int j=0;j<G[i].size();j++)
            if (c[i]!=c[G[i][j]])
            {
                flag=1;
                u=i;
                v=G[i][j];
            }
    if (!flag)
    {
        cout<<"YES\n1";
        return 0;
    }
    check=0;
    visit[u]=1;
    for (int i=0;i<G[u].size();i++) dfs(G[u][i]);
    if (!check)
    {
        cout<<"YES\n"<<u;
        return 0;
    }
    for (int i=1;i<=n;i++) visit[i]=0;
    visit[v]=1;
    check=0;
    for (int i=0;i<G[v].size();i++) dfs(G[v][i]);
    if (check) cout<<"NO";
    else cout<<"YES\n"<<v;
    return 0;
}