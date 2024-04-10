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
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i] > a[i + 1]) ans = 1;
        }
        if (ans) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}