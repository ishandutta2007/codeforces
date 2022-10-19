#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int l = 0, r = n;
    while (l < r - 1) {
        int m = (l + r) / 2;
        cout << "? " << l + 1 << ' ' << m << endl;
        vector<int> a(m - l);
        for (int i = 0; i < m - l; ++i) {
            cin >> a[i];
            a[i]--;
        }
        int count = 0;
        for (auto ind : a) {
            if (l <= ind && ind < m) {
                count++;
            }
        }
        if (count % 2) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << "! " << l + 1 << endl;
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