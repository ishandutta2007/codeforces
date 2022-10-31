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

int nxt() {
    int x;
    cin >> x;
    return x;
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int m = nxt(), n = nxt();
    vector <int> a(m);
    forn (i, 0, m)
        a[i] = nxt();
    vector <pii> b(n);
    forn (i, 0, n) 
        b[i] = {nxt(), nxt()};
    sort(all(b));
    vector <int> c(n), pr(n + 1);
    forn (i, 0, n) {
        c[i] = b[i].fs;
        pr[i + 1] = pr[i] + b[i].sc;
    }
    forn (i, 0, m) 
        cout << pr[upper_bound(all(c), a[i]) - c.begin()] << " ";
    return 0;
}