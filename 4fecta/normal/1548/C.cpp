#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 1000005, MOD = 1e9 + 7;

int fpow(int b, int p) {
    if (!p) return 1;
    int ret = fpow(b, p / 2);
    if (p & 1) return ret * ret % MOD * b % MOD;
    return ret * ret % MOD;
}

int n, q, x[MN], fact[MN * 3], inv[MN * 3], dp[MN * 3][2];

int c(int n, int k) {
    if (n < 0 || k < 0 || k > n) return 0;
    return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int32_t main() {
    boost();

    fact[0] = inv[0] = 1;
    for (int i = 1; i < MN * 3; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = fpow(fact[i], MOD - 2);
    }
    cin >> n >> q;
    dp[0][0] = dp[0][1] = n;
    int d3 = fpow(3, MOD - 2);
    for (int i = 1; i <= n * 3; i++) {
        dp[i][0] = c(n * 3, i + 1) - 2 * dp[i - 1][0] - dp[i - 1][1];
        dp[i][0] = dp[i][0] % MOD * d3 % MOD;
        dp[i][0] %= MOD, dp[i][0] += MOD, dp[i][0] %= MOD;
        dp[i][1] = (dp[i][0] + dp[i - 1][0]) % MOD;
    }
    for (int i = 1; i <= q; i++) {
        cin >> x[i];
        int ans = dp[x[i]][0] + c(n * 3, x[i]);
        printf("%lld\n", ans % MOD);
    }

    return 0;
}