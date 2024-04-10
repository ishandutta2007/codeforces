#include <bits/stdc++.h>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::string s, t;
    s += '1', t += '1';
    for (int i = 0; i < n - 2; ++i) {
        s += '0' + (i & 1);
    }
    for (int i = 0; i < m - 2; ++i) {
        t += '0' + (i & 1);
    }
    if (s.back() == '1') {
        s.back() = '0';
    }
    if (t.back() == '1') {
        t.back() = '0';
    }
    s += '1', t += '1';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 || i == n - 1) {
                std::cout << t[j];
            } else if (j == 0 || j == m - 1) {
                std::cout << s[i];
            } else {
                std::cout << '0';
            }
        }
        std::cout << "\n";
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