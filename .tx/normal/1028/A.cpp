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

    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int sx = -1, sy;
    for (int i = 0; sx == -1 && i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'B') {
                sx = i;
                sy = j;
                break;
            }
        }
    }

    int len = 1;
    for (; sy + len < m && a[sx][sy + len] == 'B'; len++) {
    }

    len /= 2;
    cout << sx + len + 1 << " " << sy + len + 1 << "\n";

    return 0;
}//oejlqz