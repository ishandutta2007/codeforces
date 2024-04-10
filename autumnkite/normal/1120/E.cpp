#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    typedef std::pair<int, int> state;

    auto ID = [&](const state &rhs) {
        return (rhs.first + n) * n + rhs.second;
    };

    std::vector lst((2 * n + 1) * n, std::pair(-1, -1));

    std::vector<state> Q;
    Q.emplace_back(0, 0);
    for (int k = 0; k < (int)Q.size(); ++k) {
        auto [s, d] = Q[k];
        if (s == 0 && d == 0 && lst[ID(state(s, d))] != std::pair(-1, -1)) {
            std::string ans;
            do {
                auto [st, w] = lst[ID(state(s, d))];
                auto nd = st % n, ns = st / n - n;
                if (!ans.empty() || w) {
                    ans.push_back(w + '0');
                }
                s = ns, d = nd;
            } while (s || d);
            std::cout << ans << "\n";
            return 0;
        }
        for (int i = (k == 0); i < 10; ++i) {
            auto ns = s + ((i * n + d) % 10) * n - i;
            auto nd = (i * n + d) / 10;
            if (-n <= ns && ns <= n
                && lst[ID(state(ns, nd))] == std::pair(-1, -1)) {
                lst[ID(state(ns, nd))] = std::pair(ID(state(s, d)), i);
                Q.push_back(state(ns, nd));
            }
        }
    }
    std::cout << -1 << "\n";
}