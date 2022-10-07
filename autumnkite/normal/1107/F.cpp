#include <bits/stdc++.h>

struct node {
    int s, d, k;

    bool operator<(const node &rhs) const {
        return d > rhs.d;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<node> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i].s >> a[i].d >> a[i].k;
    }
    std::sort(a.begin(), a.end());
    
    std::vector<long long> f(n + 1);
    for (int i = 0; i < n; ++i) {
        std::vector<long long> g(n + 1);
        for (int j = 0; j <= n; ++j) {
            g[j] = f[j] + std::max(a[i].s - 1ll * a[i].d * a[i].k, 0ll);
        }
        for (int j = 0; j < n; ++j) {
            g[j + 1] = std::max(g[j + 1], f[j] + a[i].s - 1ll * a[i].d * j);
        }
        f.swap(g);
    }
    std::cout << *std::max_element(f.begin(), f.end()) << "\n";
}