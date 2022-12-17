#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        long long ans = LLONG_MAX;
        int foo, bar;
        auto test = [&](int g) {
            if (g == n) return;
            if (1LL * g * (n / g - 1) < ans) {
                ans = 1LL * g * (n / g - 1);
                foo = g, bar = n - g;
            }
        };
        for (int d = 1; d * d <= n; d++) {
            if (n % d) continue;
            test(d), test(n / d);
        }
        cout << foo << " " << bar << "\n";
    }
    return 0;
}