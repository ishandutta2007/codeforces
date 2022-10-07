#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(n);
    for (int i = 0; i < n; ++i) {
        int c;
        std::cin >> c;
        a[i].resize(c);
        for (int &x : a[i]) {
            std::cin >> x;
        }
    }
    int m;
    std::cin >> m;
    std::set<std::vector<int>> T;
    for (int i = 0; i < m; ++i) {
        std::vector<int> p(n);
        for (int j = 0; j < n; ++j) {
            std::cin >> p[j];
            --p[j];
        }
        T.insert(p);
    }

    std::vector<int> st(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        st[i] = (int)a[i].size() - 1;
        sum += a[i][st[i]];
    }
    std::set<std::pair<int, std::vector<int>>> S;
    S.emplace(sum, st);
    while (1) {
        auto [s, p] = *(--S.end());
        S.erase(--S.end());
        if (!T.count(p)) {
            for (int i = 0; i < n; ++i) {
                std::cout << p[i] + 1 << " ";
            }
            std::cout << "\n";
            return 0;
        }
        for (int i = 0; i < n; ++i) {
            if (p[i] > 0) {
                auto q = p;
                --q[i];
                S.emplace(s - a[i][p[i]] + a[i][q[i]], q);
            }
        }
    }
}