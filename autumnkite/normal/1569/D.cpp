#include <bits/stdc++.h>

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }
    
    std::vector<std::vector<int>> v(n), h(m);
    for (int i = 0; i < k; ++i) {
        int x, y;
        std::cin >> x >> y;
        int px = std::upper_bound(a.begin(), a.end(), x) - a.begin() - 1;
        int py = std::upper_bound(b.begin(), b.end(), y) - b.begin() - 1;
        if (a[px] == x && b[py] == y) {
            continue;
        }
        if (b[py] == y) {
            v[px].push_back(py);
        } else {
            h[py].push_back(px);
        }
    }

    long long ans = 0;
    std::vector<int> cx(n), cy(m);
    for (int i = 0; i < n; ++i) {
        ans += 1ll * (int)v[i].size() * ((int)v[i].size() - 1) / 2;
        for (int y : v[i]) {
            ans -= cy[y];
            ++cy[y];
        }
        for (int y : v[i]) {
            --cy[y];
        }
    }
    for (int i = 0; i < m; ++i) {
        ans += 1ll * (int)h[i].size() * ((int)h[i].size() - 1) / 2;
        for (int x : h[i]) {
            ans -= cx[x];
            ++cx[x];
        }
        for (int x : h[i]) {
            --cx[x];
        }
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