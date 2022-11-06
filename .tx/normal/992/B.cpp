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

    llong l, r, x ,y;
    cin >> l >> r >> x >> y;
    set<int> ds;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            ds.insert(i);
            ds.insert(x / i);
        }
    }
    for (int i = 1; i * i <= y; i++) {
        if (y % i == 0) {
            ds.insert(i);
            ds.insert(y / i);
        }
    }

    set<pair<llong, llong>> ans;
    for (int i : ds) {
        llong a = i;
        llong b = 1LL * x * y / a;
        if (l <= a && a <= r && l <= b && b <= r && __gcd(a, b) == x) {
            ans.insert({a, b});
            ans.insert({b, a});
        }
    }

    cout << ans.size();


    return 0;
}