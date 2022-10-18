#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int t = 0; t <= 9; ++t) {
        vector < int > a, b;
        int f = 1;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] - '0' < t) a.push_back(s[i] - '0'), f = 0;
            else if (s[i] - '0' > t) b.push_back(s[i] - '0');
            else {
                if (f) a.push_back(s[i] - '0');
                else b.push_back(s[i] - '0');
            }
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int lst = 0;
        int ok = 1;
        for (auto key : a) {
            if (key < lst) ok = 0;
            lst = key;
        }
        lst = 0;
        for (auto key : b) {
            if (key < lst) ok = 0;
            lst = key;
        }
        if (ok) {
            vector < int > ans;
            f = 1;
            for (int i = n - 1; i >= 0; --i) {
                if (s[i] - '0' < t) ans.push_back(1), f = 0;
                else if (s[i] - '0' > t) ans.push_back(2);
                else {
                    if (f) ans.push_back(1);
                    else ans.push_back(2);
                }
            }
            reverse(ans.begin(), ans.end());
            for (auto key : ans) cout << key;
            cout << '\n';
            return;
        }
    }
    cout << '-' << '\n';
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}