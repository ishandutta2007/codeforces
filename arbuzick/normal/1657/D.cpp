#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, C;
    cin >> n >> C;
    vector<long long> mx(C + 1);
    for (int i = 0; i < n; ++i) {
        int c, d, h;
        cin >> c >> d >> h;
        mx[c] = max(mx[c], d * 1LL * h);
    }
    for (int i = 1; i <= C; ++i) {
        mx[i] = max(mx[i], mx[i - 1]);
        for (int j = i; j <= C; j += i) {
            mx[j] = max(mx[j], mx[i] * (j / i));
        }
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        long long d, h;
        cin >> d >> h;
        int ans = upper_bound(mx.begin(), mx.end(), d * h) - mx.begin();
        if (ans == C + 1) {
            cout << -1 << ' ';
        } else {
            cout << ans << ' ';
        }
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}