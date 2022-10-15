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

int n, m, a, b[MN], ans = 1;

int32_t main() {
    boost();

    cin >> n >> m >> a;
    for (int i = 1; i <= m; i++) cin >> b[i];
    int mid = n - 2 * b[m];
    ans *= fpow(a, mid); ans %= MOD;
    for (int i = 1; i <= m; i++) {
        int len = b[i] - b[i - 1];
        ans *= ((fpow(a, len) + fpow(a, 2 * len)) % MOD) % MOD * fpow(2, MOD - 2) % MOD;
        ans %= MOD;
    }
    ans %= MOD; ans += MOD; ans %= MOD;
    printf("%lld\n", ans);

    return 0;
}