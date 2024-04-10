#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    cin >> q;
    vector<vector<int>> val(1 << 17, vector<int>(18)), pow(18, vector<int>(n + 1));
    for (int i = 0; i < 18; ++i) {
        pow[i][0] = 1;
        for (int j = 1; j <= n; ++j) {
            pow[i][j] = pow[i][j - 1] * 1LL * i % mod;
        }
    }
    vector<int> ans(1 << 17);
    int count = 0;
    for (auto ch : s) {
        if (ch == '?') {
            count++;
        }
    }
    for (int md = 0; md < n; ++md) {
        int count1 = 0;
        int count2 = 0;
        int mask = 0;
        for (int l = md; l >= 0 && md + md - l < n; --l) {
            int r = md + md - l;
            if (s[l] == '?' && s[r] == '?') {
                count2++;
                count1 += 1;
                if (l != r) {
                    count1++;
                }
            } else if (s[l] != '?' && s[r] != '?') {
                if (s[l] != s[r]) {
                    break;
                }
            } else if (s[l] != '?') {
                count1++;
                mask |= (1 << (s[l] - 'a'));
            } else {
                count1++;
                mask |= (1 << (s[r] - 'a'));
            }
            for (int i = 0; i < 18; ++i) {
                val[mask][i] = (val[mask][i] + pow[i][count - count1 + count2]) % mod;
            }
        }
    }
    for (int md = 0; md + 1 < n; ++md) {
        int count1 = 0;
        int count2 = 0;
        int mask = 0;
        for (int l = md; l >= 0 && md + md - l + 1 < n; --l) {
            int r = md + md - l + 1;
            if (s[l] == '?' && s[r] == '?') {
                count2++;
                count1 += 2;
            } else if (s[l] != '?' && s[r] != '?') {
                if (s[l] != s[r]) {
                    break;
                }
            } else if (s[l] != '?') {
                count1++;
                mask |= (1 << (s[l] - 'a'));
            } else {
                count1++;
                mask |= (1 << (s[r] - 'a'));
            }
            for (int i = 0; i < 18; ++i) {
                val[mask][i] = (val[mask][i] + pow[i][count - count1 + count2]) % mod;
            }
        }
    }
    for (int mask = 1; mask < (1 << 17); ++mask) {
        int cnt = 0;
        for (int i = 0; i < 17; ++i) {
            if (mask & (1 << i)) {
                cnt++;
            }
        }
        for (int vl = mask;; vl = (vl - 1) & mask) {
            ans[mask] += val[vl][cnt];
            ans[mask] %= mod;
            if (vl == 0) {
                break;
            }
        }
    }
    while (q--) {
        string t;
        cin >> t;
        int mask = 0;
        for (auto ch : t) {
            mask |= (1 << (ch - 'a'));
        }
        cout << ans[mask] << '\n';
    }
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