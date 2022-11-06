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

    int n, q;
    cin >> n >> q;
    map<int, int> tn;
    for (int i = 0; i <= 30; i++) {
        tn[1 << i] = i;
    }

    vector<int> c(31);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        c[tn[x]]++;
    }

    for (int iq = 0; iq < q; iq++) {
        int x;
        cin >> x;
        int ans = 0;
        for (int i = 30; i >= 0; i--) {
            int t = min(c[i], x / (1 << i));
            ans += t;
            x -= t * (1 << i);
        }
        if (x == 0) {
            cout << ans;
        } else {
            cout << -1;
        }
        cout << "\n";
    }

    return 0;
}