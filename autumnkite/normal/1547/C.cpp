#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin >> T;
    while (T--) {
        int x, n, m;
        std::cin >> x >> n >> m;
        std::vector<int> a(n), b(m);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        for (int i = 0; i < m; ++i) {
            std::cin >> b[i];
        }
        std::vector<int> res(n + m);
        auto i = a.begin(), j = b.begin(), k = res.begin();
        while (i != a.end() && j != b.end()) {
            if (*i < *j) {
                *(k++) = *(i++);
            } else {
                *(k++) = *(j++);
            }
        }
        std::copy(i, a.end(), std::copy(j, b.end(), k));
        bool ok = true;
        for (int i = 0; i < n + m; ++i) {
            if (res[i] == 0) {
                ++x;
            } else if (res[i] > x) {
                std::cout << -1 << "\n";
                ok = false;
                break;
            }
        }
        if (ok) {
            for (int i = 0; i < n + m; ++i) {
                std::cout << res[i] << " ";
            }
            std::cout << "\n";
        }
    }
}