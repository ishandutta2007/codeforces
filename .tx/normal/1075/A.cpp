#ifdef VSE
#define _GLIBCXX_DEBUG
#endif
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

    llong n, x, y;
    cin >> n >> x >> y;
    llong d1 = max(x, y) - 1;
    llong d2 = max(n - x, n - y);
    if (d1 <= d2) {
        cout << "White";
    } else {
        cout << "Black";
    }

    return 0;
}//cuulyh