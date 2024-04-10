#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
        if (a[i] < i) {
            b.push_back(a[i]);
        }
    }
    sort(b.begin(), b.end());
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] < i) {
            ans += (int)b.size() - (upper_bound(b.begin(), b.end(), i) - b.begin());
        }
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