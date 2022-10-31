#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define int long long

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0) {
        int n;
        cin >> n;
        vector <int> a(n);
        forn (i, 0, n)
            cin >> a[i];
        sort(all(a));
        vector <int> b;
        int x = a[0] * a[sz(a) - 1];
        for (int j = 2; j * j <= x; j++) {
            if (x % j == 0) {
                b.pb(j);
                b.pb(x / j);
            }
        }
        sort(all(b)), b.erase(unique(all(b)), b.end());
        bool ok = 1;
        if (sz(a) != sz(b)) 
            ok = 0;
        else {
            forn (i, 0, n)
                if (a[i] != b[i])
                    ok = 0;    
         }
        if (!ok)
            cout << -1;
        else 
            cout << x;
        cout << "\n";
    }
    return 0;
}