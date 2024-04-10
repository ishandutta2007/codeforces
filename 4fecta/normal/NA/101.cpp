// Problem: C. Moamen and XOR
// Contest: Codeforces - Codeforces Round #737 (Div. 2)
// URL: https://codeforces.com/contest/1557/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 200005, MOD = 1e9 + 7;

int fpow(int b, int p) {
    if (!p) return 1;
    int ret = fpow(b, p / 2);
    if (p & 1) return ret * ret % MOD * b % MOD;
    else return ret * ret % MOD;
}

int t, n, k, fact[MN], inv[MN];

int c(int n, int k) {
    return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int32_t main() {
    boost();

    fact[0] = inv[0] = 1;
    for (int i = 1; i < MN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = fpow(fact[i], MOD - 2);
    }
    cin >> t;
    while (t--) {
        cin >> n >> k;
        if (n & 1) {
            int ans = 0;
            for (int i = 0; i <= k; i++) {
                int ways = fpow(2, n - 1);
                ans += c(k, i) * fpow(ways, k - i) % MOD;
                ans %= MOD;
            }
            ans %= MOD, ans += MOD, ans %= MOD;
            printf("%lld\n", ans);
        } else {
            int ans = 0;
            for (int i = 0; i <= k; i++) {
                int digs = k - i;
                int free = max(0ll, i - 1);
                int fways = fpow(2, n);
                int ways = fpow(2, n - 1) - 1;
                ans += fpow(ways, digs) * fpow(fways, free) % MOD;
                ans %= MOD;
            }
            ans %= MOD, ans += MOD, ans %= MOD;
            printf("%lld\n", ans);
        }
    }

    return 0;
}