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
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + n + 1);
        int s = 0;
        for (int i = 1; i <= n; ++i) s += a[i];
        if (s == 0) {
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
        if (s < 0) {
            for (int i = 1; i <= n; ++i) cout << a[i] << " ";
        }
        else for (int i = n; i >= 1; --i) cout << a[i] << " ";
        cout << '\n';
    }
    return 0;
}