#include <bits/stdc++.h>

const int V = 7000;

typedef std::bitset<V + 1> state;

int mu[V + 1];
state g[V + 1], h[V + 1];

void init() {
    mu[1] = 1;
    for (int i = 1; i <= V; ++i) {
        for (int j = i + i; j <= V; j += i) {
            mu[j] -= mu[i];
        }
    }
    for (int i = 1; i <= V; ++i) {
        for (int j = i; j <= V; j += i) {
            g[j][i] = 1;
            h[i][j] = mu[j / i];
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    init();
    
    std::vector<state> f(n);

    while (q--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int x, v;
            std::cin >> x >> v;
            --x;
            f[x] = g[v];
        } else if (op == 2) {
            int x, y, z;
            std::cin >> x >> y >> z;
            --x, --y, --z;
            f[x] = f[y] ^ f[z];
        } else if (op == 3) {
            int x, y, z;
            std::cin >> x >> y >> z;
            --x, --y, --z;
            f[x] = f[y] & f[z];
        } else {
            int x, v;
            std::cin >> x >> v;
            --x;
            std::cout << ((f[x] & h[v]).count() & 1);
        }
    }
}