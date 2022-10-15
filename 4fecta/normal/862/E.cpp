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

int n, m, q, po[MN], pe[MN], a[MN], b[MN], l, r, x, co, ce;
set<int> vals;

int solve(int sum) {
    auto it = vals.lower_bound(sum);
    if (it == vals.end()) it--;
    int ans = abs(*it - sum);
    if (it != vals.begin()) it--;
    ans = min(ans, abs(*it - sum));
    return ans;
}

int32_t main() {
    boost();

    cin >> n >> m >> q;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i & 1) sum += a[i];
        else sum -= a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        if (i & 1) po[i] += b[i];
        else pe[i] += b[i];
        po[i] += po[i - 1];
        pe[i] += pe[i - 1];
    }
    for (int i = n; i <= m; i++) {
        int l = i - n + 1;
        if (l & 1) vals.insert(pe[i] - pe[l - 1] - po[i] + po[l - 1]);
        else vals.insert(po[i] - po[l - 1] - pe[i] + pe[l - 1]);
    }
    int ans = solve(-sum);
    printf("%lld\n", ans);
    while (q--) {
        cin >> l >> r >> x;
        if (l % 2 == r % 2) co = (r - l + 1) / 2 + l % 2, ce = (r - l + 1) - co;
        else co = ce = (r - l + 1) / 2;
        sum = sum + co * x - ce * x;
        ans = solve(-sum);
        printf("%lld\n", ans);
    }

    return 0;
}