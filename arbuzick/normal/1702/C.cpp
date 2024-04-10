#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    map<int, int> frst, lst;
    for (int i = 0; i < n; ++i) {
        int u;
        cin >> u;
        if (!frst.count(u)) {
            frst[u] = i;
        }
        lst[u] = i;
    }
    while (k--) {
        int a, b;
        cin >> a >> b;
        if (!frst.count(a) || !lst.count(b) || frst[a] > lst[b]) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
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