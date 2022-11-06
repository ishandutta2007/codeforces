#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

int main(int argc, char** argv) {
#ifdef VSE
    if (argc > 1) freopen(argv[1], "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(3);
    a[0] = r / 3 - (l - 1) / 3;
    a[1] = (r + 1) / 3 - l / 3;
    a[2] = (r + 2) / 3 - (l + 1) / 3;

    vector<vector<int>> d(3, vector<int>(n + 1));
    d[0][0] = 1;

    const int M = int(1e9) + 7;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                d[(k + j) % 3][i + 1] = (d[(j + k) % 3][i + 1] + 1LL * d[j][i] * a[k]) % M;
            }
        }
    }

    cout << d[0][n] << "\n";

    return 0;
}