#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto sz = [](const auto& c) { return int(c.size());};

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
        int d;
        cin >> d;
        if (d == 0) {
            cout << "Y 0 0\n";
            continue;
        }
        if (d < 4) {
            cout << "N\n";
            continue;
        }
        double a = 0.5 * (d - sqrt(1.0 * d * (d - 4)));
        double b = d - a;
        cout << setprecision(11) << fixed << "Y " << a << " " << b << "\n";
    }

    return 0;
}//opasow