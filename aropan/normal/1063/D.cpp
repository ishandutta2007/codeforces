#include <iostream>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
#define dbg(x) cerr << #x " = " << x << endl;
#define idbg(x) #x " = " << x
#include "pretty_print.h"
#else
#define dbg(x)
#define idbg(x) ""
#endif

#ifdef _WIN32
#  define LLD "%I64d"
#else
#  define LLD "%lld"
#endif

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
template <typename T> bool chmin(T &x, const T& y) { if (x > y) { x = y; return true; } return false; }
template <typename T> bool chmax(T &x, const T& y) { if (x < y) { x = y; return true; } return false; }

#define lft(t) (m + max(0LL, t - (n - m) - 1))
#define rht(t) (m + min(m, t))


int f(ll n, ll m, ll k, ll w, ll t) {
    if (t < 0 || t > n) {
        return -1;
    }
    ll d = k - w * (n + t);

    if (d < lft(t)) {
        return -1;
    }
    if (d > rht(t)) {
        return 1;
    }
    return 0;
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    ll n, l, r, k;
    while (cin >> n >> l >> r >> k) {
        ll m = (r + n - l) % n + 1;

        ll ans = -1;

        for (ll w = 0; w <= 1e+5 + 42; ++w) {
            ll l = 0;
            ll r = n;
            while (l < r) {
                ll c = (l + r) / 2;
                int v = f(n, m, k, w, c);
                if (v == -1) {
                    r = c - 1;
                } else if (v == 1) {
                    l = c + 1;
                } else {
                    chmax(ans, c);
                    l = c + 1;
                }
            }
            if (f(n, m, k, w, l) == 0) {
                chmax(ans, l);
            }
            if (f(n, m, k, w, r) == 0) {
                chmax(ans, r);
            }
        }

        for (ll t = min(n, (ll)1e+6 + 42); t > ans; --t) {
            ll d = (k - 1) % (n + t) + 1;
            if (lft(t) <= d && d <= rht(t)) {
                ans = t;
                break;
            }
        }

        cout << ans << endl;
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}