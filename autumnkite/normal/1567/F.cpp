#include <bits/stdc++.h>

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<std::vector<int>> ans(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        int now = i & 1;
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '.') {
                ans[i][j] = now ? 1 : 4;
            } else if (a[i - 1][j] == 'X') {
                now ^= 1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'X') {
                for (int k = 0; k < 4; ++k) {
                    if (a[i + dx[k]][j + dy[k]] == '.') {
                        ans[i][j] += ans[i + dx[k]][j + dy[k]];
                    }
                }
                if (ans[i][j] % 5 != 0) {
                    std::cout << "NO\n";
                    return 0;
                }
            }
        }
    }
    std::cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << ans[i][j] << " ";
        }
        std::cout << "\n";
    }
}