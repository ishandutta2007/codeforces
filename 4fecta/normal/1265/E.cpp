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

const int MN = 200005, MOD = 998244353;

int fpow(int b, int p) {
    if (!p) return 1;
    int ret = fpow(b, p / 2);
    if (p & 1) return ret * ret % MOD * b % MOD;
    return ret * ret % MOD;
}

int n, a[MN], dp[MN];

int32_t main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    dp[0] = 1;
    int num = 1, den = 0;
    for (int i = 1; i <= n; i++) {
        int p = a[i] * fpow(100, MOD - 2) % MOD;
        dp[i] = dp[i - 1] * p % MOD;
        if (i < n) num += dp[i], num %= MOD;
        else den += dp[i], den %= MOD;
    }
    int ans = num * fpow(den, MOD - 2) % MOD;
    printf("%lld\n", ans % MOD);

    return 0;
}