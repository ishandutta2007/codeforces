#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 1e5 + 42;
const int mod = 998244353;

void solve() {
    int n, x;
    cin >> n >> x;
    int a[n];
    int inf = 2e9;
    int mx = inf;
    int mn = -inf;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mx = min(mx, a[i] + x);
        mn = max(mn, a[i] - x);
        if(mn > mx) {
            ans++;
            mx = a[i] + x, mn = a[i] - x;
        }
    }
    cout << ans << "\n";
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
}