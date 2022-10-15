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

const int MN = 300005;

int n, hit[MN];
pii a[MN];

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].f >> a[i].s;
            hit[i] = max(0ll, a[i].f - a[i - 1].s);
        }
        if (n == 1) {
            printf("%lld\n", a[1].f);
            continue;
        }
        hit[1] = max(0ll, a[1].f - a[n].s);
        int sum = 0;
        for (int i = 1; i <= n; i++) sum += hit[i];
        int ans = 1LL << 60;
        for (int i = 1; i <= n; i++) ans = min(ans, sum - hit[i] + a[i].f);
        printf("%lld\n", ans);
    }

    return 0;
}