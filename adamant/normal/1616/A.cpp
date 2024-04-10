#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    int a[n];
    map<int, int> cnt;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        cnt[-a[i]];
    }
    int ans = 0;
    for(auto it: cnt) {
        if(it.second) {
            ans += 1 + !cnt[-it.first] * (it.second >= 2);
        }
    }
    cout << ans << "\n";
    
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
    return 0;
}