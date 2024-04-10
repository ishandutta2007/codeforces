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
    int n, l, r;
    cin >> n >> l >> r;
    ll ans = n, pow = 2;
    forn (i, 0, l - 1) {
        ans += (pow - 1);
        pow *= 2;
    }
    ll ans2 = 0, pow2 = 1;
    forn (i, 0, r) {
        ans2 += pow2;
        pow2 *= 2;
    }
    pow2 /= 2;
    forn (i, r, n) 
        ans2 += pow2;
    cout << ans << " " << ans2;
    return 0;
}