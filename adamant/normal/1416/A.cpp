#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    map<int, vector<int>> occs;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        occs[a[i]].push_back(i);
    }
    int res[n + 1];
    memset(res, -1, sizeof(res));
    for(auto it: occs) {
        it.second.insert(begin(it.second), -1);
        it.second.push_back(n);
        int mn = 0;
        for(int i = 1; i < it.second.size(); i++) {
            mn = max(mn, it.second[i] - it.second[i - 1]);
        }
        if(res[mn] == -1) {
            res[mn] = it.first;
        } else {
            res[mn] = min(res[mn], it.first);
        }
    }
    for(int i = 1; i <= n; i++) {
        if(res[i - 1] != -1 && (res[i] == -1 || res[i] > res[i - 1])) {
            res[i] = res[i - 1];
        }
        cout << res[i] << ' ';
    }
    cout << "\n";
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}