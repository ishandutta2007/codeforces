#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 1e5 + 42;

void solve() {
    int n;
    cin >> n;
    int a[n];
    map<int, vector<int>> pos;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    int ans[n];
    for(auto [val, it]: pos) {
        if(it.size() == 1) {
            cout << -1 << "\n";
            return;
        }
        for(size_t i = 1; i < it.size(); i++) {
            ans[it[i - 1]] = it[i];
        }
        ans[it.back()] = it[0];
    }
    for(auto it: ans) {
        cout << it + 1 << ' ';
    }
    cout << "\n";
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    cerr << "Time: " << clock() / double(CLOCKS_PER_SEC) << endl;
}