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

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, I;
    cin >> n >> I;
    map <int, int> a;
    forn (i, 0, n) {
        int t;
        cin >> t;
        a[t]++;
    }
    vector <pii> b;
    for (pii i : a) 
        b.pb(i);
    sort(all(b));
    int k = (1LL << (8 * I / n));
    //cout << k << " ";
    if (8 * I / n > 60 || k >= sz(b))
        return cout << 0, 0;
    int s = 0;
    forn (i, 0, k)
        s += b[i].sc;
    int ans = n - s;
    forn (i, k, sz(b)) {
        s -= b[i - k].sc;
        s += b[i].sc;
        ans = min(ans, n - s);
    }
    cout << ans;
    return 0;
}