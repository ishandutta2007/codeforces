#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 1e9 + 1;
const int MAXN = 2e6 + 5;
const int mod = 1e9 + 7;

ll lol(int a, int b) {
    if (a >= b) return a - b;
    return a + mod - b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<ll>> dp(MAXN, vector<ll>(2));
    dp[1][0] = dp[1][1] = 0;
    dp[2][0] = dp[2][1] = 0;
    for (int i = 3; i < MAXN; i++) {
        dp[i][0] = (2 * dp[i - 2][1] + dp[i - 1][1]) % mod;
        ll kek = 2 * lol(dp[i - 2][1], dp[i - 2][0]) + lol(dp[i - 1][1], dp[i - 1][0]);
        if (kek >= 4) dp[i][1] = dp[i][0];
        else dp[i][1] = (dp[i][0] + 4 - kek) % mod;
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n][1] << "\n";
    }
    return 0;
}