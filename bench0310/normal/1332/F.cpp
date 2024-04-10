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
    const ll mod=998244353;
    auto sub=[&](ll a,ll b)->ll{return (a-b+mod)%mod;};
    auto mul=[&](ll a,ll b)->ll{return (a*b)%mod;};
    vector<array<ll,3>> dp(n+1,{1,1,1});
    function<void(int,int)> dfs=[&](int a,int p)
    {
        for(int b:v[a])
        {
            if(b==p) continue;
            dfs(b,a);
            dp[a][0]=mul(dp[a][0],2*dp[b][0]+2*dp[b][1]+3*dp[b][2]);
            dp[a][1]=mul(dp[a][1],2*dp[b][0]+dp[b][1]+2*dp[b][2]);
            dp[a][2]=mul(dp[a][2],dp[b][0]+dp[b][1]+dp[b][2]);
        }
        dp[a][0]=sub(dp[a][0],dp[a][2]);
        dp[a][1]=sub(dp[a][1],dp[a][2]);
    };
    dfs(1,0);
    cout << sub(dp[1][0]+dp[1][1]+dp[1][2],1) << "\n";
    return 0;
}