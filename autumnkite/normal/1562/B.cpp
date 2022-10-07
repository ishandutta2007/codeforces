#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;

bool check(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int ans = INF;
    auto dfs = [&](auto &self, int k, int d, int lst, int now) {
        if (k == d) {
            if (!check(now)) {
                ans = std::min(ans, now);
            }
            return;
        }
        for (int i = lst + 1; i < (int)s.size(); ++i) {
            self(self, k + 1, d, i, now * 10 + s[i] - '0');
        }
    };
    int i = 1;
    while (1) {
        dfs(dfs, 0, i, -1, 0);
        if (ans < INF) {
            std::cout << i << "\n";
            std::cout << ans << "\n";
            return;
        }
        ++i;
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