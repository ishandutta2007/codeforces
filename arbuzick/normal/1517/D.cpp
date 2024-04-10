#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pii pair<int, int>

const int maxn = 500, inf = 1e12;
int dist[maxn][maxn][11];

int a[maxn][maxn], b[maxn][maxn];

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    if (k % 2 == 1) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << -1 << ' ';
            }
            cout << '\n';
        }
        return;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            cin >> b[i][j];
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int d = 0; d < k / 2; ++d) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dist[i][j][d + 1] = inf;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i + 1 < n) {
                    dist[i + 1][j][d + 1] = min(dist[i + 1][j][d + 1], dist[i][j][d] + a[i][j]);
                    dist[i][j][d + 1] = min(dist[i][j][d + 1], dist[i + 1][j][d] + a[i][j]);
                }
                if (j + 1 < m) {
                    dist[i][j + 1][d + 1] = min(dist[i][j + 1][d + 1], dist[i][j][d] + b[i][j]);
                    dist[i][j][d + 1] = min(dist[i][j][d + 1], dist[i][j + 1][d] + b[i][j]);
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << dist[i][j][k / 2] * 2 << ' ';
        }
        cout << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}