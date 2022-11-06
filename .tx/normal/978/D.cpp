#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

int main() {
#ifdef G13
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int ans = 1e9;
    int n;
    cin >> n;
    if (n <= 2) {
        cout << 0;
        return 0;
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int d0 = -1; d0 <= 1; d0++) {
        for (int d1 = -1; d1 <= 1; d1++) {
            llong d = (a[1] + d1) - (a[0] + d0);
            llong c = a[1] + d1 + d;
            bool ok = true;
            int ca = abs(d0) + abs(d1);
            for (int i = 2; i < n; i++) {
                if (abs(c - a[i]) > 1) {
                    ok = false;
                    break;
                }
                ca += abs(c - a[i]);
                c += d;
            }
            if (ok) {
                ans = min(ans, ca);
            }
        }
    }

    if (ans == 1e9) {
        ans = -1;
    }
    cout << ans;

    return 0;
}