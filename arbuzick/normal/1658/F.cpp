#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> pr(n + 1);
    for (int i = 0; i < n; ++i) {
        pr[i + 1] = pr[i] + s[i] - '0';
    }
    if (pr[n] * 1LL * m % n != 0) {
        cout << -1 << '\n';
        return;
    }
    for (int i = 0; i + m <= n; ++i) {
        if (pr[i + m] - pr[i] == pr[n] * 1LL * m / n) {
            cout << 1 << '\n';
            cout << i + 1 << ' ' << i + m << '\n';
            return;
        }
    }
    for (int i = 0; i + n - m <= n; ++i) {
        if (pr[n] - (pr[i + n - m] - pr[i]) == pr[n] * 1LL * m / n) {
            cout << 2 << '\n';
            cout << 1 << ' ' << i << '\n';
            cout << i + n - m + 1 << ' ' << n << '\n';
            return;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}