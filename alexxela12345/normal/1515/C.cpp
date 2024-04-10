#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

void solve() {
    int n, m, x;
    cin >> n >> m >> x;
    set<pair<int, int>> s;
    for (int i = 0; i < m; i++) {
        s.insert({0, i});
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        auto pp = *s.begin();
        s.erase(s.begin());
        ans[i] = pp.second + 1;
        pp.first += a;
        s.insert(pp);
    }
    cout << "YES" << endl;
    for (int el : ans) {
        cout << el << " ";
    }
    cout << endl;
}

signed main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}