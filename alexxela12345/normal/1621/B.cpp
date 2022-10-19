#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

const int INF = 1e9 + 228;

void solve() {
    int n;
    cin >> n;
    array<int, 2> mn = {INF, 0};
    array<int, 2> mx = {-INF, 0};
    array<int, 3> biggest = {INF, -INF, 0};
    while (n--) {
        int l, r, c;
        cin >> l >> r >> c;
        array<int, 2> a, b;
        a = {l, c};
        mn = min(mn, a);
        b = {r, -c};
        mx = max(mx, b);
        if (r - l > biggest[1] - biggest[0]) {
            biggest = {l, r, c};
        } else if (r - l == biggest[1] - biggest[0]) {
            biggest[2] = min(biggest[2], c);
        }
        int ans = mn[1] - mx[1];
        if (mx[0] - mn[0] == biggest[1] - biggest[0]) {
            ans = min(ans, biggest[2]);
        }
        cout << ans << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}