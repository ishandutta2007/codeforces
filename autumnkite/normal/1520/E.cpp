#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<int> p;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '*') {
            p.push_back(i);
        }
    }
    if (p.empty()) {
        std::cout << 0 << "\n";
        return;
    }
    int m = p.size() / 2;
    long long ans = 0;
    for (int i = 0; i < m; ++i) {
        ans += p[m] - p[i] - (m - i);
    }
    for (int i = m; i < (int)p.size(); ++i) {
        ans += p[i] - p[m] - (i - m);
    }
    std::cout << ans << "\n";
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