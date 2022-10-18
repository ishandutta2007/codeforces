#include<bits/stdc++.h>

using namespace std;

int const maxn = 1e5 + 5;
int a[maxn];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        int ans = n;
        for (int j = 1; j <= 100; ++j) {
            int cur = 0;
            for (int i = 1; i <= n;) {
                if (a[i] != j) {
                    i += k;
                    cur++;
                }
                else i++;
            }
            ans = min(ans, cur);
        }
        cout << ans << '\n';
    }
    return 0;
}