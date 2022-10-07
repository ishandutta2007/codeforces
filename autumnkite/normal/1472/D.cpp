#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end(), std::greater<int>());
    long long sum = 0;
    for (int i = 0; i < n; i += 2) {
        if (!(a[i] & 1)) {
            sum += a[i];
        }
    }
    for (int i = 1; i < n; i += 2) {
        if (a[i] & 1) {
            sum -= a[i];
        }
    }
    if (sum == 0) {
        std::cout << "Tie\n";
    } else if (sum > 0) {
        std::cout << "Alice\n";
    } else {
        std::cout << "Bob\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}