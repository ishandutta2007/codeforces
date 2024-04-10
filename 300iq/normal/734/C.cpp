#include <bits/stdc++.h>

#define fc first
#define sc second
#define all(x) x.begin(), x.end()
#define bit(x) __builtin_popcount(x)
#define pb push_back
#define popb pop_back
#define ll long long

using namespace std;

int main() {
    srand('M' + 'R' + '.' + 'D' + 'U' + 'D' + 'E' + 'C');
    #ifdef ONPC
        freopen("a.in", "r", stdin);
        //freopen("a.out", "w", stdout);
    #else
        //freopen("a.in", "r", stdin);
        //freopen("a.out", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    ll n, m, k, x, s;
    cin >> n >> m >> k >> x >> s;
    vector <ll> a(m), b(m), c(k), d(k);
    for (int i = 0; i < m; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    for (int i = 0; i < k; i++) cin >> c[i];
    for (int i = 0; i < k; i++) cin >> d[i];
    ll res = n * x;
    for (int i = 0; i < m; i++) {
        int l = 0, r = k;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (d[m] + b[i] <= s) {
                l = m;
            } else {
                r = m;
            }
        }
        if (b[i] <= s) {
            res = min(res, n * a[i]);
        }
        if (d[l] + b[i] <= s) {
            res = min(res, max(0ll, (n - c[l])) * a[i]);
        }
    }
    for (int i = 0; i < k; i++) {
        if (d[i] <= s) {
            res = min(res, max(0ll, (n - c[i])) * x);
        }
    }
    cout << res << '\n';
}