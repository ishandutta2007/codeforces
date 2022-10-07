#include <bits/stdc++.h>

void solve() {
    int n, d;
    std::cin >> n >> d;
    std::vector<int> a(n);
    for (int &x : a) {
        std::cin >> x;
    }
    d = n - d;
    std::vector<bool> vis(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            std::vector<int> c;
            for (int j = i; !vis[j]; j = (j + d) % n) {
                c.push_back(a[j]);
                vis[j] = true;
            }
            c.insert(c.end(), c.begin(), c.end());
            int now = 0, len = 0;
            for (int x : c) {
                if (x) {
                    ++now;
                } else {
                    now = 0;
                }
                len = std::max(len, now);
            }
            if (len == (int)c.size()) {
                std::cout << -1 << "\n";
                return;
            }
            ans = std::max(ans, len);
        }
    }
    std::cout << ans << "\n";
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