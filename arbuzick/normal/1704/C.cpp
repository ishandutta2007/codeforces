#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        a[i]--;
    }
    sort(a.begin(), a.end());
    vector<int> kek;
    for (int i = 0; i < m; ++i) {
        if (i == m - 1) {
            kek.push_back(a[0] + n - a[i] - 1);
        } else {
            kek.push_back(a[i + 1] - a[i] - 1);
        }
    }
    sort(kek.rbegin(), kek.rend());
    int tm = 0;
    int ans = m;
    for (int i = 0; i < (int)kek.size(); ++i) {
        ans += min(tm * 2, kek[i]);
        if (kek[i] > tm * 2) {
            tm++;
            if (kek[i] > (tm - 1) * 2 + 1) {
                ans++;
                tm++;
            }
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