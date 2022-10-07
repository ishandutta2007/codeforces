#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<std::vector<int>> pos(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        --a[i];
        pos[a[i]].push_back(i);
    }
    std::vector<std::vector<int>> f(n, std::vector<int>(n));
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            f[i][j] = f[i][j - 1];
            for (int k : pos[a[j]]) {
                if (i <= k && k < j) {
                    f[i][j] = std::max(f[i][j], f[i][k] + f[k + 1][j - 1] + 1);
                }
            }
        }
    }
    std::cout << n - 1 - f[0][n - 1] << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}