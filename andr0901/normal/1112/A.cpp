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

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector <pii> a(n);
    vector <int> b(m + 1, -1);
    forn (i, 0, n)
        cin >> a[i].fs;
    forn (i, 0, n)
        cin >> a[i].sc;
    forn (i, 0, n)
        b[a[i].sc] = max(b[a[i].sc], a[i].fs);
    int ans = 0;
    forn (i, 0, k) {
        int t;
        cin >> t;
        t--;
        if (b[a[t].sc] > a[t].fs)
            ans++;
        if (b[a[t].sc] == a[t].fs)
            b[a[t].sc]++;
     }
     cout << ans;
    return 0;
}