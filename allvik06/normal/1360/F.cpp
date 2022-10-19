#include <bits/stdc++.h>

using namespace std;
#define int long long

bool check(vector <string> &a, string &b) {
    for (int i = 0; i < a.size(); ++i) {
        int kol = 0;
        for (int j = 0; j < b.size(); ++j) {
            if (b[j] != a[i][j]) ++kol;
        }
        if (kol > 1) return false;
    }
    return true;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector <string> a(n);
        for (string &i : a) cin >> i;
        string ans;
        for (int i = 0; i < m; ++i) {
            set <char> s;
            for (int j = 0; j < n; ++j) {
                s.insert(a[j][i]);
            }
            if (s.size() == 1) {
                ans += *s.begin();
                continue;
            }
            bool flag = false;
            for (char c : s) {
                for (int j = 0; j < n; ++j) {
                    string tmp = ans + c;
                    if (a[j][i] != c) {
                        for (int k = i + 1; k < m; ++k) {
                            tmp += a[j][k];
                        }
                        if (check(a, tmp)) {
                            ans = tmp;
                            flag = true;
                            break;
                        }
                    }
                }
                if (flag) break;
            }
            break;
        }
        if (ans.size() == m && check(a, ans)) cout << ans << "\n";
        else cout << -1 << "\n";
    }
}