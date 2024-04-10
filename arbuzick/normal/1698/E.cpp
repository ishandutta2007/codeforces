#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n), pos_a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
        pos_a[a[i]] = i;
    }
    vector<int> b(n), pos_b(n, -1);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        if (b[i] != -1) {
            b[i]--;
            pos_b[b[i]] = i;
        }
    }
    int ans = 1;
    int nw = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] < s && b[i] == -1) {
            nw++;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i + s < n && b[pos_a[i + s]] == -1) {
            nw++;
        }
        if (pos_b[i] != -1) {
            if (a[pos_b[i]] > i + s) {
                cout << 0 << '\n';
                return;
            }
        } else {
            ans = ans * 1LL * nw % mod;
            nw--;
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