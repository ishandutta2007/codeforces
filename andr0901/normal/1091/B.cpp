#pragma GCC optmize("Ofast")
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
    vector <pii> a(n);
    int s1 = 0, s2 = 0;
    forn (i, 0, n) {
        cin >> a[i].fs >> a[i].sc;
        s1 += a[i].fs, s2 += a[i].sc;
    }
    vector <pii> b(n);
    forn (i, 0, n) {
        cin >> b[i].fs >> b[i].sc;
        s1 += b[i].fs, s2 += b[i].sc;
    }
    cout << s1 / n << " " << s2 / n;
    return 0;
}