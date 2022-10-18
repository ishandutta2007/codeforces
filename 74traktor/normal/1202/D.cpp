#include <bits/stdc++.h>

using namespace std;

int const maxn = 1e5;

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0 && i + n / i + 2 <= maxn) {
            for (int j = 1; j <= i; ++j) cout << 1;
            cout << 33;
            for (int j = 1; j <= n / i; ++j) cout << 7;
            cout << '\n';
            return;
        }
    }
    for (int x = 1; x <= 100000; ++x) {
        int a = (n - x);
        for (int j = 1; j * j <= a; ++j) {
            if (a % j == 0 && a / j > 6 * x) {
                int t = j, y = a / j - 6 * x;
                if (t + y + x + 5 <= maxn) {
                    for (int cur = 1; cur <= x; ++cur) {
                        cout << 1;
                    }
                    cout << 337;
                    for (int cur = 1; cur <= y; ++cur) cout << 1;
                    cout << 33;
                    for (int cur = 1; cur <= t; ++cur) cout << 7;
                    cout << '\n';
                    return;
                }
            }
        }
    }
    cout << 1 / 0 << endl;
    exit(0);
}

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}