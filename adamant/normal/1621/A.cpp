#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

const int inf = 1e9;
const int maxn = 1e5 + 42;

void solve() {
    int n, k;
    cin >> n >> k;
    if(k * 2 - 1 > n) {
        cout << -1 << "\n";
    } else {
        string ans[n];
        for(int i = 0; i < n; i++) {
            ans[i] = string(n, '.');
            if(i % 2 == 0 && k) {
                k--;
                ans[i][i] = 'R';
            }
            cout << ans[i] << "\n";
        }
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