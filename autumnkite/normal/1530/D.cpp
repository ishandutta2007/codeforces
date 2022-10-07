#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    std::vector<std::vector<int>> pos(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        --a[i];
        b[i] = a[i];
        pos[a[i]].push_back(i);
    }
    for (int _ = 0; _ < 2; ++_) {
        std::vector<bool> vis(n);
        for (int i = 0; i < n; ++i) {
            if (!pos[i].empty()) {
                vis[_ == 0 ? pos[i].front() : pos[i].back()] = true;
            }
        }
        std::vector<int> s, t;
        for (int i = 0; i < n; ++i) {
            if (!vis[i] && pos[i].empty()) {
                s.push_back(i);
                t.push_back(i);
            }
        }
        int tmp = t.size();
        for (int i = 0; i < n; ++i) {
            if (!vis[i] && !pos[i].empty()) {
                s.push_back(i);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (vis[i] && pos[i].empty()) {
                t.push_back(i);
            }
        }
        if (tmp == 1 && (int)t.size() == 1) {
            continue;
        }
        for (int i = 0; i < (int)t.size(); ++i) {
            a[s[i]] = t[(i + 1) % t.size()];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += a[i] == b[i];
        }
        std::cout << ans << "\n";
        for (int i = 0; i < n; ++i) {
            std::cout << a[i] + 1 << " \n"[i == n - 1];
        }
        return;
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