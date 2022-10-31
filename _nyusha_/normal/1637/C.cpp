#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 1e5 + 5;
int a[maxn];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        int flag = 1;
        for (int i = 2; i < n; ++i) if (a[i] != 1) flag = 0;
        if (flag) {
            cout << -1 << '\n';
            continue;
        }
        if (n == 3) {
            if (a[2] % 2 == 0) cout << a[2] / 2 << '\n';
            else cout << -1 << '\n';
            continue;
        }
        int ans = 0, L = 0, R = 0;
        for (int i = 2; i < n; ++i) {
            ans += (a[i] + 1) / 2;
        }
        cout << ans << '\n';
    }
    return 0;
}