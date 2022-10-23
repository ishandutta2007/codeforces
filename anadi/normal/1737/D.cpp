#include <bits/stdc++.h>

using namespace std;

const int N = 507;
const long long INF = 1'001'002'003'004'005'006LL;

int n, m;
int dist[N][N];
long long best[N];
tuple <int, int, int> edges[N * N];

void solve()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        best[i] = INF;
        for (int j = 1; j <= n; ++j) {
            dist[i][j] = i == j ? 0 : N;
        }
    }

    for (int i = 1; i <= m; ++i) {
        auto &[u, v, c] = edges[i];
        scanf("%d %d %d", &u, &v, &c);
        
        best[u] = min(best[u], (long long)c);
        best[v] = min(best[v], (long long)c);

        dist[u][v] = min(dist[u][v], 1);
        dist[v][u] = min(dist[v][u], 1);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }

    long long ans = INF;
    for (int i = 1; i <= m; ++i) {
        auto &[u, v, c] = edges[i];
        ans = min(ans, 1LL * (dist[1][u] + dist[v][n] + 1) * c);
        ans = min(ans, 1LL * (dist[1][v] + dist[u][n] + 1) * c);
    }

    for (int i = 1; i <= n; ++i) {
        int best_coef = 3 * N;
        for (int j = 1; j <= n; ++j) {
            best_coef = min(best_coef, dist[1][j] + dist[j][n] + 2 + dist[i][j]);
        }

        ans = min(ans, best_coef * best[i]);
    }

    printf("%lld\n", ans);
}

int main()
{
    int cases = 1;
    scanf("%d", &cases);

    while (cases--) {
        solve();
    }

    return 0;
}