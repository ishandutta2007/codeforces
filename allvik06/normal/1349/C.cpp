#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1e18;

int power(int a, int n) {
    if (n == 0) return 1;
    if (n == 1) return a;
    if (n % 2 == 0) {
        int tmp = power(a, n / 2);
        return tmp * tmp;
    } else {
        return a * power(a, n - 1);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, t;
    cin >> n >> m >> t;
    vector <vector <int>> a(n, vector <int> (m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }
    vector <vector <int>> dist(n, vector <int> (m, INF));
    bool flag = false;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    queue <pair <int, int>> nul, one, two;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < 4; ++k) {
                int x = i + dx[k], y = j + dy[k];
                if (x < 0 || x >= n || y < 0 || y >= m) continue;
                if (a[x][y] == a[i][j]) {
                    dist[i][j] = 1;
                    flag = true;
                    nul.push({i, j});
                    break;
                }
            }
        }
    }
    while (!nul.empty() || !one.empty() || !two.empty()) {
        if (nul.empty()) {
            swap(nul, one);
            swap(one, two);
        }
        if (nul.empty()) {
            swap(nul, one);
        }
        pair <int, int> now = nul.front();
        nul.pop();
        for (int k = 0; k < 4; ++k) {
            int x = now.first + dx[k], y = now.second + dy[k];
            if (x < 0 || x >= n || y < 0 || y >= m) continue;
            int f = (a[now.first][now.second]^1);
            if (dist[x][y] > dist[now.first][now.second] + (f != a[x][y]) + 1) {
                if (f != a[x][y]) {
                    two.push({x, y});
                }
                else {
                    one.push({x, y});
                }
                dist[x][y] = dist[now.first][now.second] + (f != a[x][y]) + 1;
            }
        }
    }
    while (t--) {
        int x, y, p;
        cin >> x >> y >> p; --x; -- y;
        if (!flag) {
            cout << a[x][y] << "\n";
        }
        else {
            if (p < dist[x][y]) {
                cout << a[x][y] << "\n";
            }
            else {
                cout << (a[x][y] + p - dist[x][y] + 1) % 2 << "\n";
            }
        }
    }
}