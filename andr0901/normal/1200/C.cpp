#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
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
#define int long long

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m, q;    
    cin >> n >> m >> q;
    int g = __gcd(n, m);
    vector <int> b = {n, m};
    while (q --> 0) {
        vector <pii> a(2);
        forn (i, 0, 2)
            cin >> a[i].fs >> a[i].sc;
        forn (i, 0, 2) {
            a[i].sc--;
            a[i].sc /= (b[a[i].fs - 1] / g);
        }
        if (a[0].sc == a[1].sc)
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
    return 0;
}