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

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

ll brute_first(ll c, ll hr, ll hb, ll wr, ll wb)
{
    ll res = 0;
    for (ll i = 0; i * wr <= c; ++i) {
        res = max(res, i * hr + (c - i * wr) / wb * hb);
    }
    return res;
}

ll brute_second(ll c, ll hr, ll hb, ll wr, ll wb)
{
    ll res = 0;
    for (ll i = 0; i * wr <= c && i <= wb; ++i) {
        res = max(res, i * hr + (c - i * wr) / wb * hb);
    }
    return res;
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    ll c, hr, hb, wr, wb;
    ll ans = 0;
    cin >> c >> hr >> hb >> wr >> wb;

    if (wr > 10000) {
        ans = max(ans, brute_first(c, hr, hb, wr, wb));
    } else {
        ans = max(ans, brute_second(c, hb, hr, wb, wr));
    }
    if (wb > 10000) {
        ans = max(ans, brute_first(c, hb, hr, wb, wr));
    } else {
        ans = max(ans, brute_second(c, hr, hb, wr, wb));
    }
    cout << ans << endl;

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}