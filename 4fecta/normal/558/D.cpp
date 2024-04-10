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

int h, q, id, l, r, t, x, y, ans;

int32_t main() {
    boost();

    cin >> h >> q;
    l = 1LL << (h - 1), r = 1LL << h;
    vector<pii> v;
    for (int i = 1; i <= q; i++) {
        cin >> id >> x >> y >> t;
        x <<= (h - id);
        y = (y + 1) << (h - id);
        //printf("%d %d\n", x, y);
        if (t == 1) l = max(l, x), r = min(r, y);
        else v.push_back({x, y});
    }
    v.push_back({r, r});
    sort(v.begin(), v.end());
    for (pii p : v) {
        if (r <= l) break;
        //printf("%lld %lld\n", p.f, p.s);
        if (l < p.f) {
            if (ans || l + 1 < p.f) return 0 * printf("Data not sufficient!\n");
            ans = l;
        }
        l = max(l, p.s);
    }
    if (ans) printf("%lld\n", ans);
    else printf("Game cheated!\n");

    return 0;
}