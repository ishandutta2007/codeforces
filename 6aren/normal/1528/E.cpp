#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 1000005;

int64_t dp[2][N], pdp[N];

int64_t C2(int64_t x) { return x * (x - 1) / 2 % MOD; }

int64_t C3(int64_t x) {
    bool d2 = false, d3 = false;
    int64_t res = 1;
    for (int64_t i = x - 2; i <= x; i++) {
        int foo = i;
        if (!d2 && foo % 2 == 0) {
            d2 = true;
            foo = foo / 2;
        }
        if (!d3 && foo % 3 == 0) {
            d3 = true;
            foo = foo / 3;
        }
        res = res * foo % MOD;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    if (n == 1) return cout << 5 << '\n', 0;

    dp[0][0] = pdp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[0][i] = (dp[0][i - 1] + dp[0][i - 1] * (dp[0][i - 1] + 1) / 2) % MOD;
        if (i > 1) dp[0][i] = (dp[0][i] + dp[0][i - 1] * pdp[i - 2]) % MOD;
        pdp[i] = (pdp[i - 1] + dp[0][i]) % MOD;
        dp[1][i] = (dp[0][i] - dp[0][i - 1] + MOD) % MOD;
    }
    int64_t res =
        2 * (dp[0][n] + dp[0][n - 1] * C2(pdp[n - 2] + 1) +
             pdp[n - 2] * C2(dp[0][n - 1] + 1) + C3(dp[0][n - 1] + 2)) - 1;
    res = (res + MOD) % MOD;

    for (int i = 1; i < n; i++) {
        res = (res + (dp[0][n - i - 1] - 1) * dp[1][i]) % MOD;        
    }

    cout << res << '\n';

    return 0;
}