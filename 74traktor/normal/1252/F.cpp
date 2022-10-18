#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 1e5 + 5;
vector < int > a[2];
int t[maxn], s[maxn];

void solve() {
    int n, ans = 0;
    cin >> n;
    a[0] = {}, a[1] = {};
    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        a[t[i]].push_back(s[i]);
        ans += s[i];
    }
    sort(a[0].rbegin(), a[0].rend());
    sort(a[1].rbegin(), a[1].rend());
    int d = min((int)a[0].size(), (int)a[1].size());
    if (2 * d == n) {
        cout << 2 * ans - min(a[0].back(), a[1].back()) << '\n';
    } else {
        for (int i = 0; i < d; i++) ans += a[0][i] + a[1][i];
        cout << ans << '\n';
    }
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}