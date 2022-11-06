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

    int q;
    cin >> q;
    for (int iq = 0; iq < q; iq++) {
        llong n, m, k;
        cin >> n >> m >> k;
        llong d = max(m, n);
        if (d > k) {
            cout << "-1\n";
            continue;
        }
        if ((m + n) % 2 == 0) {
            if ((d + k) % 2 == 0) {
                cout << k;
            } else {
                cout << k - 2;
            }
        } else {
            cout << k - 1;
        }
        cout << "\n";
    }

    return 0;
}