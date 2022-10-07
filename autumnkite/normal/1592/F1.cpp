#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector a(n, std::vector(m, 0));
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < m; ++j) {
            a[i][j] ^= s[j] == 'B';
            if (i) {
                a[i - 1][j] ^= s[j] == 'B';
            }
            if (j) {
                a[i][j - 1] ^= s[j] == 'B';
            }
            if (i && j) {
                a[i - 1][j - 1] ^= s[j] == 'B';
            }
        }
    }

    int sum = std::accumulate(a.begin(), a.end(), 0, 
    [&](int a, const std::vector<int> &b) {
        return std::accumulate(b.begin(), b.end(), a);
    });

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            if (a[i][j] && a[n - 1][j] && a[i][m - 1] && a[n - 1][m - 1]) {
                std::cout << sum - 1 << "\n";
                return 0;
            }
        }
    }
    std::cout << sum << "\n";
}