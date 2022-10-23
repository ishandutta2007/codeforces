#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=3e3+10;
vector<pii> G[N];
int n,dp[N],p[N],res=1e9;

void read()
{
    cin>>n;
    for (int i=1,u,v;i<n;i++)
    {
        cin>>u>>v;
        G[u].pb(mp(v,0));
        G[v].pb(mp(u,1));
    }
}

void dfs_cost(int u)
{
    dp[u]=0;
    for (pii v : G[u])
        if (v.fi!=p[u])
        {
            p[v.fi]=u;
            dfs_cost(v.fi);
            dp[u]+=dp[v.fi]+v.se;
        }
}

void dfs_cal(int u,int cost,int sl0,int best,int len)
{
    res=min(res,cost+dp[u]+len-best);
    for (pii v : G[u])
        if (v.fi!=p[u])
        {
            if (v.se) dfs_cal(v.fi,cost+dp[u]-dp[v.fi]-1,sl0,best+1,len+1);
            else dfs_cal(v.fi,cost+dp[u]-dp[v.fi],sl0+1,max(best,sl0+1),len+1);
        }
}

void process()
{
    for (int root=1;root<=n;root++)
    {
        for (int i=1;i<=n;i++) p[i]=0;
        dfs_cost(root);
        dfs_cal(root,0,0,0,0);
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