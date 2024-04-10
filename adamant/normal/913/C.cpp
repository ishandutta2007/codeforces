#include <bits/stdc++.h>

using namespace std;

#define int int64_t

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, l;
    cin >> n >> l;
    const int logn = 31, inf = 1e18;
    int c[logn];
    for(int i = 0; i < logn; i++) {
        c[i] = inf;
    }
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for(int i = 1; i < logn; i++) {
        c[i] = min(c[i], 2 * c[i - 1]);
    }
    for(int i = logn - 1; i; i--) {
        c[i - 1] = min(c[i - 1], c[i]);
    }
    int ans = 0;
    for(int i = 0; i < logn; i++) {
        if((l >> i) & 1) {
            ans += c[i];
        } else {
            ans = min(ans, c[i]);
        }
    }
    cout << ans << endl;
    return 0;
}