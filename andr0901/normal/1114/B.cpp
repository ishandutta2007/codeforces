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
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> a(n);
    forn (i, 0, n)
        cin >> a[i];
    vector <int> b = a;
    sort(all(b));
    reverse(all(b));
    multiset <int> s;
    int ans = 0;
    forn (i, 0, m * k) {
        ans += b[i];
        s.insert(b[i]);
    }
    cout << ans << "\n";
    int t = 0;
    vector <int> kek;
    forn (i, 0, n) {
        if (s.find(a[i]) != s.end()) {
            s.erase(s.find(a[i]));
            t++;
        }
        if (t == m) {
            kek.pb(i + 1);
            t = 0;
        }
    }
    forn (i, 0, kek.size() - 1)
        cout << kek[i] << " ";
    return 0;
}