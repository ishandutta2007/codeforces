#include <bits/stdc++.h>

int calc(const std::string &s, const std::string &t) {
    int p = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (p < (int)t.size() && s[i] == t[p]) {
            ++p;
        }
    }
    return (int)s.size() + (int)t.size() - 2 * p;
}

void solve() {
    int n;
    std::cin >> n;
    std::string s(std::to_string(n));
    int ans = (int)s.size() + 1;
    for (int i = 0; i < 64; ++i) {
        ans = std::min(ans, calc(s, std::to_string(1ull << i)));
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