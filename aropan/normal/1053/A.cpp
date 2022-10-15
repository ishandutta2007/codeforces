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


bool check(ll d, ll x, ll n, ll m) {
    if (d % x) {
        return false;
    }
    ll y = d / x;
    return 0 <= x && x <= n && 0 <= y && y <= m;
}


int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif

    ll n, m, k;
    while (cin >> n >> m >> k) {
        ll x = n, y = m;

        ll gx = gcd(k, x);
        x /= gx;
        k /= gx;

        ll gy = gcd(k, y);
        y /= gy;
        k /= gy;

        if (k > 2) {
            cout << "NO" << endl;
            continue;
        }

        if (k == 1) {
            if (2 * x <= n) {
                x *= 2;
            } else {
                y *= 2;
            }
        }

        cout << "YES" << endl;
        cout << "0 0" << endl;
        cout << x << " 0" << endl;
        cout << "0 " << y << endl;
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}