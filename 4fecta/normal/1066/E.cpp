#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define int ll
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 200005, MOD = 998244353;

int n, m, a[MN], b[MN];
ll pow2[MN];
char c;

int32_t main() {
    boost();

    pow2[0] = 1;
    for (int i = 1; i < MN; i++) {
        pow2[i] = pow2[i - 1] * 2;
        pow2[i] %= MOD;
    }
    cin >> n >> m;
    if (n < m) {
        for (int i = m - n; i < m; i++) cin >> c, a[i] = c - '0';
        for (int i = 0; i < m; i++) cin >> c, b[i] = c - '0';
    } else {
        for (int i = 0; i < n; i++) cin >> c, a[i] = c - '0';
        for (int i = n - m; i < n; i++) cin >> c, b[i] = c - '0';
    }
    if (m > n) swap(n, m);
    ll ans = 0;
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += b[i];
        if (a[i]) ans += cnt * pow2[n - i - 1], ans %= MOD;
    }

    printf("%lld\n", ans % MOD);

    return 0;
}