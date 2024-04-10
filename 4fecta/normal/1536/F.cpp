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
    else return ret * ret % MOD;
}

int n, dp[MN], fact[MN], inv[MN];

int c(int n, int k) {
    assert(0 <= k && k <= n);
    return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int32_t main() {
    boost();

    fact[0] = inv[0] = 1;
    for (int i = 1; i < MN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = fpow(fact[i], MOD - 2);
    }
    cin >> n;
    int ans = 0;
    for (int i = n % 2; i <= n / 2; i += 2) ans += c(n - i, i) * fact[n - i - 1], ans %= MOD;
    printf("%lld\n", ans * n * 2 % MOD);

    return 0;
}