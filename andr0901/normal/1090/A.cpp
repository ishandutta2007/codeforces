#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define int long long

typedef long long ll;

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <pii> a(n);
    int m = -1;
    forn (i, 0, n) {
        cin >> a[i].fs;
        a[i].sc = -1;
        forn (j, 0, a[i].fs) {
            int t;
            cin >> t;
            a[i].sc = max(a[i].sc, t);
        }
        m = max(m, a[i].sc);
    }
    //cout << m;
    ll ans = 0;
    forn (i, 0, n)
        ans += (m - a[i].sc) * a[i].fs;
    cout << ans;
    return 0;
}