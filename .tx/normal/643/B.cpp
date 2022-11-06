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

    int n, k;
    cin >> n >> k;
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (n < 5 || k < n + 1) {
        cout << -1;
        return 0;
    }

    cout << a << " " << c;
    for (int i = 1; i <= n; i++) {
        if (i != a && i != b && i != c && i != d) {
            cout << " " << i;
        }
    }

    cout << " " << d << " " << b << "\n";
    cout << c << " " << a;
    for (int i = 1; i <= n; i++) {
        if (i != a && i != b && i != c && i != d) {
            cout << " " << i;
        }
    }
    cout << " " << b << " " << d << "\n";

    return 0;
}//kubpdc