#include<bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int a, b, ans = 0, t = 1;
    cin >> a >> b;
    if (a > b) swap(a, b);
    while (a < b) {
        a += t, t++, ans++;
    }
    if ((a - b) % 2 == 0) {
        cout << ans << '\n';
        return;
    }
    if ((a + t - b) % 2 == 1) {
        cout << ans + 2 << '\n';
    }
    else cout << ans + 1 << '\n';
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
    while (t--) solve();
    return 0;
}