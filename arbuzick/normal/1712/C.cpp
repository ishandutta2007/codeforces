#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), s(n, -1), f(n, n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
        if (s[a[i]] == -1) {
            s[a[i]] = i;
        }
        f[a[i]] = i;
    }
    int pos = n - 1;
    for (int i = n - 2; i >= 0; --i) {
        if (a[i] > a[i + 1]) {
            break;
        }
        pos = i;
    }
    if (pos == 0) {
        cout << 0 << '\n';
        return;
    }
    int cnt_nw = 0, cnt_col = 0;
    for (int i = 0; i < n; ++i) {
        if (s[a[i]] == i) {
            cnt_nw++;
            cnt_col++;
        }
        if (f[a[i]] == i) {
            cnt_nw--;
        }
        if (cnt_nw == 0 && pos <= i + 1) {
            cout << cnt_col << '\n';
            return;
        }
    }
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