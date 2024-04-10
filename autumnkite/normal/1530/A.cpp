#include <bits/stdc++.h>

void solve() {
    std::string s;
    std::cin >> s;
    std::cout << *std::max_element(s.begin(), s.end()) << "\n";
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