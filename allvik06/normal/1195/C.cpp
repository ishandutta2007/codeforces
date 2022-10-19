#include <bits/stdc++.h>

using namespace std;
#define int long long
#define double long double

const int INF = 1e18;

signed main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, maxa = 0, maxb = 0;
    cin >> n;
    vector <int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector <int> c(n), d(n);
    for (int i = 0; i < n; i++) {
        c[i] = a[i] + maxb;
        d[i] = b[i] + maxa;
        maxa = max(maxa, c[i]);
        maxb = max(maxb, d[i]);
    }
    cout << max(maxa, maxb);
}