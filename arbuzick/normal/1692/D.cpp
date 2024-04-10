#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int x;
    cin >> x;
    set<int> used;
    int ans = 0;
    int tm = ((s[0] - '0') * 10 + (s[1] - '0')) * 60 + (s[3] - '0') * 10 + (s[4] - '0');
    while (!used.count(tm)) {
        used.insert(tm);
        int hours = tm / 60, minutes = tm % 60;
        if (hours / 10 == minutes % 10 && hours % 10 == minutes / 10) {
            ans++;
        }
        tm += x;
        tm %= 1440;
    }
    cout << ans << '\n';
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