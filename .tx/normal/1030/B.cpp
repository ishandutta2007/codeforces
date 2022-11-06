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

    int n, d;
    cin >> n >> d;
    int x1 = d, y1 = -d, x2 = 2 * n - d, y2 = d;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        int nx = x + y;
        int ny = x - y;
        if (x1 <= nx && nx <= x2 && y1 <= ny && ny <= y2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }



    return 0;
}//sspkdf