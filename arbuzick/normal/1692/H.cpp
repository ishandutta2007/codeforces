#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    int a = x[0], l = 0, r = 1, bal = 1;
    vector<int> pos(n);
    map<int, int> count;
    map<int, pair<int, int>> val;
    for (int i = 0; i < n; ++i) {
        pos[i] = count[x[i]]++;
        val[x[i]] = {-1, -1};
    }
    // bal = (pos_r - pos_l + 1) * 2 - (i_r - i_l + 1);
    // -pos_l * 2 + i_l
    for (int i = 0; i < n; ++i) {
        if (val[x[i]].first != -1) {
            if (bal < pos[i] * 2 + 1 - i + val[x[i]].first) {
                bal = pos[i] * 2 + 1 - i + val[x[i]].first;
                l = val[x[i]].second;
                r = i + 1;
                a = x[i];
            }
        }
        val[x[i]] = max(val[x[i]], {-pos[i] * 2 + i, i});
    }
    cout << a << ' ' << l + 1 << ' ' << r << '\n';
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