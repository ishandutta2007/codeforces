#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

const double PI = acos(-1.0);

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    double n, r;
    cin >> n >> r;

    double ll = 0, rr = 1e15;

    for (int it = 0; it < 1111; it++) {
        double mm = (ll + rr) / 2;
        double x = 2 * mm * 2 * mm;
        double y = 2 * (r + mm) * (r + mm) * (1 - cos(2 * PI / n));
        if (x > y) {
            rr = mm;
        } else {
            ll = mm;
        }
    }

    cout << fixed << setprecision(11) << ll << "\n";//

    return 0;
}//hidqxy