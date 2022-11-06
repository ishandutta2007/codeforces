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

    int n, m, l;
    cin >> n >> m >> l;
    vector<llong> a(n);
    for (auto& i : a) {
        cin >> i;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > l && (i == 0 || a[i - 1] <= l)) {
            ans++;
        }
    }

    for (int im = 0; im < m; im++) {
        int t;
        cin >> t;
        if (t == 0) {
            cout << ans << "\n";
        } else {
            int p, d;
            cin >> p >> d;
            --p;
            llong& x = a[p];
            x += d;
            if (x > l && x - d <= l) {
                bool ll = p == 0 || a[p - 1] <= l;
                bool rr = p == n - 1 || a[p + 1] <= l;
                if (ll && rr) {
                    ans++;
                } else if (!ll && !rr) {
                    ans--;
                }
            }
        }
    }

    return 0;
}//mvvrfj