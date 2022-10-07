#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    int mx = *std::max_element(a.begin(), a.end());
    long long sum = std::accumulate(a.begin(), a.end(), 0ll) - mx;
    std::cout << mx + 1.0 * sum / (n - 1) << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cout.setf(std::ios::fixed);
    std::cout.precision(12);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}