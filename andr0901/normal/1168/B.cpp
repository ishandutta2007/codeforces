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
    string s;
    cin >> s;
    vector <pii> a;
    forn (i, 0, sz(s)) {
        for (int j = 1; j < min(i + 1, sz(s) - i); j++) {
            if (s[i - j] == s[i] && s[i + j] == s[i]) {
                a.eb(i - j, i + j);
                break;
            }
        }
    }
    /*forn (i, 0, sz(a))
        cout << a[i].fs << " " << a[i].sc << "\n";*/
    sort(rall(a));
    int j = 0, mn = sz(s);
    ll ans = 0;
    for (int i = sz(s) - 1; i >= 0; i--) {
        while (j < sz(a) && a[j].fs == i) {
            mn = min(mn, a[j].sc);
            j++;
        }
        //cout << mn << " ";
        ans += (sz(s) - mn);
    }
    cout << ans;
    return 0;  
}