#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <set>

using namespace std;
const int INF = 1e9;

inline void solve() {
    int n, k;
    cin >> n >> k;
    vector <array <int, 4>> a(n);
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    vector <vector <vector <int>>> w(k + 1, vector <vector <int>> (k + 1, vector <int> (4)));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> a[i][j]; --a[i][j];
        }
        if (a[i][0] == a[i][2]) {
            int x = min(a[i][1], a[i][3]);
            ++w[a[i][0]][x + 1][1];
            ++w[a[i][0] + 1][x + 1][0];
        } else {
            int x = min(a[i][0], a[i][2]);
            ++w[x + 1][a[i][1]][3];
            ++w[x + 1][a[i][1] + 1][2];
        }
    }
    set <pair <int, pair <int, int>>> s;
    s.insert(make_pair(0, make_pair(0, 0)));
    vector <vector <int>> d(k + 1, vector <int> (k + 1, INF));
    while (!s.empty()) {
        auto now = *s.begin();
        int x = now.second.first;
        int y = now.second.second;
        int cx = k - x;
        int cy = k - y;
        s.erase(s.begin());
        for (int t = 0; t < 4; ++t) {
            int xx = x + dx[t];
            int yy = y + dy[t];
            if (xx < 0 || xx > k || yy < 0 || yy > k) continue;
            int nw = now.first + w[now.second.first][now.second.second][t] + w[cx][cy][t ^ 1];
            if (d[xx][yy] > nw) {
                s.erase(make_pair(d[xx][yy], make_pair(xx, yy)));
                d[xx][yy] = nw;
                s.insert(make_pair(d[xx][yy], make_pair(xx, yy)));
            }
        }
    }
    cout << n - d[k / 2][k / 2] << "\n";
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

/*

 */