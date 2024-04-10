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

int n, a, r, m, h[MN];

int check(int lvl) {
    int ab = 0, be = 0;
    for (int i = 1; i <= n; i++) {
        if (h[i] < lvl) be += lvl - h[i];
        else ab += h[i] - lvl;
    }
    int ret = min(ab, be) * m;
    if (ab > be) return ret + (ab - be) * r;
    else return ret + (be - ab) * a;
}

int32_t main() {
    boost();

    cin >> n >> a >> r >> m;
    for (int i = 1; i <= n; i++) cin >> h[i];
    sort(h + 1, h + n + 1);
    m = min(m, a + r);
    int lo = 0, hi = 1e9, mid;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        int p1 = check(mid), p2 = check(mid + 1);
        if (p1 <= p2) hi = mid;
        else lo = mid + 1;
    }
    printf("%lld\n", check(lo));

    return 0;
}