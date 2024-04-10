#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    a.back() = n;
    for (int i = n - 1; i >= 1; --i) {
        std::cout << "? ";
        for (int j = 1; j < n; ++j) {
            std::cout << n << " ";
        }
        std::cout << i << std::endl;
        int x;
        std::cin >> x;
        if (!x) {
            a.back() = n - i;
            break;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (i != a.back()) {
            std::cout << "? ";
            for (int j = 1; j < n; ++j) {
                std::cout << a.back() << " ";
            }
            std::cout << i << std::endl;
            int x;
            std::cin >> x;
            a[x - 1] = i;
        }
    }
    std::cout << "! ";
    for (int x : a) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}