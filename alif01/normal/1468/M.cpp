#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
constexpr int Lim = 400;
void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(n);
    std::map<int, int> id;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int k;
        std::cin >> k;
        a[i].resize(k);
        for (int j = 0; j < k; ++j) {
            int x;
            std::cin >> x;
            if (!id.count(x)) {
                id[x] = cnt++;
            }
            a[i][j] = id[x];
        }
        std::sort(a[i].begin(), a[i].end());
    }
    std::vector<std::vector<int>> p(cnt);
    std::vector<int> last(cnt, -1), pos(cnt, -1);
    for (int i = 0; i < n; ++i) {
        for (auto v : a[i]) {
            p[v].push_back(i);
        }
    }
    for (int v = 0; v < cnt; ++v) {
        for (auto i : p[v]) {
            if (int(a[i].size()) <= Lim) {
                for (int j = 0; a[i][j] < v; ++j) {
                    int u = a[i][j];
                    if (last[u] == v) {
                        std::cout << pos[u] + 1 << " " << i + 1 << "\n";
                        return;
                    }
                    last[u] = v;
                    pos[u] = i;
                }
            }
        }
    }
    std::vector<bool> f(cnt);
    for (int i = 0; i < n; ++i) {
        if (int(a[i].size()) > Lim) {
            for (auto v : a[i]) {
                f[v] = true;
            }
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    int cnt = 0;
                    for (auto v : a[j]) {
                        cnt += f[v];
                    }
                    if (cnt >= 2) {
                        std::cout << i + 1 << " " << j + 1 << "\n";
                        return;
                    }
                }
            }
            for (auto v : a[i]) {
                f[v] = false;
            }
        }
    }
    std::cout << -1 << "\n";
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}