#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    llong n;
    int q;
    cin >> n >> q;
    for (int iq = 0; iq < q; iq++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        if ((x + y) % 2 == 0) {
            llong ans = (x / 2) * n;
            if (x & 1) {
                ans += (n + 1) / 2;
            }
            ans += y / 2;
            cout << ans + 1 << "\n";
        } else {
            llong ans = (n * n + 1) / 2;
            ans += (x / 2) * n;
            if (x & 1) {
                ans += n / 2;
            }
            ans += y / 2;
            cout << ans + 1 << "\n";
        }
    }

    return 0;
}//bfyuyy