#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
struct Edge {
    int u, v, l;
};
bool operator<(const Edge &a, const Edge &b) {
    return a.l < b.l;
}
struct DSU {
    std::vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 1) { std::iota(f.begin(), f.end(), 0); }
    int leader(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) { return leader(x) == leader(y); }
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return false;
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[leader(x)]; }
};
constexpr int inf = 1e9 + 1;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, m, k;
        std::cin >> n >> m >> k;
        std::vector<Edge> e1(m), e2;
        int mn = inf;
        for (int i = 0; i < m; ++i) {
            int u, v, l;
            std::cin >> u >> v >> l;
            --u;
            --v;
            e1[i] = {u, v, std::max(0, l - k)};
            if (l <= k) {
                e2.push_back({u, v, k - l});
            } else {
                mn = std::min(mn, l - k);
            }
        }
        std::sort(e1.begin(), e1.end());
        std::sort(e2.begin(), e2.end());
        i64 ans = 0;
        DSU t(n);
        for (auto [u, v, l] : e1) {
            if (t.merge(u, v)) {
                ans += l;
            }
        }
        if (ans == 0) {
            ans = mn;
        }
        int cnt = 0;
        t = n;
        for (auto [u, v, l] : e2) {
            if (t.merge(u, v)) {
                ++cnt;
            }
        }
        if (cnt == n - 1) {
            ans = std::min<i64>(ans, e2[0].l);
        }
        std::cout << ans << "\n";
    }
    return 0;
}