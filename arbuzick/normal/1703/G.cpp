#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long ans = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }
    ans = max(ans, sum - k * 1LL * n);
    vector<int> nw;
    for (int i = n - 1; i >= 0; --i) {
        nw.push_back(a[i]);
        vector<int> nw2;
        for (auto v : nw) {
            sum -= (v - v / 2);
            if (v / 2 > 0) {
                nw2.push_back(v / 2);
            }
        }
        nw = nw2;
        ans = max(ans, sum - k * 1LL * i);
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