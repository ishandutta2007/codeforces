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

    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    vector<string> b(n, string(m, '.'));

    auto star = [&](int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m) {
            return false;
        }
        return a[i][j] == '*';
    };

    vector<array<int, 3>> ans;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int p = 0;
            while (true) {
                if (star(i - p, j) && star(i + p, j) && star(i, j - p) && star(i, j + p)) {
                    p++;
                } else {
                    break;
                }
            }
            if (p > 1) {
                ans.push_back({i, j, p - 1});
                for (int k = 0; k < p; k++) {
                    b[i - k][j] = b[i + k][j] = b[i][j - k] = b[i][j + k] = '*';
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            cout << -1;
            return 0;
        }
    }

    cout << isz(ans) << "\n";
    for (auto& i : ans) {
        cout << i[0] + 1 << " " << i[1] + 1 << " " << i[2] << "\n";
    }

    return 0;
}//cmjrgv