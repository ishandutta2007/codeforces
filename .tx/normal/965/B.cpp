#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

int main() {
#ifdef G13
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> b(n, vector<int>(n));

    auto f = [&](int x, int y, int dx, int dy) {
        for (int i = 0; i < k; i++) {
            if (x < 0 || x >= n || y < 0 || y >= n || a[x][y] == '#') {
                return;
            }
            x += dx;
            y += dy;
        }
        for (int i = 0; i < k; i++) {
            x -= dx;
            y -= dy;
            b[x][y]++;
        }
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            f(i, j, 1, 0);
            f(i, j, 0, 1);
//            f(i, j, 1, 1);
//            f(i, j, 1, -1);
        }
    }

    int ax = 0, ay = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (b[i][j] > b[ax][ay]) {
                ax = i;
                ay = j;
            }
        }
    }

    cout << ax + 1 << " " << ay + 1 << "\n";

    return 0;
}