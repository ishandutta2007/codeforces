#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int q;
    cin >> q;
    int n = 500005;
    int m = 650;
    vector <ll> a(n);
    vector <vector <ll>> small(m, vector <ll> (m));
    forn (i, 0, q) {
        int tp, x, y;
        cin >> tp >> x >> y;
        if (tp == 1) {
            a[x] += y;
            //if (x < m) {
                forn (j, 1, m)
                    small[j][x % j] += y;
            //}
        } else {
            ll ans = 0;
            if (x < m) 
                cout << small[x][y] << "\n";
            else {
                for (int j = y; j < n; j += x)
                    ans += a[j];
                cout << ans << "\n";
            }
        }
    }
    return 0;
}