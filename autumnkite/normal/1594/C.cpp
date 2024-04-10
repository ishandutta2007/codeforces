#include <bits/stdc++.h>

void solve() {
    int n;
    char c;
    std::cin >> n >> c;
    std::string s;
    std::cin >> s;
    bool ok = true;
    for (char x : s) {
        ok &= x == c;
    }
    if (ok) {
        std::cout << 0 << "\n";
        return;
    }
    for (int i = 1; i <= n; ++i) {
        bool ok = true;
        for (int j = i; j <= n; j += i) {
            ok &= s[j - 1] == c;
        }
        if (ok) {
            std::cout << 1 << "\n";
            std::cout << i << "\n";
            return;
        }
    }
    std::cout << 2 << "\n";
    std::cout << n << " " << n - 1 << "\n";
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