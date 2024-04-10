#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int const maxn = 2e5 + 5;
int a[maxn], b[maxn];
int x[maxn], y[maxn];
int inf = 1e9;

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
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i] >> b[i];
        }
        ll bal = 0;
        for (int i = 1; i <= n; ++i) {
            if (2 * a[i] <= m) {
                x[i] = a[i], y[i] = m - a[i];
            } else if (2 * b[i] <= m) {
                x[i] = m - b[i], y[i] = b[i];
            } else {
                x[i] = min(a[i], m), y[i] = m - x[i];
            }
            bal += (a[i] - x[i]) - (b[i] - y[i]);
        }
        for (int i = 1; i <= n; ++i) {
            int cnt;
            if (abs(bal) > inf) cnt = inf;
            else cnt = abs(bal) / 2;
            if (bal > 0) {
                int imin = min({cnt, a[i] - x[i], y[i]});
                bal -= 2 * imin;
                x[i] += imin;
                y[i] -= imin;
            } else {
                int imin = min({cnt, x[i], b[i] - y[i]});
                bal += 2 * imin;
                x[i] -= imin;
                y[i] += imin;
            }
        }
        cout << abs(bal) << '\n';
        for (int i = 1; i <= n; ++i) {
            cout << x[i] << " " << y[i] << '\n';
        }
    }
    return 0;
}