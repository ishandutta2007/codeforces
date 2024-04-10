#include<bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int a, b, c, ans = 1e18;
    cin >> a >> b >> c;
    for (int f = a - 1; f <= a + 1; ++f) {
        for (int s = b - 1; s <= b + 1; ++s) {
            for (int t = c - 1; t <= c + 1; ++t) {
                ans = min(ans, abs(f - s) + abs(f - t) + abs(s - t));
            }
        }
    }
    cout << ans << '\n';
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}