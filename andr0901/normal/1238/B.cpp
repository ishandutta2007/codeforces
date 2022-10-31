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
#define int long long

void solve() {
    int n, r;
    cin >> n >> r;
    vector <int> a(n);
    forn (i, 0, n) 
        cin >> a[i];
    sort(all(a)), a.erase(unique(all(a)), a.end());
    int ans = sz(a);
    forn (i, 0, sz(a)) 
        ans = min(ans, max(i, (int)(lower_bound(all(a), 1e6) - lower_bound(all(a), i * r + 1))));
    cout << ans << "\n";
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int q;
    cin >> q;
    while (q --> 0)
        solve();
    return 0;
}