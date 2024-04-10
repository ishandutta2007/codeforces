#include <bits/stdc++.h>

int calc(std::string s) {
    std::vector<bool> vis(10);
    for (char c : s) {
        vis[c - '0'] = true;
    }
    return std::accumulate(vis.begin(), vis.end(), 0);
}

void solve() {
    std::string s;
    std::cin >> s;
    int lim;
    std::cin >> lim;
    if (calc(s) <= lim) {
        std::cout << s << "\n";
        return;
    }
    for (int i = (int)s.size() - 1; i >= 0; --i) {
        for (int j = s[i] - '0' + 1; j <= 9; ++j) {
            for (int k = 0; k <= 9; ++k) {
                std::string t(s.begin(), s.begin() + i);
                t += char(j + '0');
                t += std::string((int)s.size() - i - 1, char(k + '0'));
                if (calc(t) <= lim) {
                    std::cout << t << "\n";
                    return;
                }
            }
        }
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