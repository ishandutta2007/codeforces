#include <iostream>
#include <vector>
#include <cmath>
#include <array>
#include <set>
#include <queue>

using namespace std;
#define int long long

struct dsu {
    vector <int> p, sz;

    dsu(int n) {
        p.resize(n);
        sz.resize(n, 1);
        for (int i = 0; i < n; ++i) p[i] = i;
    }

    int parent(int v) {
        if (v == p[v]) return v;
        p[v] = parent(p[v]);
        return p[v];
    }

    inline void unite(int a, int b) {
        a = parent(a);
        b = parent(b);
        if (a == b) return;
        if (sz[a] > sz[b]) swap(a, b);
        p[a] = b;
        sz[b] += sz[a];
    }
};

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    int n, m, k;
    cin >> n >> m >> k;
    int a[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    vector <array <int, 3>> all;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            all.push_back({a[i][j], i, j});
        }
    }
    sort(all.rbegin(), all.rend());
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    dsu now(n * m);
    for (auto i : all) {
        for (int l = 0; l < 4; ++l) {
            int x = i[1] + dx[l], y = i[2] + dy[l];
            if (x < 0 || x >= n || y < 0 || y >= m || a[x][y] < i[0]) continue;
            now.unite(i[1] * m + i[2], x * m + y);
        }
        if (k % i[0] != 0) continue;
        int cnt = k / i[0];
        if (cnt > now.sz[now.parent(i[1] * m + i[2])]) continue;
        int ans[n][m];
        bool used[n][m];
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < m; ++y) {
                ans[x][y] = 0;
                used[x][y] = false;
            }
        }
        queue <pair <int, int>> q;
        q.push(make_pair(i[1], i[2]));
        used[i[1]][i[2]] = true;
        for (int _ = 0; _ < cnt; ++_) {
            int x = q.front().first, y = q.front().second;
            ans[x][y] = i[0];
            q.pop();
            for (int l = 0; l < 4; ++l) {
                int xx = x + dx[l], yy = y + dy[l];
                if (xx < 0 || xx >= n || yy < 0 || yy >= m || a[xx][yy] < i[0] || used[xx][yy]) continue;
                used[xx][yy] = true;
                q.push(make_pair(xx, yy));
            }
        }
        cout << "YES\n";
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < m; ++y) {
                cout << ans[x][y] << " ";
            }
            cout << "\n";
        }
        return 0;
    }
    cout << "NO";
}