#include <bits/stdc++.h>

using namespace std;

#define int long long

int n;
int mod = 1e9 + 7;
int dp[2005][2005][2];

void dfs(int h, int bal){
    if (n - h + 1 < bal || (n - h + 1 - bal) % 2 == 1){
        dp[h][bal][0] = -2, dp[h][bal][1] = -2;
        return;
    }
    if (h == n + 1){
        dp[h][bal][0] = 0, dp[h][bal][1] = 0;
        return;
    }
    if (dp[h + 1][bal + 1][0] == -1) dfs(h + 1, bal + 1);
    if (bal - 1 >= 0){
        if (dp[h + 1][bal - 1][0] == -1) dfs(h + 1, bal - 1);
        int ans1 = 0, ans2 = 0;
        if (max(dp[h + 1][bal - 1][1], dp[h + 1][bal - 1][0]) >= 0) ans1 = max(dp[h + 1][bal - 1][1], dp[h + 1][bal - 1][0]);
        if (max(dp[h + 1][bal + 1][1], dp[h + 1][bal + 1][0]) >= 0) ans2 = max(dp[h + 1][bal + 1][1], dp[h + 1][bal + 1][0]);
        dp[h][bal][0] = ans1 + ans2;
        int cnt1 = -1, cnt2 = -1;
        if (dp[h + 1][bal - 1][0] >= 0) cnt1 = dp[h + 1][bal - 1][0];
        if (dp[h + 1][bal + 1][0] >= 0) cnt2 = dp[h + 1][bal + 1][0];
        dp[h][bal][1] = max(ans1 + cnt2 + 1, ans2 + cnt1 + 1);
    }
    else{
        int ans1 = max({(long long)0, dp[h + 1][bal + 1][0], dp[h + 1][bal + 1][1]});
        dp[h][bal][0] = ans1;
        int ans2 = max({(long long)-1, dp[h + 1][bal + 1][0]});
        dp[h][bal][1] = ans2 + 1;
    }
    for (int z = 0; z <= 1; ++z) dp[h][bal][z] %= mod;
}

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    n *= 2;
    for (int i = 0; i <= n; ++i) for (int j = 0; j <= n; ++j) for (int z = 0; z <= 1; ++z) dp[i][j][z] = -1;
    dfs(1, 0);
    cout << max(dp[1][0][0], dp[1][0][1]) << '\n';
    return 0;
}