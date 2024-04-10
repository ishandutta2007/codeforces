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

struct Vc{
    int x, y;
    Vc(int _x = 0, int _y = 0) {
         x = _x;
         y = _y;
    }
    Vc(Vc a, Vc b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }
    int len() {
        return x * x + y * y;
    }
};

int operator%(Vc a, Vc b) {
    return a.x * b.y - a.y * b.x;
}

int operator*(Vc a, Vc b) {
    return a.x * b.x + a.y * b.y;
};

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <Vc> a(n);
    forn (i, 0, n)
        cin >> a[i].x >> a[i].y;
    vector <pii> b;
    forn (i, 0, n) {
        forn (j, i + 1, n) {
            bool ok = 1;
            for (pii k : b) {
                if (Vc(a[i], a[j]) % Vc(a[k.fs], a[k.sc]) == 0 && 
                    Vc(a[i], a[j]) % Vc(a[i], a[k.sc]) == 0)
                    ok = 0;
            }
            if (ok)
                b.pb({i, j});
        }
    }
    ll ans = 0;
    forn (i, 0, sz(b))
        forn (j, i + 1, sz(b))
            if (Vc(a[b[i].fs], a[b[i].sc]) % Vc(a[b[j].fs], a[b[j].sc]))
                ans++;
    cout << ans;
    return 0;
}