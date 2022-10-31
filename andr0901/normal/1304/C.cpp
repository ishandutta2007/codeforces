#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
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

pii intersect(pii a, pii b) {
    return {max(a.fs, b.fs), min(a.sc, b.sc)};
}

void solve() {
    int n, t;
    cin >> n >> t;
    vector <pair <int, pii>> a(n);
    forn (i, 0, n)
        cin >> a[i].fs >> a[i].sc.fs >> a[i].sc.sc;
    pii cur = {t, t};
    sort(all(a));
    int prev = 0;
    forn (i, 0, n) {
        cur.fs -= a[i].fs - prev;
        cur.sc += a[i].fs - prev;
        cur = intersect(cur, a[i].sc);
        //cout << cur.fs << " " << cur.sc << "\n";
        if (cur.fs > cur.sc) {
            cout << "NO\n";
            return;
        }
        prev = a[i].fs;
    }
    cout << "YES\n";
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}