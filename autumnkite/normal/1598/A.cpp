#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::string a, b;
    std::cin >> a >> b;
    for (int i = 0; i < n; ++i) {
        if (a[i] == '1' && b[i] == '1') {
            std::cout << "NO\n";
            return;
        }
    }
    std::cout << "YES\n";
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