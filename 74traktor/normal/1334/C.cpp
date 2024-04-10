#include<bits/stdc++.h>

using namespace std;

#define int long long

int const maxn = 3e5 + 5;
int a[maxn], b[maxn], inf = 1e18, c[maxn];

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
        int n, ans = inf, sum = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
        for (int i = 1; i <= n; ++i) {
            int lst = i - 1;
            if (i == 1) lst = n;
            c[i] = max(a[i] - b[lst], 0ll);
            sum += c[i];
        }
        for (int i = 1; i <= n; ++i) {
            ans = min(ans, a[i] + sum - c[i]);
        }
        cout << ans << '\n';
    }
    return 0;
}