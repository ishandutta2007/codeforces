#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
#define mp make_pair
const ll maxn=1e5+10,mod=1e9+7,inf=1e18;
int visit[maxn],n,k;
vector<int> G[maxn];

void dfs(int u)
{
    visit[u]=1;
    for (int i=0;i<G[u].size();i++)
        if (!visit[G[u][i]]) dfs(G[u][i]);
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    int u,v;
    for (int i=1;i<=k;i++)
    {
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
    int t=0,h=0;
    for (int i=1;i<=n;i++)
        if (G[i].size())
        {
            t++;
            if (!visit[i]) dfs(i),h++;
        }
    cout<<k-(t-h);
    return 0;
}