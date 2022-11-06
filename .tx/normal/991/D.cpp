#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

int d[4][111];
string a[2];

void relax(int& a, int b) {
    a = max(a, b);
}

int main() {
#ifdef G13
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> a[0] >> a[1];
    int n = a[0].size();

    memset(d, -1, sizeof(int) * 4 * 111);
    d[3][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int m = 0; m < 4; m++) {
            if (d[m][i] == -1) {
                continue;
            }
            if (a[0][i] == 'X' && a[1][i] == 'X') {
                relax(d[3][i + 1], d[m][i]);
            } else if (a[0][i] == 'X' || a[1][i] == 'X') {
                if (m == 0) {
                    relax(d[3][i + 1], d[m][i] + 1);
                }
                if (a[0][i] == 'X') {
                    relax(d[1][i + 1], d[m][i]);
                } else {
                    relax(d[2][i + 1], d[m][i]);
                }
            } else {
                if (m != 3) {
                    relax(d[3][i + 1], d[m][i] + 1);
                }
                if (m == 0) {
                    relax(d[1][i + 1], d[m][i] + 1);
                    relax(d[2][i + 1], d[m][i] + 1);
                }
                relax(d[0][i + 1], d[m][i]);
            }
        }
    }

    int ans = 0;
    for (int m = 0; m < 4; m++) {
        ans = max(ans, d[m][n]);
    }

    cout << ans;

    return 0;
}