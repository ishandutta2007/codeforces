#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 1e5 + 42;

void solve() {
    int n;
    cin >> n;
    int a[n];
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt += a[i] % 2;
    }
    cout << min(cnt, n - cnt) << "\n";
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