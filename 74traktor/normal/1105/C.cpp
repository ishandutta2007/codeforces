#include <bits/stdc++.h>

using namespace std;

#define int long long

int mod = 1e9 + 7;

int dp[200005][3];

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, l, r;
    cin >> n >> l >> r;
    if (l == r){
        if (r * n % 3 != 0) cout << 0 << endl;
        else cout << 1 << endl;
        return 0;
    }
    map < int, int > t;
    t[0] = 0;
    t[1] = 0;
    t[2] = 0;
    if (l % 3 == 1){
        for (int i = l; i <= min(r, l + 1); ++i) t[i % 3]++;
        l = min(r, l + 1) + 1;
    }
    else if (l % 3 == 2){
        for (int i = l; i <= min(r, l); ++i) t[i % 3]++;
        l = min(r, l) + 1;
    }
    t[0] += (r - l + 3) / 3;
    t[1] += (r - l + 2) / 3;
    t[2] += (r - l + 1) / 3;
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i){
        dp[i][0] = (dp[i - 1][0] * t[0]) % mod + (dp[i - 1][1] * t[2]) % mod + (dp[i - 1][2] * t[1]) % mod;
        dp[i][1] = (dp[i - 1][0] * t[1]) % mod + (dp[i - 1][1] * t[0]) % mod + (t[2] * dp[i - 1][2]) % mod;
        dp[i][2] = (dp[i - 1][0] * t[2]) % mod + (dp[i - 1][1] * t[1]) % mod + (dp[i - 1][2] * t[0]) % mod;
        for (int j = 0; j <= 2; ++j) dp[i][j] %= mod;
    }
    cout << dp[n][0] << endl;
    return 0;
}