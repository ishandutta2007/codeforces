#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define int long long

typedef long long ll;

pii f(pii a, pii b) {
    if (a.sc > b.sc || a.fs > b.fs)
        return {0, 0};
    b.sc++, b.fs++;
    if ((b.fs - a.fs) * (b.sc - a.sc) % 2 == 0)
        return {(b.fs - a.fs) * (b.sc - a.sc) / 2, (b.fs - a.fs) * (b.sc - a.sc) / 2};
    if ((a.fs + a.sc) % 2)
        return {(b.fs - a.fs) * (b.sc - a.sc) / 2, (b.fs - a.fs) * (b.sc - a.sc) / 2 + 1};
    return {(b.fs - a.fs) * (b.sc - a.sc) / 2 + 1, (b.fs - a.fs) * (b.sc - a.sc) / 2};
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    pii o = {1, 1};
    while (t --> 0) {
        /*pii a, b;
        cin >> a.fs >> a.sc >> b.fs >> b.sc;
        b.fs++, b.sc++;
        cout << f(a, b).fs << " " << f(a, b).sc << "\n";*/
        pii e;
        cin >> e.fs >> e.sc;
        pii a, b, c, d;
        cin >> a.fs >> a.sc >> b.fs >> b.sc >> c.fs >> c.sc >> d.fs >> d.sc;
        pii x = {max(a.fs, c.fs), max(a.sc, c.sc)}, y = {min(b.fs, d.fs), min(b.sc, d.sc)};
        cout << f(o, e).fs + f(a, b).sc - f(x, y).sc - f(c, d).fs << " " << e.fs * e.sc  - (f(o, e).fs + f(a, b).sc - f(x, y).sc - f(c, d).fs) << "\n";

    }
    return 0;
}