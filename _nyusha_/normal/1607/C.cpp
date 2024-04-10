#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 2e5 + 5;
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
        sort(a + 1, a + n + 1);
        int ans = a[1], add = 0;
        for (int i = 2; i <= n; ++i) {
            add += a[i - 1];
            a[i] -= add;
            ans = max(ans, a[i]);
        }
        cout << ans << '\n';
    }
    return 0;
}