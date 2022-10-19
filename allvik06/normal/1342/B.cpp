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
        string s;
        cin >> s;
        bool flag = true;
        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] != s[i + 1]) flag = false;
        }
        if (flag) {
            cout << s << "\n";
        }
        else {
            for (int i = 0; i < s.size() - 1; ++i) {
                if (s[i] == s[i + 1]) {
                    cout << s[i];
                    if (s[i] == '0') {
                        cout << '1';
                    }
                    else {
                        cout << '0';
                    }
                }
                else {
                    cout << s[i];
                }
            }
            cout << s[s.size() - 1];
            cout << "\n";
        }
    }
    return 0;
}