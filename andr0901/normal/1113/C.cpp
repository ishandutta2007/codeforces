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
main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n + 1);
    int s = 0;
    map <int, int> b, d;
    a[0] = 0;
    forn (i, 1, n + 1)
        cin >> a[i];
    ll ans = 0;
    forn (i, 0, n + 1) {
        s ^= a[i];
        if (i % 2)
            b[s]++;
        else
            d[s]++;
        if (i % 2)
            ans += b[s] - 1;
        else
            ans += d[s] - 1;
    }
    cout << ans;
    return 0;
}