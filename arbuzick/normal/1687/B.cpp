#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a;
    for (int i = 0; i < m; ++i) {
        string s(m, '0');
        s[i] = '1';
        cout << "? " << s << endl;
        int val;
        cin >> val;
        a.emplace_back(val, i);
    }
    sort(a.begin(), a.end());
    int ans = 0;
    string nw(m, '0');
    for (int i = 0; i < m; ++i) {
        nw[a[i].second] = '1';
        cout << "? " << nw << endl;
        int val;
        cin >> val;
        if (val != ans + a[i].first) {
            nw[a[i].second] = '0';
        } else {
            ans += a[i].first;
        }
    }
    cout << "! " << ans << endl;
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