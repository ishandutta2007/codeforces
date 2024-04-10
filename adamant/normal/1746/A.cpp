#include <bits/stdc++.h>

using namespace std;

#define int int64_t

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n];
    bool ok = false;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        ok |= a[i];
    }
    cout << (ok ? "yes" : "no") << "\n";
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    cerr << clock() / double(CLOCKS_PER_SEC) << endl;
    //return 0;
}