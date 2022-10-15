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

#ifdef LOCAL
#define dbg(x) cerr << #x " = " << x << endl;
#include "pretty_print.h"
#else
#define dbg(x)
#endif

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define snd second
#define fst first

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
template <typename T> bool chmin(T &x, const T& y) { if (x > y) { x = y; return true; } return false; }
template <typename T> bool chmax(T &x, const T& y) { if (x < y) { x = y; return true; } return false; }

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    ll x, s;
    while (cin >> s >> x) {
        ll o, z;
        o = 0;
        z = 1;
        ll ans = 0;
        if (x <= s) {
            if (x == s) {
                ans -= 2;
            }
            while (s) {
                int bx = x & 1;
                int bs = s & 1;
                x >>= 1;
                s >>= 1;
                ll o_ = o;
                ll z_ = z;
                if (bx == 0) {
                    z = bs? o_ : z_;
                    o = bs? o_ : z_;
                } else {
                    z = bs? 2 * z_ : 0;
                    o = bs? 0 : 2 * o_;
                }
            }
            ans += z;
        }
        cout << ans << endl;
    }

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}