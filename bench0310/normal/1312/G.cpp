#include <bits/stdc++.h>

using namespace std;

const int N=1000005;
vector<pair<char,int>> v[N];
vector<int> cnt(N,0);
vector<int> ok(N,0);
vector<int> dp(N);

void dfs_ini(int a)
{
    sort(v[a].begin(),v[a].end());
    cnt[a]=ok[a];
    for(auto [c,to]:v[a])
    {
        dfs_ini(to);
        cnt[a]+=cnt[to];
    }
}

void dfs(int a,int best)
{
    if(ok[a]) dp[a]=min(dp[a],best+1);
    best=min(best,dp[a]);
    int now=ok[a];
    for(auto [c,to]:v[a])
    {
        dp[to]=dp[a]+1;
        dfs(to,best+now);
        now+=cnt[to];
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int p;
        char c;
        scanf("%d %c",&p,&c);
        v[p].push_back({c,i});
    }
    int k;
    scanf("%d",&k);
    vector<int> x(k);
    for(int i=0;i<k;i++)
    {
        scanf("%d",&x[i]);
        ok[x[i]]=1;
    }
    dfs_ini(0);
    dfs(0,0);
    for(int i=0;i<k;i++) printf("%d%c",dp[x[i]]," \n"[i==k-1]);
    return 0;
}