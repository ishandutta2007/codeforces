#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    n *= 2;
    vector<int> pr(n + 1);
    int l = -1, r = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            pr[i + 1] = pr[i] + 1;
        } else {
            pr[i + 1] = pr[i] - 1;
        }
        if (pr[i + 1] < 0) {
            r = i;
            if (l == -1) {
                l = i;
            }
        }
    }
    if (l == -1) {
        cout << "0\n";
        return;
    }
    r++;
    int pos_pr_mx_l = 0, pos_pr_mx_m = l + 1;
    for (int i = 0; i < l; ++i) {
        if (pr[i + 1] > pr[pos_pr_mx_l]) {
            pos_pr_mx_l = i + 1;
        }
    }
    for (int i = l; i < r; ++i) {
        if (pr[i + 1] > pr[pos_pr_mx_m]) {
            pos_pr_mx_m = i + 1;
        }
    }
    for (int i = r; i <= n; ++i) {
        if (pr[i] >= 0 && pr[i] + pr[pos_pr_mx_l] - pr[pos_pr_mx_m] >= 0) {
            cout << "1\n";
            cout << pos_pr_mx_l + 1 << ' ' << i << '\n';
            return;
        }
        if (pr[i] > pr[pos_pr_mx_m]) {
            pos_pr_mx_m = i;
        }
    }
    int pos_mx = 0;
    for (int i = 0; i < n; ++i) {
        if (pr[i + 1] > pr[pos_mx]) {
            pos_mx = i + 1;
        }
    }
    cout << "2\n";
    cout << 1 << ' ' << pos_mx << '\n';
    cout << pos_mx + 1 << ' ' << n << '\n';
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