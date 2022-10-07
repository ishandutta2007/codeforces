#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin >> T;
    while (T--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<int> pos(m);
        for (int i = 0; i < m; ++i) {
            std::cin >> pos[i];
            --pos[i];
        }
        std::vector<int> a(n, INF);
        for (int i = 0; i < m; ++i) {
            std::cin >> a[pos[i]];
        }
        for (int i = 1; i < n; ++i) {
            a[i] = std::min(a[i], a[i - 1] + 1);
        }
        for (int i = n - 2; i >= 0; --i) {
            a[i] = std::min(a[i], a[i + 1] + 1);
        }
        for (int i = 0; i < n; ++i) {
            std::cout << a[i] << " ";
        }
        std::cout << "\n";
    }
}