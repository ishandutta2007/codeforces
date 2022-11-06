#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

int d[3333][3333];

int main() {
#ifdef G13
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    memset(d, -1, sizeof(int) * 3333 * 3333);

    int n;
    cin >> n;
    vector<int> s(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    for (int i = 0; i < n; i++) {
        d[i][0] = c[i];
        for (int j = 0; j < i; j++) {
            if (s[j] >= s[i]) {
                continue;
            }
            if (d[j][0] != -1) {
                if (d[i][1] == -1) {
                    d[i][1] = 1e9;
                }
                d[i][1] = min(d[i][1], d[j][0] + c[i]);
            }
            if (d[j][1] != -1) {
                if (d[i][2] == -1) {
                    d[i][2] = 1e9;
                }
                d[i][2] = min(d[i][2], d[j][1] + c[i]);
            }
        }
    }

    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        if (d[i][2] != -1) {
            ans = min(ans, d[i][2]);
        }
    }

    cout << (ans == 1e9 ? -1 : ans);

    return 0;
}