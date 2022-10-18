#include<bits/stdc++.h>

using namespace std;

int const maxn = 1005, maxc = 42;
int dist[maxn][maxn][maxc];
int a[maxn][maxn];
int best[maxc][maxc];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, q, r1, c1, r2, c2;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) cin >> a[i][j];
    }
    for (int i = 0; i <= n + 1; ++i) {
        for (int j = 0; j <= m + 1; ++j) {
            for (int z = 1; z <= k; ++z) dist[i][j][z] = n * m * 2;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int z = 1; z <= k; ++z) {
                dist[i][j][z] = min({dist[i][j][z], dist[i - 1][j][z] + 1, dist[i][j - 1][z] + 1});
            }
            dist[i][j][a[i][j]] = 0;
        }
    }
    for (int i = n; i >= 1; --i) {
        for (int j = m; j >= 1; --j) {
            for (int z = 1; z <= k; ++z) {
                dist[i][j][z] = min({dist[i][j][z], dist[i + 1][j][z] + 1, dist[i][j + 1][z] + 1});
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= 1; --j) {
            for (int z = 1; z <= k; ++z) {
                dist[i][j][z] = min({dist[i][j][z], dist[i - 1][j][z] + 1, dist[i][j + 1][z] + 1});
            }
        }
    }
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= m; ++j) {
            for (int z = 1; z <= k; ++z) {
                dist[i][j][z] = min({dist[i][j][z], dist[i][j - 1][z] + 1, dist[i + 1][j][z] + 1});
            }
        }
    }
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= k; ++j) best[i][j] = n * m * 2;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int z = 1; z <= k; ++z) {
                best[a[i][j]][z] = min(best[a[i][j]][z], dist[i][j][z]);
            }
        }
    }
    bool find = true;
    while (find) {
        find = false;
        for (int z = 1; z <= k; ++z) {
            for (int i = 1; i <= k; ++i) {
                for (int j = 1; j <= k; ++j) {
                    int cur = best[i][z] + best[z][j] + 1;
                    if (cur < best[i][j]) {
                        best[i][j] = cur;
                        find = true;
                    }
                }
            }
        }
    }
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        cin >> r1 >> c1 >> r2 >> c2;
        int ans = abs(r1 - r2) + abs(c2 - c1);
        if (a[r1][c1] == a[r2][c2]) ans = min(ans, 1);
        for (int j = 1; j <= k; ++j) {
            for (int z = 1; z <= k; ++z) {
                int add;
                if (j != z) add = 2;
                else add = 1;
                int cur = dist[r1][c1][j] + best[j][z] + add + dist[r2][c2][z];
                ans = min(ans, cur);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}