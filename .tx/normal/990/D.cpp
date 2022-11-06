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

    int n, a, b;
    cin >> n >> a >> b;
    if (a > 1 && b > 1) {
        cout << "NO\n";
        return 0;
    }
    int x = max(a, b);
    if (x == 1 && (n == 2 || n == 3)) {
        cout << "NO\n";
        return 0;
    }
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = x - 1; i + 1 < n; i++) {
        g[i][i + 1] = g[i + 1][i] = 1;
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                cout << 0;
                continue;
            }
            if (x == a) {
                cout << g[i][j];
            } else {
                cout << 1 - g[i][j];
            }
        }
        cout << "\n";
    }

    return 0;
}