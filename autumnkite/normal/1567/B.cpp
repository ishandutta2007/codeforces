#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int N = 300000;
    std::vector<int> sum(N + 1);
    for (int i = 0; i < N; ++i) {
        sum[i + 1] = sum[i] ^ i;
    }

    int T;
    std::cin >> T;
    while (T--) {
        int a, b;
        std::cin >> a >> b;
        if (sum[a] == b) {
            std::cout << a << "\n";
        } else if (a != (sum[a] ^ b)) {
            std::cout << a + 1 << "\n";
        } else {
            std::cout << a + 2 << "\n";
        }
    }
}