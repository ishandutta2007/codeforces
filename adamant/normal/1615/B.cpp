#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

const int mod = 998244353;

int cnt(int a, int b) {
    int k = a / (2 * b);
    return k * b + min((a % (2 * b)), b);
}

void solve() {
    int l, r;
    cin >> l >> r;
    int ans = r - l + 1;
    for(int i = 0; i < 22; i++) {
        int t = 1 << i;
        ans = min(ans, cnt(r + 1, t) - cnt(l, t));
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