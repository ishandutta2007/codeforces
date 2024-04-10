#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::map<std::pair<int, int>, int> cnt;
    std::pair<int, int> now;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'D') {
            ++now.first;
        } else {
            ++now.second;
        }
        int g = std::__gcd(now.first, now.second);
        std::pair<int, int> tmp(now.first / g, now.second / g);
        std::cout << ++cnt[tmp] << " ";
    }
    std::cout << "\n";
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