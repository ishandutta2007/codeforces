#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

int d[111][2];

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x == 1) {
            d[i][1] = max(d[i - 1][0], d[i - 1][1]) + 1;
            d[i][0] = d[i - 1][0];
        } else {
            d[i][1] = d[i - 1][1];
            d[i][0] = d[i - 1][0] + 1;
        }
    }

    cout << max(d[n][0], d[n][1]);


    return 0;
}//gvjevt