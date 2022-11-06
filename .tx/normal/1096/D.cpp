#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

llong d[111111][5];

int main(int argc, char** argv) {
#ifdef VSE
    if (argc > 1) freopen(argv[1], "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    string s;
    cin >> n >> s;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 4; j++) {
            d[i][j] = 1e18;
        }
    }

    string al = "hard";

    d[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            if (s[i] != al[j]) {
                d[i + 1][j] = min(d[i + 1][j], d[i][j]);
            } else {
                d[i + 1][j] = min(d[i + 1][j], d[i][j] + a[i]);
                d[i + 1][j + 1] = min(d[i + 1][j + 1], d[i][j]);
            }
        }
    }

//    for (int i = 0; i <= n; i++) {
//        for (int j = 0; j < 4; j++) {
//            if (d[i][j] == 1e18) {
//                cout << "-";
//            } else {
//                cout << d[i][j];
//            }
//            cout << " ";
//        }
//        cout << "\n";
//    }

    llong ans = 1e18;
    for (int i = 0; i < 4; i++) {
        ans = min(ans, d[n][i]);
    }

    cout << ans << "\n";

    return 0;
}//ewgnih