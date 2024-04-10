#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ans += a[i];
    }
    multiset<int> ms;
    for (int i = 0; i < n; ++i) {
        ms.insert(-a[i] + (n - i - 1));
    }
    ans -= k * 1LL * (k - 1) / 2;
    while (k > 0) {
        ans += *ms.begin();
        ms.erase(ms.begin());
        k--;
    }
    cout << ans << '\n';
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