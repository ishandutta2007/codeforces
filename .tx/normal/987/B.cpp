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

    int x, y;
    cin >> x >> y;
    if (x == y || x == 2 && y == 4 || x == 4 && y == 2) {
        cout << "=";
        return 0;
    }

    long double xd = x;
    long double yd = y;

    long double l1 = yd * log(xd);
    long double l2 = xd * log(yd);

    if (l1 < l2) {
        cout << "<";
    } else if (l2 < l1) {
        cout << ">";
    } else {
        cout << "=";
    }

    return 0;
}