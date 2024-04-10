#include <bits/stdc++.h>

using namespace std;

void solve() {
    string w;
    cin >> w;
    int p;
    cin >> p;
    vector<int> used(w.size(), 1);
    set<pair<int, int>> s;
    int sum = 0;
    for (int i = 0; i < (int)w.size(); ++i) {
        s.insert({w[i] - 'a' + 1, i});
        sum += w[i] - 'a' + 1;
    }
    while (sum > p) {
        sum -= s.rbegin()->first;
        used[s.rbegin()->second] = 0;
        s.erase(*s.rbegin());
    }
    for (int i = 0; i < (int)w.size(); ++i) {
        if (used[i]) {
            cout << w[i];
        }
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