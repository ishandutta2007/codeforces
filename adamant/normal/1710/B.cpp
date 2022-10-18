#include <bits/stdc++.h>

using namespace std;

#define int int64_t

void solve() {
    int n, m;
    cin >> n >> m;
    int x[n], p[n];
    map<int, int> add;
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> p[i];
        add[x[i] - p[i]]++;
        add[x[i]] -= 2;
        add[x[i] + p[i]]++;
    }
    int sum = 0, ad = 0;
    int prev = 0;
    
    int mn = 1e18, mx = -1e18;
    for(auto [x, c]: add) {
        sum += ad * (x - prev);
        ad += c;
        prev = x;
        if(sum > m) {
            mn = min(mn, x - (sum - m));
            mx = max(mx, x + (sum - m));
        }
    }
    string ans(n, '1');
    if(mn < mx) {
        for(int i = 0; i < n; i++) {
            ans[i] = '0';
            if(x[i] - p[i] <= mn && mx <= x[i] + p[i]) {
                ans[i] = '1';
            }
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