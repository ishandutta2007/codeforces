#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        sum += a[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
        sum -= b[i];
    }
    if (sum != 0) {
        std::cout << -1 << "\n";
        return;
    }
    std::vector<std::pair<int, int>> pp, pn;
    for (int i = 0; i < n; ++i) {
        if (a[i] < b[i]) {
            pp.emplace_back(i, b[i] - a[i]);
            sum += b[i] - a[i];
        } else if (a[i] > b[i]) {
            pn.emplace_back(i, a[i] - b[i]);
        }
    }
    std::cout << sum << "\n";
    for (int i = 0; i < sum; ++i) {
        --pp.back().second;
        --pn.back().second;
        std::cout << pn.back().first + 1 << " " << pp.back().first + 1 << "\n";
        if (!pp.back().second) {
            pp.pop_back();
        }
        if (!pn.back().second) {
            pn.pop_back();
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}