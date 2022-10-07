#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int n;
    long long k, x;
    std::cin >> n >> k >> x;
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());

    std::vector<long long> b(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        b[i] = std::max(0ll, (a[i + 1] - a[i] - 1) / x);
    }
    std::sort(b.begin(), b.end());

    int ans = n;
    for (auto x : b) {
        if (k >= x) {
            k -= x;
            --ans;
        } else {
            break;
        }
    }
    std::cout << ans << "\n";
}