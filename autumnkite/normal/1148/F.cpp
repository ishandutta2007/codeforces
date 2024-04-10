#include <bits/stdc++.h>

std::mt19937_64 rnd(std::chrono::system_clock::now()
                    .time_since_epoch().count());

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<unsigned long long> mask(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i] >> mask[i];
        sum += a[i];
    }

    if (sum < 0) {
        sum = -sum;
        for (int i = 0; i < n; ++i) {
            a[i] = -a[i];
        }
    }

    unsigned long long s = 0;
    for (int k = 61; k >= 0; --k) {
        long long nsum = 0;
        for (int i = 0; i < n; ++i) {
            if (mask[i] >> k & 1 && !(mask[i] & ((1ull << k) - 1))) {
                nsum += a[i];
            }
        }
        if (nsum > 0) {
            s |= 1ull << k;
            for (int i = 0; i < n; ++i) {
                if (mask[i] >> k & 1) {
                    a[i] = -a[i];
                    mask[i] ^= 1ull << k;
                }
            }
        }
    }
    std::cout << s << "\n";
}