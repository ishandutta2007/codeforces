#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int p = std::find(s.begin(), s.end(), '0') - s.begin();
    if (p < (n + 1) / 2) {
        std::cout << p + 1 << " " << n << " " << p + 2 << " " << n << "\n";
    } else if (p < n) {
        std::cout << 1 << " " << p + 1 << " " << 1 << " " << p << "\n";
    } else {
        std::cout << 1 << " " << n - 1 << " " << 2 << " " << n << "\n";
    }
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