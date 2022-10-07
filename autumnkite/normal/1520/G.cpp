#include <bits/stdc++.h>

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

const long long INF = std::numeric_limits<long long>::max();

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, w;
    std::cin >> n >> m >> w;
    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> a[i][j];
        }
    }

    auto bfs = [&](int sx, int sy) {
        std::vector<std::vector<int>> dis(n, std::vector<int>(m, n * m));
        std::vector<std::pair<int, int>> Q;
        Q.emplace_back(sx, sy);
        dis[sx][sy] = 0;
        for (int i = 0; i < (int)Q.size(); ++i) {
            auto [x, y] = Q[i];
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if (0 <= nx && nx < n && 0 <= ny && ny < m
                    && a[nx][ny] != -1 && dis[nx][ny] == n * m) {
                    dis[nx][ny] = dis[x][y] + 1;
                    Q.emplace_back(nx, ny);
                }
            }
        }
        return dis;
    };

    auto disS = bfs(0, 0);
    auto disT = bfs(n - 1, m - 1);

    long long minS = INF, minT = INF;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (disS[i][j] < n * m && a[i][j] > 0) {
                minS = std::min(minS, 1ll * disS[i][j] * w + a[i][j]);
            }
            if (disT[i][j] < n * m && a[i][j] > 0) {
                minT = std::min(minT, 1ll * disT[i][j] * w + a[i][j]);
            }
        }
    }
    long long ans = INF;
    if (minS != INF && minT != INF) {
        ans = std::min(ans, minS + minT);
    }
    if (disT[0][0] < n * m) {
        ans = std::min(ans, 1ll * disT[0][0] * w);
    }
    std::cout << (ans == INF ? -1 : ans) << "\n";
}