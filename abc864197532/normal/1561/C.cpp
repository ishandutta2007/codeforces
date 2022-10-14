#include <bits/stdc++.h>
int main () {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector <std::vector <int>> a(n);
        for (int i = 0, sz; i < n; ++i) {
            std::cin >> sz;
            a[i].resize(sz);
            for (int &j : a[i])
                std::cin >> j;
        }
        std::vector <int> mx(n), p(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < a[i].size(); ++j) {
                mx[i] = std::max(mx[i], a[i][j] - j);
            }
            p[i] = i;
        }
        std::sort(p.begin(), p.end(), [&](int i, int j) {
            return mx[i] < mx[j];
        });
        int l = -1, r = 1 << 30;
        while (r - l > 1) {
            int m = l + r >> 1, now = m;
            bool dead = false;
            for (int i : p) {
                for (int j : a[i]) {
                    if (now > j)
                        now++;
                    else
                        dead =true;
                }
            }
            if (dead)
                l = m;
            else
                r = m;
        }
        std::cout << r << std::endl;
    }
}