#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

const int mod = 998244353;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int ans = n + 1;
    int c1 = count(begin(a), end(a), '1');
    int c2 = count(begin(b), end(b), '1');
    if(c1 == c2) {
        int cur = 0;
        for(int i = 0; i < n; i++) {
            cur += a[i] != b[i];
        }
        ans = min(ans, cur);
    }
    if(c2 == n - c1 + 1) {
        int cur = 0;
        for(int i = 0; i < n; i++) {
            cur += a[i] == b[i];
        }
        ans = min(ans, cur);
    }
    if(ans == n + 1) {
        cout << -1 << "\n";
    } else {
        cout << ans << "\n";
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
    return 0;
}