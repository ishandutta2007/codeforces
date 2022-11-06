#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, h;
    cin >> n >> h;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }

    int ans = 0;
    int i1 = 0;
    int i2 = 0;
    int ch = h;
    int cans = r[0] - l[0];
    while (i1 < n) {
        while (i2 + 1 < n && l[i2 + 1] - r[i2] < ch) {
            ch -= l[i2 + 1] - r[i2];
            cans += r[i2 + 1] - r[i2];
            i2++;
        }
        ans = max(ans, cans + ch);
        if (i1 == i2) {
            i1++;
            i2++;
            cans = i1 == n ? 0 : r[i1] - l[i1];
            ch = h;
        } else {
            cans -= l[i1 + 1] - l[i1];
            ch += l[i1 + 1] - r[i1];
            i1++;
        }
    }

    cout << ans;

    return 0;
}