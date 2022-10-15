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

const int MN = 100005, LOG = 19;

int n, q, a[MN], l, r;
pii st[MN][LOG];

pii qry(int l, int r) {
    int lvl = 31 - __builtin_clz(r - l + 1);
    return max(st[l][lvl], st[r - (1 << lvl) + 1][lvl]);
}

int f(int l, int r) {
    if (l > r) return 0;
    pii tmp = qry(l, r);
    return (tmp.s - l + 1) * (r - tmp.s + 1) * tmp.f + f(l, tmp.s - 1) + f(tmp.s + 1, r);
}

int32_t main() {
    boost();

    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) st[i][0] = {abs(a[i] - a[i + 1]), i};
    for (int s = 1; s < LOG; s++) for (int i = 1; i + (1 << s) <= n; i++) st[i][s] = max(st[i][s - 1], st[i + (1 << (s - 1))][s - 1]);
    while (q--) {
        cin >> l >> r;
        printf("%lld\n", f(l, r - 1));
    }

    return 0;
}