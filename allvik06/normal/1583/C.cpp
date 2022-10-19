#include <bits/stdc++.h>

using namespace std;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n, m;
    cin >> n >> m;
    vector <string> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <int> ans(m);
    ans.back() = m - 1;
    for (int i = m - 2; i >= 0; --i) {
        bool ok = true;
        bool res = true;
        for (int j = 0; j < n; ++j) {
            if (!ok && a[j][i] == 'X') {
                res = false;
                break;
            }
            if (a[j][i + 1] == '.') ok = true;
            else ok = false;
        }
        if (res) ans[i] = ans[i + 1];
        else ans[i] = i;
    }
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y; --x; --y;
        if (ans[x] >= y) cout << "YES\n";
        else cout << "NO\n";
    }
}