#include<bits/stdc++.h>

using namespace std;

int const maxn = 55;
int a[maxn];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> a[i];
        string ans = "";
        for (int i = 1; i <= m; i++) ans += "B";
        for (int i = 1; i <= n; i++) {
            a[i] = min(a[i], m - a[i] + 1);
            if (ans[a[i] - 1] == 'B') ans[a[i] - 1] = 'A';
            else ans[m - a[i]] = 'A';
        }
        cout << ans << '\n';
    }
    return 0;
}