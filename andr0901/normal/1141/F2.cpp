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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    forn (i, 0, n)
        cin >> a[i];
    map <int, vector <pii>> mp;
    forn (i, 0, n) {
        int s = 0;
        forn (j, i, n) {
            s += a[j];
            mp[s].eb(i, j);
        }
    }
    vector <pii> ans;
    for (auto i : mp) {
        auto b = i.sc;
        sort(all(b), [&](pii a, pii b){return a.sc < b.sc;});
        vector <pii> c;
        int last = -1e9;
        forn (j, 0, sz(b)) {
            if (b[j].fs > last) {
                last = b[j].sc;
                c.pb(b[j]);
            }
        }
        if (sz(c) > sz(ans))
            ans = c;
    }
    cout << sz(ans) << "\n";
    for (auto i : ans)
        cout << i.fs + 1 << " " << i.sc + 1 << "\n";
    return 0;
}