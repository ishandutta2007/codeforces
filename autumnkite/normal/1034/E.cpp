#include <bits/stdc++.h>

template<typename T>
void FWT(int n, std::vector<T> &f, int op) {
    for (int i = 0; i < n; ++i) {
        for (int S = 0; S < (1 << n); ++S) {
            if (S >> i & 1) {
                if (op == 1) {
                    f[S] += f[S ^ (1 << i)];
                } else if (op == -1) {
                    f[S] -= f[S ^ (1 << i)];
                }
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    using ull = unsigned long long;
    std::vector<ull> a(1 << n);
    for (int i = 0; i < (1 << n); ++i) {
        char c;
        std::cin >> c;
        a[i] = 1ull * (c - '0') << (__builtin_popcount(i) << 1);
    }
    std::vector<ull> b(1 << n);
    for (int i = 0; i < (1 << n); ++i) {
        char c;
        std::cin >> c;
        b[i] = 1ull * (c - '0') << (__builtin_popcount(i) << 1);
    }

    FWT(n, a, 1);
    FWT(n, b, 1);
    for (int i = 0; i < (1 << n); ++i) {
        a[i] *= b[i];
    }
    FWT(n, a, -1);
    for (int i = 0; i < (1 << n); ++i) {
        a[i] >>= __builtin_popcount(i) << 1;
        std::cout << a[i] % 4;
    }
    std::cout << "\n";
}