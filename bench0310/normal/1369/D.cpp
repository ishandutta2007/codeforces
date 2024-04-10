#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const ll mod=1000000007;
    int N=2000000;
    vector<vector<ll>> dp(N+1,vector<ll>(2,0));
    auto mx=[&](int n)->ll
    {
        if((n%3)==0) return dp[n][1];
        else return dp[n][0];
    };
    for(int i=3;i<=N;i++)
    {
        dp[i][0]=(2*mx(i-2)+mx(i-1))%mod;
        dp[i][1]=(4+2*dp[i-2][0]+dp[i-1][0])%mod;
    }
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << mx(n) << "\n";
    }
    return 0;
}