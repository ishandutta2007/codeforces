#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        int lst = 0;
        for (int i = 0; i < n; ++i) {
            int v = 0;
            for (int j = 0; j < 30; ++j) {
                if (lst >> j & 1 && !(a[i] >> j & 1)) {
                    v |= 1 << j;
                }
            }
            std::cout << v << " ";
            lst = a[i] ^ v;
        }
        std::cout << "\n";
    }
}