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

    int n, m;
    cin >> n >> m;
    llong s = 0;
    for (int i = 0; i < m; i++) {
        int x, d;
        cin >> x >> d;
        s += 1LL * x * n;
        if (d > 0) {
            s += 1LL * d * n * (n - 1) / 2;
        } else {
            int t = (n + 1) / 2;
            s += 1LL * d * t * (t - 1) / 2;
            t = n - t + 1;
            s += 1LL * d * t * (t - 1) / 2;
        }
    }

    cout << setprecision(11) << fixed << 1.0 * s / n;

    return 0;
}