#include <bits/stdc++.h>

const long long INF = 0x3f3f3f3f3f3f3f3fll;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    a.insert(a.begin(), -INF);
    a.insert(a.end(), INF);
    n += 2;

    std::vector<std::vector<std::pair<long long, long long>>> seg(n);
    for (int i = 0; i < m; ++i) {
        long long l, r;
        std::cin >> l >> r;
        int pl = std::lower_bound(a.begin(), a.end(), l) - a.begin();
        int pr = std::upper_bound(a.begin(), a.end(), r) - a.begin();
        if (pl != pr) {
            continue;
        }
        seg[pl].emplace_back(l, r);
    }

    std::vector<long long> f(n, INF), g(n, INF);
    f[0] = 0, g[0] = 0;
    for (int i = 1; i < n; ++i) {
        std::sort(seg[i].begin(), seg[i].end());
        long long r = a[i];
        for (int j = (int)seg[i].size(); j >= 0; --j) {
            if (j < (int)seg[i].size()) {
                r = std::min(r, seg[i][j].second);
            }
            long long l = a[i - 1];
            if (j > 0) {
                l = seg[i][j - 1].first;
            }
            f[i] = std::min(f[i], f[i - 1] + (l - a[i - 1]) + 2 * (a[i] - r));
            f[i] = std::min(f[i], g[i - 1] + 2 * (l - a[i - 1]) + 2 * (a[i] - r));
            g[i] = std::min(g[i], f[i - 1] + (l - a[i - 1]) + (a[i] - r));
            g[i] = std::min(g[i], g[i - 1] + 2 * (l - a[i - 1]) + (a[i] - r));
        }
    }
    std::cout << std::min(f[n - 1], g[n - 1]) << "\n";
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