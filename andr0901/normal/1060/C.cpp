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
    int n, m;
    cin >> n >> m;
    vector <int> aa(n), bb(m);
    forn (i, 0, n)
        cin >> aa[i];
    forn (i, 0, m)
        cin >> bb[i];
    vector <int> a(n + 1);
    forn (i, 1, n + 1)
        a[i] = aa[i - 1] + a[i - 1];
    vector <int> b(m + 1);
    forn (i, 1, m + 1)
        b[i] = bb[i - 1] + b[i - 1];
    vector <int> c(n + 1, 1e9);
    forn (i, 0, n)
        forn (j, i + 1, n + 1)
            c[j - i] = min(c[j - i], a[j] - a[i]);
    //return 0;
    vector <int> d(m + 1, 1e9);
    forn (i, 0, m)
        forn (j, i + 1, m + 1)
            d[j - i] = min(d[j - i], b[j] - b[i]);
    int x;
    cin >> x;
    int ans = 0;
    forn (i, 1, n + 1)
        forn (j, 1, m + 1)
            if (1LL * c[i] * d[j] <= x)
                ans = max(ans, i * j);
    cout << ans;
    return 0;
}