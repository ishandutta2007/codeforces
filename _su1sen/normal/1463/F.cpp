#include <algorithm>
#include <iostream>
#include <vector>

bool kth_bit(int s, int i) {
    return (s >> i) & 1;
}

int main() {
    int n, x, y;
    std::cin >> n >> x >> y;
    if (x > y) std::swap(x, y);

    const int t = x + y;

    std::vector<int> pd(1 << y);
    
    for (int i = 0; i < t; ++i) {
        if (i >= n) break;
        std::vector<int> dp(1 << y);
        int num = (n - i - 1) / t + 1;
        for (int s = 0; s < 1 << y; ++s) {
            if (not (kth_bit(s, 0) or kth_bit(s, y - x))) {
                int ns = (s >> 1) | (1 << (y - 1));
               dp[ns] = std::max(dp[ns], pd[s] + num);
            }
            dp[s >> 1] = std::max(dp[s >> 1], pd[s]);
        }
        pd.swap(dp);
    }

    std::cout << *std::max_element(pd.begin(), pd.end()) << std::endl;
    return 0;
}