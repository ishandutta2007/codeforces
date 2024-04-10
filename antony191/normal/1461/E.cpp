#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
//#pragma GCC optimize("vpt")

using namespace std;

typedef long long ll;
typedef long double ld;

const char el = '\n';
const int inf = 1000'000'000, mod = 1000'000'007, mod2 = 998'244'353;
const ll llinf = 1e18;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define x first
#define y second
#define debug(x) cout << #x << ": " << x << el

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return true; } return false; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return true; } return false; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(nullptr));

__int128 gcd (__int128 a, __int128 b, __int128 & x, __int128 & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    __int128 x1, y1;
    __int128 d = gcd (b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
bool find_any_solution (__int128 a, __int128 b, __int128 c, __int128 & x0, __int128 & y0, __int128 & g) {
    g = gcd(a, b, x0, y0);
    if (c % g != 0)
        return false;
    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 *= -1;
    if (b < 0) y0 *= -1;
    return true;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll k, l, r, t, x, y;
    cin >> k >> l >> r >> t >> x >> y;
    if (y < x) {
        if (k + y <= r) k += y;
        ll delta = x - y;
        ll op = (k - (l + x)) / delta;
        if (op + 2 > t) cout << "Yes" << el;
        else cout << "No" << el;
        return 0;
    }
    ll a = max(l, r - y + 1);
    ll b = min(l + x - 1, r);
    if (a > b) return cout << "Yes" << el, 0;
    __int128 x0, y0, g;
    for (ll i = a; i <= b; i++) {
        if (find_any_solution((__int128)x, (__int128)y, (__int128)(k - i), x0, y0, g)) {
            x0 = x0 % y;
            if (x0 < 0) x0 += y;
            if (x0 < t) return cout << "No" << el, 0;
        }
    }
    cout << "Yes" << el;
    return 0;
}