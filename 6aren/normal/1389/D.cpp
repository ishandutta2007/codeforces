#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

void solve() {
    int n, k;
    cin >> n >> k;
    int x, y, xx, yy;
    cin >> x >> y >> xx >> yy;
    int u = max(xx, x);
    int v = min(y, yy);
    if (u < v) k -= n * (v - u);
    if (k <= 0) {
        cout << 0 << '\n';
        return;
    }

    int to_inter = max(u - v, 0LL);
    int to_equal = max(y, yy) - min(x, xx);
    if (u < v) to_equal -= v - u;

    int ans = 1e18;
    for (int i = 1; i <= n; i++) {
        int temp = i * to_inter;
        int temp2 = to_equal * i;
        if (temp2 < k) temp += temp2 + (k - temp2) * 2;
        else temp += k;
        ans = min(ans, temp);
    }
    cout << ans << '\n';
    return;
}

main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        solve();
    }
    return 0;
}