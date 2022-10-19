#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    int total = 0;
    ll sq = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sq += (n - 2) * a[i] * a[i];
        total += a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        sq += (n - 2) * b[i] * b[i];
        total += b[i];
    }
    const int N = 1e4 + 1;
    bitset<N> dp;
    dp.set(0);
    for (int i = 0; i < n; i++) {
        bitset<N> ndp;
        ndp |= dp << a[i];
        ndp |= dp << b[i];
        dp = move(ndp);
    }
    for (int i = total / 2; i >= 0; i--) {
        if (dp[i]) {
            ll x = i;
            ll y = total - i;
            cout << sq + x * x + y * y << '\n';
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}