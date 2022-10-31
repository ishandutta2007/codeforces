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

vector <pii> b;
int n, x1, y1, x2, y2;

bool check(int m) {
    pii c = {x1 + m / n * b[n].fs + b[m % n].fs, y1 + m / n * b[n].sc + b[m % n].sc};
    return abs(x2 - c.fs) + abs(y2 - c.sc) > m;
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> n;
    vector <char> a(n + 1);
    forn (i, 1, n + 1)
        cin >> a[i];
    b.resize(n + 1);
    forn (i, 1, n + 1) {
        b[i] = b[i - 1];
        if (a[i] == 'R')
            b[i].fs++;
        if (a[i] == 'L')
            b[i].fs--;
        if (a[i] == 'U')
            b[i].sc++;
        if (a[i] == 'D')
            b[i].sc--;
    }
    int l = -1, r = 1e18;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (check(m))
            l = m;
        else
            r = m;
    }
    if (r == 1e18)
        return cout << -1, 0;
    else
        cout << r;
    return 0;
}