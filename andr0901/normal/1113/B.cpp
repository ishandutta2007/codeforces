#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define int long long

typedef long long ll;

 main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    ll s = 0;
    vector <int> a(n);
    forn (i, 0, n) {
        int t;
        cin >> t;
        a[i] = t;
        s += t;
    }
    sort(all(a));
    ll ans = s;
    forn (i, 0, n) {
        for (int j = 1; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                ans = min(ans, s - a[0] - a[i] + a[i] / j + a[0] * j);
            }
        }
    }
    cout << ans;
    return 0;
}