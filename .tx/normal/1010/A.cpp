#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

#define min(a, b) std::min<decltype((a) < (b) ? (a) : (b))>(a, b)
#define max(a, b) std::max<decltype(!((a) < (b)) ? (a) : (b))>(a, b)
template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) {
            cout << -1;
            return 0;
        }
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (b[i] == 1) {
            cout << -1;
            return 0;
        }
    }
    a.push_back(a.front());
    b.push_back(b.front());
    n++;

    double l = 0, r = 1e9;
    for (int it = 0; it < 1000; it++) {
        double m = (l + r) / 2;
        for (int i = 0; i < n; i++) {
            if (i) {
                m -= (abs(m) + x) / b[i];
            }
            if (i + 1 < n) {
                m -= (abs(m) + x) / a[i];
            }
        }
        if (m < 0) {
            l = (l + r) / 2;
        } else {
            r = (l + r) / 2;
        }
    }

    cout << setprecision(11) << fixed << l;

    return 0;
}