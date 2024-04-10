#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

int n;
int used[1111][1111];

int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy[8] = {1, 1, 1, 0, -1, -1, -1, 0};

bool on(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= n;
}

void dfs(int vx, int vy) {
    used[vx][vy] = 1;
    for (int t = 0; t < 8; t++) {
        int x = vx + dx[t];
        int y = vy + dy[t];
        if (!on(x, y) || used[x][y]) {
            continue;
        }
        dfs(x, y);
    }
}

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;
    int ax, ay, sx, sy, ex, ey;
    cin >> ax >> ay >> sx >> sy >> ex >> ey;

    for (int t = 0; t < 8; t++) {
        for (int i = 0; i < n; i++) {
            int x = ax + dx[t] * i;
            int y = ay + dy[t] * i;
            if (on(x, y)) {
                used[x][y] = true;
            }
        }
    }

    dfs(sx, sy);

    if (used[ex][ey]) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}//ybbadz