#include <bits/stdc++.h>

int calc(int x) {
    int res = 0;
    for (int i = 2; i * i <= x; ++i) {
        while (x % i == 0) {
            ++res;
            x /= i;
        }
    }
    return res + (x > 1);
}

void solve() {
    int a, b, k;
    std::cin >> a >> b >> k;
    if (k == 0) {
        if (a == b) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    } else if (k == 1) {
        if (a != b && (a % b == 0 || b % a == 0)) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    } else {
        if (k <= calc(a) + calc(b)) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
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