#pragma GCC optmize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, l, r;
    const int MOD = 1e9 + 7;
    cin >> n >> l >> r;
    vector <vector <int>> dp(n + 1, vector <int> (3));
    while (r % 3 != l % 3) {
        dp[1][r % 3]++;
        r--;
    }
    dp[1][r % 3]++;
    dp[1][0] += (r - l) / 3;
    dp[1][1] += (r - l) / 3;
    dp[1][2] += (r - l) / 3;
    forn (i, 2, n + 1) {
        dp[i][0] = ((1LL * dp[i - 1][0] * dp[1][0]) % MOD +
                    (1LL * dp[i - 1][1] * dp[1][2]) % MOD +
                    (1LL * dp[i - 1][2] * dp[1][1]) % MOD) % MOD;
        dp[i][1] = ((1LL * dp[i - 1][0] * dp[1][1]) % MOD +
                    (1LL * dp[i - 1][1] * dp[1][0]) % MOD +
                    (1LL * dp[i - 1][2] * dp[1][2]) % MOD) % MOD;
        dp[i][2] = ((1LL * dp[i - 1][0] * dp[1][2]) % MOD +
                    (1LL * dp[i - 1][1] * dp[1][1]) % MOD +
                    (1LL * dp[i - 1][2] * dp[1][0]) % MOD) % MOD;
    }
    cout << dp[n][0];
    return 0;
}