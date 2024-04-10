#include <bits/stdc++.h>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> cnt(m, std::vector<int>(26));
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < m; ++j) {
            ++cnt[j][s[j] - 'a'];
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < m; ++j) {
            --cnt[j][s[j] - 'a'];
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (cnt[i][j]) {
                std::cout << char(j + 'a');
            }
        }
    }
    std::cout << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}