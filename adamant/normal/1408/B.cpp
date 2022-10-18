#include <bits/stdc++.h>

using namespace std;

#define int int64_t
const int maxn = 2e5 + 42;

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n];
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt += (i > 0 && a[i] > a[i - 1]);
    }
    cnt += 1;
    if(cnt == 1) {
        cout << (a[0] ? 1 : 0) << "\n";
    } else if(k == 1) {
        cout << -1 << "\n";
    } else {
        cout << (cnt - 1 + k - 2) / (k - 1) << "\n";
    }
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