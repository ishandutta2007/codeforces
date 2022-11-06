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

    vector<int> a(1 << k);
    for (int i = 0; i < n; i++) {
        int x = 0;
        for (int j = 0; j < k; j++) {
            int y;
            cin >> y;
            x = (x << 1) | y;
        }
        a[x] = 1;
    }

    for (int i = 0; i < sz(a); i++) {
        if (a[i]) {
            for (int j = 0; j < k; j++) {
                if (((i >> j) & 1) == 0) {
                    a[i ^ (1 << j)] = 1;
                }
            }
        }
    }

    for (int i = 0; i < sz(a); i++) {
        int j = i ^ ((1 << k) - 1);
        if (a[i] && a[j]) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}//khzsaa