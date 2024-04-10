#include<bits/stdc++.h>

using namespace std;

#define int long long

int const maxn = 1e5 + 5;
int a[maxn], b[maxn], pos[maxn];

void solve() {
    int n, m, ans = 0, R = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) pos[a[i]] = i;
    for (int j = 1; j <= m; ++j) cin >> b[j];
    for (int i = 1; i <= m; ++i) {
        if (pos[b[i]] > R) {
            ans += ((pos[b[i]] - i) * 2 + 1);
        }
        else ans++;
        R = max(R, pos[b[i]]);
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
    while (t--) solve();
    return 0;
}