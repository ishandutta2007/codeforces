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
        int m, k;
        cin >> m >> k;

        vector<int> a(k);
        for (auto& i : a) {
            cin >> i;
        }
        vector<int> p(k);
        iota(begin(p), end(p), 0);
        vector<int> was(k);
        vector<int> wa;
        int c = -1;

        int fr = 0;
        int wfr = -1;
        for (int i = 0; i + 1 < m; i++) {
            int t, r;
            cin >> t >> r;
            --t;
            if (r == 1 && c == -1) {
                c = 0;
                wfr = fr;
                wa = a;
                sort(begin(p), end(p), [&](int i, int j) {
                    return a[i] < a[j];
                });
            }
            if (c != -1 && t != -1) {
                was[t] = 1;
            }
            while (c != -1 && was[p[c]]) {
                c++;
            }
            if (t == -1) {
                fr++;
            } else {
                a[t]--;
            }
        }


        for (int i = 0; i < k; i++) {
            if (c != -1 && (!was[i] && wa[i] <= wfr || a[i] <= fr - wa[p[c]])) {
                cout << "Y";
            } else if (c == -1 && a[i] <= fr) {
                cout << "Y";
            } else {
                cout << "N";
            }
        }

        cout << "\n";

    }

    return 0;
}