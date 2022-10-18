#include <bits/stdc++.h>

#define int int64_t

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    int ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        ans += (a[i] + 1) % 2;
    }
    cout << (ans % 2 ? "errorgorn" : "maomao90") << "\n";
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
}