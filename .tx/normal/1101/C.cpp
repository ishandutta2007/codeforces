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

    int t;
    cin >> t;
    for (int it = 0; it < t; it++) {
        int n;
        cin >> n;
        vector<pair<int, int>> p(2 * n);
        for (int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            p[i * 2] = {l, -i - 1};
            p[i * 2 + 1] = {r, i + 1};
        }
        sort(begin(p), end(p));
        vector<int> ans(n);
        int c = 0;
        for (auto [x, i] : p) {
            if (i > 0) {
                c--;
            } else {
                c++;
            }

            ans[abs(i) - 1] = 1;
            if (c == 0) {
                break;
            }
        }
        if (find(begin(ans), end(ans), 0) == end(ans)) {
            cout << "-1\n";
        } else {
            for (int i : ans) {
                cout << i + 1 << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}//wxbjrb