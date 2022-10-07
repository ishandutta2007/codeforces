#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int n, q;
    std::cin >> n >> q;
    std::vector<int> sum(n + 1);
    for (int i = 0; i < n; ++i) {
        char c;
        std::cin >> c;
        sum[i + 1] = sum[i] + (c - 'a' + 1);
    }
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        --l;
        std::cout << sum[r] - sum[l] << "\n";
    }
}