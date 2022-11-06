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

    int n, m;
    cin >> n >> m;
    n += m;
    vector<int> x(n);
    for (auto& i : x) {
        cin >> i;
    }

    vector<int> t(n);
    for (auto& i : t) {
        cin >> i;
    }

    int l = -1, r = 0;
    while (r < n && t[r] == 0) {
        r++;
    }

    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        if (t[i] == 1) {
            l = i;
            r = i + 1;
            while (r < n && t[r] == 0) {
                r++;
            }
        } else {
            int d = 1e9;
            int t = -1;
            if (l != -1) {
                d = x[i] - x[l];
                t = l;
            }
            if (r < n) {
                if (x[r] - x[i] < d) {
                    d = x[r] - x[i];
                    t = r;
                }
            }
            ans[t]++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (t[i]) {
            cout << ans[i] << " ";
        }
    }

    return 0;
}//kecpca