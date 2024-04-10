#include<bits/stdc++.h>

using namespace std;

int const maxn = 3505;
int a[maxn];
int inf = 1e9 + 1;

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
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        k = min(k, m - 1);
        int ans = 0;
        for (int i = 0; i <= k; ++i) {
            int cur = inf;
            for (int j = 0; j <= n; ++j) {
                if (j + k <= m - 1) {
                    cur = min(cur, max(a[i + j + 1], a[n - m + i + j + 1]));
                }
                else break;
            }
            ans = max(ans, cur);
        }
        cout << ans << '\n';
    }
    return 0;
}