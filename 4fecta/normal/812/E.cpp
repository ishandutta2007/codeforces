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

const int MN = 100005;

int n, val[MN], u, depth[MN], xorsum = 0, par[MN], good, bad, mx, freq[20000005], bcnt;
ll ans = 0;

int32_t main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 2; i <= n; i++) cin >> par[i], depth[i] = depth[par[i]] + 1, mx = max(mx, depth[i]);
    good = mx & 1, bad = !good;
    for (int i = 1; i <= n; i++) {
        if (depth[i] % 2 == good) xorsum ^= val[i];
        else freq[val[i]]++, bcnt++;
    }
    if (!xorsum) ans += bcnt * (bcnt - 1) / 2, ans += (n - bcnt) * (n - bcnt - 1) / 2;
    for (int i = 1; i <= n; i++) {
        if (depth[i] % 2 == bad) continue;
        ans += freq[xorsum ^ val[i]];
    }
    printf("%lld\n", ans);

    return 0;
}