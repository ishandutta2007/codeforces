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
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <pii> a;
    forn (i, 0, n) {
        forn (j, 0, m) {
            int t;
            cin >> t;
            a.pb({t, i + j});
        }
    }
    vector <pii> b;
    forn (i, 0, n) {
        forn (j, 0, m) {
            int t;
            cin >> t;
            b.pb({t, i + j});
        }
    }
    sort(all(a));
    sort(all(b));
    forn (i, 0, a.size())
        if (a[i] != b[i])
            return cout << "NO", 0;
    cout << "YES";
    return 0;
}