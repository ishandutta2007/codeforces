#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v[n+1];
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int res=0;
    vector<array<int,2>> dp(n+1,{0,0});
    vector<int> d(n+1,0);
    function<void(int,int)> dfs=[&](int a,int p)
    {
        d[a]=v[a].size();
        res=max(res,d[a]);
        dp[a]={d[a]-1,1};
        vector<int> zero,one;
        int za=-1,zb=-1,oa=-1,ob=-1;
        for(int to:v[a])
        {
            if(to==p) continue;
            dfs(to,a);
            int t=max(dp[to][0],dp[to][1]);
            if(t>za)
            {
                zb=za;
                za=t;
            }
            else if(t>zb) zb=t;
            if(dp[to][0]>oa)
            {
                ob=oa;
                oa=dp[to][0];
            }
            else if(dp[to][0]>ob) ob=dp[to][0];
            dp[a][0]=max(dp[a][0],t+d[a]-2);
            dp[a][1]=max(dp[a][1],dp[to][0]+1);
            res=max({res,t+d[a]-1,dp[to][0]+1});
        }
        if(zb!=-1) res=max({res,za+zb+d[a]-2,oa+ob+1});
    };
    dfs(1,0);
    cout << res << "\n";
    return 0;
}