#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

//#define min(a, b) std::min<decltype((a) < (b) ? (a) : (b))>(a, b)
//#define max(a, b) std::max<decltype(!((a) < (b)) ? (a) : (b))>(a, b)
template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

bool d[55][55];

int main() {
#ifdef G13
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<llong> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    llong ans = 0;
    for (int b = 60; b >= 0; b--) {
        memset(d, false, sizeof(bool) * 55 * 55);
        llong s = 0;
        ans |= (1LL << b);
        for (int i = 1; i <= n; i++) {
            s += a[i - 1];
            d[1][i] = (s & ans) == ans;
        }

        for (int i = 2; i <= k; i++) {
            for (int j = 1; j <= n; j++) {
                s = 0;
                for (int t = 1; t <= j; t++) {
                    s += a[j - t];
                    d[i][j] |= d[i - 1][j - t] && ((s & ans) == ans);
                }
            }
        }

        if (!d[k][n]) {
            ans ^= 1LL << b;
        }
    }

    cout << ans;

    return 0;
}