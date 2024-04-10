#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<int> f(n + 1);
    for (int i = 2; i <= n; ++i) {
        int cnt = 0, x = i;
        while (x % 2 == 0) {
            cnt++;
            x /= 2;
        }
        f[i] = f[i - 1] + cnt;
    }
    vector<vector<int>> c(min(40, n), vector<int>(n)), pr(min(40, n), vector<int>(n + 1));
    for (int i = 0; i < c.size(); ++i) {
        for (int j = 0; j < (int)c[i].size(); ++j) {
            if (i + j <= n - 1 && f[n - 1 - i] - f[j] - f[n - 1 - i - j] == 0) {
                c[i][j] = 1;
            }
            pr[i][j + 1] = pr[i][j] + c[i][j];
        }
    }
    vector<int> ans(1 << 20);
    for (int i = 0; i < n; ++i) {
        long long nw = b[i];
        for (int len = 1; len <= 20 && i + len <= n; ++len) {
            if (nw >= (1 << 20)) {
                break;
            }
            int used = len - 1, kek = k;
            if (i > 0) {
                used++;
                kek--;
            }
            if (i + len < n) {
                used++;
                kek--;
            }
            if ((pr[used][n] - pr[used][max(0, kek)]) % 2 == 1) {
                ans[nw] ^= 1;
            }
            if (len < 20 && i + len + 1 <= n) {
                if (b[i + len] > 20) {
                    break;
                }
                int x = (1 << b[i + len]);
                nw *= x;
            }
        }
    }
    bool st = false;
    for (int i = (1 << 20) - 1; i >= 0; --i) {
        if (ans[i]) {
            st = true;
            cout << 1;
        } else if (st) {
            cout << 0;
        }
    }
    if (!st) {
        cout << 0;
    }
    cout << '\n';
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