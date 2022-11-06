#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int dc[4] = {0, 0, 1, 1};

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    int r, c, x, y;
    cin >> r >> c >> x >> y;
    --r; --c;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> d(n, vector<int>(m, 1e9));
    d[r][c] = 0;
    deque<int> q;
    q.push_back(r);
    q.push_back(c);
    while (!q.empty()) {
        int vx = q.front(); q.pop_front();
        int vy = q.front(); q.pop_front();

        for (int i = 0; i < 4; i++) {
            int x = vx + dx[i];
            int y = vy + dy[i];
            if (x < 0 || x >= n || y < 0 || y >= m || a[x][y] == '*') {
                continue;
            }
            if (d[x][y] > d[vx][vy] + dc[i]) {
                d[x][y] = d[vx][vy] + dc[i];
                if (dc[i] == 0) {
                    q.push_front(y);
                    q.push_front(x);
                } else {
                    q.push_back(x);
                    q.push_back(y);
                }
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (d[i][j] == 1e9) {
                continue;
            }
            int l = 0, r = 0;
            if (j < c) {
                l += c - j;
            } else {
                r += j - c;
            }
            int t = (d[i][j] - l - r) / 2;
            l += t;
            r += t;
            if (l <= x && r <= y) {
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}//elliic