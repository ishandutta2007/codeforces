#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++) {
            if (s[i] == '?' && (i > 0 && s[i - 1] != '?')) {
                if (s[i - 1] == 'B') s[i] = 'R';
                else s[i] = 'B';
            }
        }
        // cout << s << endl;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '?' && (i < n - 1 && s[i + 1] != '?')) {
                if (s[i + 1] == 'B') s[i] = 'R';
                else s[i] = 'B';
            }
        }
        if (s[0] == '?') {
            for (int i = 0; i < n; i += 2) s[i] = 'B';
            for (int i = 1; i < n; i += 2) s[i] = 'R';
        }
        cout << s << '\n';
    }

    return 0;
}