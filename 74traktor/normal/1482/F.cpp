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
        int c = -1;
        int imin = a[1], imax = a[1];
        for (int i = 1; i <= n; ++i) imin = min(imin, a[i]), imax = max(imax, a[i]);
        for (int i = 2; i <= n; ++i) {
            if (a[i] >= a[i - 1]) c = a[i] - a[i - 1];
        }
        if (n == 1 || imin == imax) {
            cout << 0 << '\n';
            continue;
        }
        if (c == -1) {
            int flag = 1;
            for (int i = 3; i <= n; ++i) {
                if (a[i] - a[i - 1] != a[i - 1] - a[i - 2]) flag = 0;
            }
            if (flag) cout << 0 << '\n';
            else cout << -1 << '\n';
        }
        else {
            int flag = 1, m = -1;
            int was = -1;
            for (int i = 2; i <= n; ++i) {
                if (a[i - 1] + c != a[i]) {
                    m = a[i - 1] + c - a[i];
                    was = 1;
                }
            }
            if (was == -1) cout << 0 << '\n';
            else {
                if (m <= 0) cout << -1 << '\n';
                else {
                    if (m <= a[1]) flag = 0;
                    for (int i = 2; i <= n; ++i) if (a[i] != (a[i - 1] + c) % m) flag = 0;
                    if (flag) cout << m << " " << c << '\n';
                    else cout << -1 << '\n';
                }
            }
        }
    }
    return 0;
}