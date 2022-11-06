#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto csz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    for (int it = 0; it < t; it++) {
        int n, x, y ,d;
        cin >> n >> x >> y >> d;
        --x; --y;
        if (abs(x - y) % d == 0) {
            cout << abs(x - y) / d << "\n";
            continue;
        }
        int ans = int(2e9) + 1e8;
        if (y % d == 0) {
            ans = min(ans, (x + d - 1) / d + y / d);
        }
        if (abs(n - 1 - y) % d == 0) {
            ans = min(ans, (n - 1 - x + d - 1) / d + abs(n - 1 - y) / d);
        }
        if (ans > 2e9) {
            cout << "-1\n";
        } else {
            cout << ans << "\n";
        }
    }

    return 0;
}//arrqrl