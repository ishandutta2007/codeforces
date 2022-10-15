#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 4050, MOD = 998244353;

int n, m, fact[MN], inv[MN], ans;

int fpow(int b, int p) {
    if (!p) return 1;
    int ret = fpow(b, p / 2);
    if (p & 1) return ret * ret % MOD * b % MOD;
    else return ret * ret % MOD;
}

int ch(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int paths(int x, int y) {
    return ch(x + y, x);
}

int solve(int n, int m, int f) {
    int ret = 0;
    for (int i = 1; i < n; i++) {
        int tmp = 0;
        for (int j = m - 1; j > 0; j--) {
            if (!f) {
                tmp += paths(i - 1, j) * paths(i, m - j - 1);
                tmp %= MOD;
            }
            ret += tmp * paths(n - i, j - 1) % MOD * paths(n - i - 1, m - j) % MOD;
            ret %= MOD;
            if (f) {
                tmp += paths(i - 1, j) * paths(i, m - j - 1);
                tmp %= MOD;
            }
        }
    }
    return ret;
}

int32_t main() {
    boost();

    cin >> n >> m;
    fact[0] = inv[0] = 1;
    for (int i = 1; i < MN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = fpow(fact[i], MOD - 2);
    }
    ans += solve(n, m, 0) + solve(m, n, 1);
    printf("%lld\n", ans * 2 % MOD);

    return 0;
}