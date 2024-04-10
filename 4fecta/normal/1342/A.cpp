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

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        int ans = a * abs(x - y);
        int d = min(abs(x), abs(y));
        if ((x <= 0 && y >= 0) || (x >= 0 && y <= 0)) {
            d = 0;
        }
        if (a * 2 >= b) ans += d * b;
        else ans = (x + y) * a;
        printf("%lld\n", ans);
    }

    return 0;
}