#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=5e4+1;
vector<ll> G[maxn];
ll k,n,visit[maxn],f[maxn][501],ans=0;

void read()
{
    cin>>n>>k;
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
            for (int j=0;j<k;j++) ans+=f[v][j]*f[u][k-1-j];
            for (int j=1;j<=k;j++) f[u][j]+=f[v][j-1];
        }
}

void process()
{
    for (int i=1;i<=n;i++) f[i][0]=1;
    dfs(1);
    cout<<ans;
}
int main()
{
    //freopen("ss.inp","r",stdin);
    read();
    process();
    return 0;
}