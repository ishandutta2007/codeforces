#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 200005, MOD = 1e9 + 7;

int fpow(int b, int p) {
    if (!p) return 1;
    int ret = fpow(b, p / 2);
    if (p % 2) return ret * ret % MOD * b % MOD;
    return ret * ret % MOD;
}

int n, m, h, fact[MN], inv[MN], tot, want;

int choose(int n, int k) { //n objects, k stacks, any amount
    if (n == 0 && k == 0) return 1;
    if (n < 0 || k <= 0) return 0;
    return fact[n + k - 1] * inv[n] % MOD * inv[k - 1] % MOD;
}

int32_t main() {
    boost();

    fact[0] = inv[0] = 1;
    for (int i = 1; i < MN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = fpow(fact[i], MOD - 2) % MOD;
    }
    cin >> n >> m >> h;
    for (int i = 1; i <= n + m; i++) {
        int x = i / 2, y = i - x;
        tot += choose(n - x, x) * choose(m - y, y); tot %= MOD;
        tot += choose(n - y, y) * choose(m - x, x); tot %= MOD;
        want += choose(n - x, x) * choose(m - y * (h + 1), y); want %= MOD;
        want += choose(n - y, y) * choose(m - x * (h + 1), x); want %= MOD;
    }
    printf("%lld\n", want * fpow(tot, MOD - 2) % MOD);

    return 0;
}