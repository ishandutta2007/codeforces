#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;

struct state {
    int mn, mx, s;

    state() : mn(INF), mx(-INF), s(INF) {}
    state(int v) : mn(v), mx(v), s(INF) {}
    state(int _mn, int _mx, int _s) : mn(_mn), mx(_mx), s(_s) {}

    state operator+(const state &rhs) const {
        return state(std::min(mn, rhs.mn), std::max(mx, rhs.mx), std::min({s, rhs.s, rhs.mn - mx}));
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    std::cin >> m >> n;
    std::vector<bool> vis(1 << n);
    for (int i = 0; i < m; ++i) {
        int x;
        std::cin >> x;
        vis[x] = true;
    }

    std::vector<state> f(1 << n);
    for (int x = 0; x < (1 << n); ++x) {
        if (vis[x]) {
            f[x] = 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        std::vector<state> g(1 << n);
        for (int x = 0; x < (1 << n); ++x) {
            state a = f[x], b = f[x ^ (1 << i)];
            if (b.mn != -INF) {
                b.mn ^= 1 << i;
                b.mx ^= 1 << i;
            }
            g[x] = a + b;
        }
        f.swap(g);
    }
    for (int x = 0; x < (1 << n); ++x) {
        std::cout << f[x].s << " ";
    }
    std::cout << "\n";
}