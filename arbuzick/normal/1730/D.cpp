#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    map<pair<char, char>, int> count;
    for (int i = 0; i < n; ++i) {
        count[{min(s1[i], s2[n - i - 1]), max(s1[i], s2[n - i - 1])}]++;
    }
    bool fl = false;
    for (auto [letters, cnt] : count) {
        if (cnt % 2) {
            if (fl || letters.first != letters.second) {
                cout << "NO\n";
                return;
            }
            fl = true;
        }
    }
    cout << "YES\n";
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