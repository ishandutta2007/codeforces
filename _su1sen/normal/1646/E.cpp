#include <iostream>
#include <numeric>
#include <vector>

constexpr uint32_t L = 20;

int main() {
    uint32_t n, m;
    std::cin >> n >> m;

    std::vector<uint32_t> d(n + 1, 0), b(n + 1, 0), l(n + 1, 0);
    for (uint32_t i = 2; i <= n; ++i) {
        for (uint64_t pow_i = i; pow_i <= n; pow_i *= i) {
            ++l[i];
            if (d[pow_i] < l[i]) {
                d[pow_i] = l[i];
                b[pow_i] = i;
            }
        }
    }
    
    std::vector f(L, std::vector<uint32_t>(L, 0));
    for (uint32_t d = 1; d < L; ++d) {
        std::vector<uint8_t> erased(m + 1, false);
        for (uint32_t c = d + 1; c < L; ++c) {
            f[d][c] = f[d][c - 1];
            uint32_t k = c / std::gcd(c, d);
            for (uint32_t j = k; j <= m; j += k) {
                if (erased[j]) continue;
                f[d][c] += erased[j] = true;
            }
        }
    }

    uint64_t ans = 1;
    for (uint32_t i = 2; i <= n; ++i) {
        ans += m - f[d[i]][l[b[i]]];
    }
    std::cout << ans << std::endl;
    return 0;
}