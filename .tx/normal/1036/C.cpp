#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
using ull = uint64_t;

//llong go(ull r, ull cur, int c) {
//    if (cur > r || c > 3) {
//        return 0;
//    }
//    llong res = 1 + (cur == 0 ? 0 : go(r, cur * 10, c));
//    for (ull i = 1; i <= 9; i++) {
//        res += go(r, cur * 10ull + i, c + 1);
//    }
//    return res;
//}

llong d[22][5][2];

llong get(string r) {
    memset(d, 0, sizeof(llong) * 22 * 5 * 2);
    d[0][0][0] = 1;
    for (int i = 1; i <= r.size(); i++) {
        for (int j = 0; j <= 3; j++) {
            d[i][j][1] += d[i - 1][j][1];
            d[i][j + 1][1] += 9 * d[i - 1][j][1];
            for (int k = 0; k + '0' < r[i - 1]; k++) {
                d[i][j + (k == 0 ? 0 : 1)][1] += d[i - 1][j][0];
            }
            d[i][j + (r[i - 1] == '0' ? 0 : 1)][0] += d[i - 1][j][0];
        }
    }
    llong res = 0;
    for (int i = 0; i <= 3; i++) {
        res += d[r.size()][i][0] + d[r.size()][i][1];
    }

    return res;
}

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    map<llong, llong> m;
    for (int it = 0; it < t; it++) {
        llong l, r;
        cin >> l >> r;
        llong ar = get(to_string(r));
        llong al = get(to_string(l - 1));
        cout << ar - al << "\n";
    }

    return 0;
}//ezlbvc