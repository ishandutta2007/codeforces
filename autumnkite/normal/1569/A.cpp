#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    for (int i = 0; i + 1 < n; ++i) {
        if (s[i] != s[i + 1]) {
            std::cout << i + 1 << " " << i + 2 << "\n";
            return;
        }
    }
    std::cout << -1 << " " << -1 << "\n";
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