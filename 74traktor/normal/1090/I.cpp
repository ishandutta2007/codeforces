#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
int const maxn = 1e7 + 5;
ll a[maxn];
ull b[maxn];

void solve() {
    int n;
    ll l, r, x, y, z, b1, b2;
    cin >> n >> l >> r >> x >> y >> z >> b1 >> b2;
    ull mod = (1ll << 32);
    b[1] = b1;
    b[2] = b2;
    for (int i = 1; i <= n; ++i) {
        if (i >= 3) b[i] = (b[i - 2] * (ull)x + b[i - 1] * (ull)y + (ull)z) % mod;
        a[i] = b[i] % (r - l + 1) + l;
    }
    //cin >> n;
    //for (int i = 1; i <= n; ++i) cin >> a[i];
    int ok = 1;
    for (int i = 1; i <= n; ++i) {
        if (a[i] >= 0) ok = 0;
    }
    ll zn = 2;
    ll imin = a[1];
    ll ans = 8e18;
    for (int i = 2; i <= n; ++i) {
        if (a[i] >= 0) {
            if (imin < a[i]) ans = min(ans, imin * a[i]);
        }
        imin = min(imin, a[i]);
    }
    if (zn == 2) {
        ll imax ;
        int f = 1;
        for (int i = n; i >= 1; --i) {
            if (a[i] >= 0) continue;
            if (f) {
                imax = a[i];
                f = 0;
                continue;
            }
            if (imax > a[i]) {
                if (a[i] * imax < ans) ans = a[i] * imax;
            }
            imax = max(imax, a[i]);
        }
    }
    if (ans == 8e18) {
        cout << "IMPOSSIBLE" << '\n';
        return;
    }
    cout << ans << '\n';
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
        //cout << endl;
    }
    return 0;
}