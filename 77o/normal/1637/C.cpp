#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    ll ans = 0;
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i && i + 1 < n) {
            ans += (a[i] + 1) / 2;
            cnt1 += a[i] == 1;
        }
    }
    if (n == 3 && a[1] % 2 || cnt1 == n - 2)
        cout << "-1\n";
    else
        cout << ans << '\n';
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