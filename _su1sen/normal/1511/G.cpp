#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

constexpr int L = 18;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<uint8_t> c(m);
    for (int i = 0; i < n; ++i) {
        int v;
        std::cin >> v;
        c[--v] ^= 1;
    }
    std::vector<uint8_t> s(m + 1);
    for (int i = 0; i < m; ++i) {
        s[i + 1] ^= s[i] ^ c[i];
    }

    std::vector tab(L, std::vector<uint32_t>(m));
    for (int i = 1; i < L; ++i) {
        for (int l = 0; l + (1 << i) <= m; ++l) {
            int h = 1 << (i - 1);
            tab[i][l] = tab[i - 1][l] ^ tab[i - 1][l + h] ^ ((s[l + 2 * h] ^ s[l + h]) << (i - 1));
        }
    }

    int q;
    std::cin >> q;
    while (q --> 0) {
        int l, r;
        std::cin >> l >> r;
        --l;

        uint32_t x = 0;
        for (int i = L; i --> 0;) {
            int w = 1 << i;
            if (l + w > r) continue;
            x ^= tab[i][l] ^ ((s[r] ^ s[l + w]) << i);
            l += w;
        }
        std::cout << (x ? 'A' : 'B');
    }
    std::cout << '\n';

    return 0;
}