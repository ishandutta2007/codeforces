#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    set<string> used;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        used.insert(s[i]);
    }
    for (int i = 0; i < n; ++i) {
        bool ch = false;
        string pr = "", suf = s[i];
        while (!suf.empty()) {
            pr += suf[0];
            suf = suf.substr(1);
            if (used.count(pr) && used.count(suf)) {
                ch = true;
            }
        }
        cout << ch;
    }
    cout << '\n';
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