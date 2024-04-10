#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    int q;
    cin >> q;
    while (q--) {
        string s, t;
        cin >> s >> t;
        bool ok = false;
        for (int i = 0; i < (int)s.size(); ++i) {
            for (int len = 1; len <= (int) t.size() && i + len - 1 < (int)s.size(); ++len) {
                int cur = 0;
                bool tmp_ok = true;
                for (int j = 0; j < len; ++j) {
                    if (s[i + j] != t[cur]) {
                        tmp_ok = false;
                        break;
                    }
                    ++cur;
                }
                for (int j = i + len - 2; cur < (int)t.size() && j >= 0; --j) {
                    if (s[j] != t[cur]) {
                        tmp_ok = false;
                        break;
                    }
                    ++cur;
                }
                if (tmp_ok && cur == (int)t.size()) {
                    ok = true;
                    break;
                }
            }
            if (ok) break;
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
}