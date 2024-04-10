#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += s[i] - '0';
    }
    for (int i = 0; i < n - 1; ++i) {
        ans += s[i] > '0';
    }
    std::cout << ans << "\n";
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