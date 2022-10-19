#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector <bool> ans(n);
        int len = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                ++len;
            }
            else break;
        }
        int len1 = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '1') ++len1;
            else break;
        }
        if (len + len1 == n) cout << s << "\n";
        else {
            for (int i = 0; i < len; ++i) cout << 0;
            cout << 0;
            for (int i = 0; i < len1; ++i) cout << 1;
            cout << "\n";
        }
    }
}