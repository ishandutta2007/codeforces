#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

llong get(llong n, llong x, bool f) {
    if (f) {
        if (x % 2 == 0) {
            return x / 2;
        }
        if (n % 2 == 1) {
            return (n + 1) / 2 + get(n / 2, x / 2, false);
        }
        return n / 2 + get(n / 2, x / 2, true);
    } else {
        if (x % 2 == 1) {
            return x / 2;
        }
        if (n % 2 == 0) {
            return n / 2 + get(n / 2, x / 2, false);
        }
        return n / 2 + get((n + 1) / 2, x / 2, true);
    }
}

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    llong n, q;
    cin >> n >> q;
    for (int iq = 0; iq < q; iq++) {
        llong x;
        cin >> x;
        cout << get(n, x - 1, true) + 1 << "\n";
    }

    return 0;
}