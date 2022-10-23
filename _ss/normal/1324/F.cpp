#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=2e5+10;
vector<int> G[N];
int n,a[N],dp[N];

void read()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1,u,v;i<n;i++)
    {
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
}

void dfs(int u,int r)
{
    if (a[u]) dp[u]=1;
    else dp[u]=-1;
    for (int v : G[u])
        if (v!=r)
        {
            dfs(v,u);
            if (dp[v]>0) dp[u]+=dp[v];
        }
}

void dfs2(int u,int r)
{
    for (int v : G[u])
        if (v!=r)
        {
            if (dp[v]>=0) dp[v]=max(dp[v],dp[u]);
            else if (dp[u]>0) dp[v]+=dp[u];
            dfs2(v,u);
        }
}

void process()
{
    dfs(1,0);
    dfs2(1,0);
    for (int i=1;i<=n;i++) cout<<dp[i]<<" ";
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