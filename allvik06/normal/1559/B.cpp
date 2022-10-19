#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;

signed main() {
    if (0) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool ok = false;
        for (int i = 0; i < n; ++i) {
            if (s[i] != '?') {
                ok = true;
                for (int j = i - 1; j >= 0; --j) {
                    if (s[j] == '?') {
                        if (s[j + 1] == 'B') s[j] = 'R';
                        else s[j] = 'B';
                    }
                }
                for (int j = i + 1; j < n; ++j) {
                    if (s[j] == '?') {
                        if (s[j - 1] == 'B') s[j] = 'R';
                        else s[j] = 'B';
                    }
                }
                break;
            }
        }
        if (ok) {
            cout << s << "\n";
        } else {
            for (int i = 0; i < n; ++i) {
                if (i % 2 == 0) cout << "R";
                else cout << "B";
            }
            cout << "\n";
        }
    }
}