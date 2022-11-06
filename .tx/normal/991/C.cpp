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

    llong n;
    cin >> n;
    llong l = 0, r = n;
    while (l + 1 < r) {
        llong m = (l + r) >> 1;
        llong x = n;
        llong c = 0;
        while (x) {
            c += min(m, x);
            x = max(0LL, x - m);
            x -= x / 10;
        }
        if (c * 2 >= n) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r;

    return 0;
}