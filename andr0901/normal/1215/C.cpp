#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    string a, b;
    cin >> n >> a >> b;
    vector <int> c, d;
    forn (i, 0, n) {
        if (a[i] == 'a' && b[i] == 'b')
            c.pb(i);
        if (a[i] == 'b' && b[i] == 'a')
            d.pb(i);
    }
    vector <pii> ans;
    while (sz(c) > 1) {
        ans.eb(c[sz(c) - 1], c[sz(c) - 2]);
        c.pop_back(), c.pop_back();
    }
    while (sz(d) > 1) {
        ans.eb(d[sz(d) - 1], d[sz(d) - 2]);
        d.pop_back(), d.pop_back();
    }
    if (sz(c) != sz(d))
        return cout << -1, 0;
    if (sz(c) == 1)
        ans.eb(c[0], c[0]), ans.eb(c[0], d[0]);
    cout << sz(ans) << "\n";
    for (auto i : ans)
        cout << i.fs + 1 << " " << i.sc + 1 << "\n";
    return 0;
}