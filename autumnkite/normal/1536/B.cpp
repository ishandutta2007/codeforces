#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int pw = 1;
    for (int len = 1; len <= (int)s.size(); ++len) {
        pw *= 26;
        for (int S = 0; S < pw; ++S) {
            std::string t;
            for (int i = 0, x = S; i < len; ++i) {
                t += x % 26 + 'a';
                x /= 26;
            }
            std::reverse(t.begin(), t.end());
            if (s.find(t) == s.npos) {
                std::cout << t << "\n";
                return;
            }
        }
    }
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