#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int l = -1, r = n;
    while (l < r - 1) {
        int m = (l + r) / 2;
        vector<int> pr(n + 1);
        for (int i = 0; i < n; ++i) {
            pr[i + 1] = pr[i] + s[i] - '0';
        }
        int p = 0;
        bool ch = false;
        for (int i = 0; i < n; ++i) {
            while ((i + 1 - p) - (pr[i + 1] - pr[p]) > m) {
                p++;
            }
            if (pr[n] - (pr[i + 1] - pr[p]) <= m) {
                ch = true;
                break;
            }
        }
        if (ch) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << '\n';
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