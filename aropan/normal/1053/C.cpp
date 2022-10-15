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

const int MAXN = 2e+5 + 42;
const int MAXT = 4 * MAXN;
const int MOD = (int)1e+9 + 7;

#define goleft(x) 2 * x + 0
#define goright(x) 2 * x + 1

int n;

ll a[MAXN];

ll f[MAXT];
ll w[MAXT];

ll wa[MAXT];
ll wi[MAXT];
ll wr[MAXT];

ll WI;
ll WA;


void init(int x, int i) {
    f[x] = w[i];
    wa[x] = w[i] * a[i] % MOD;
    wi[x] = w[i] * i % MOD;
}

void upd(int x) {
    f[x] = f[goleft(x)] + f[goright(x)];
    wa[x] = (wa[goleft(x)] + wa[goright(x)]) % MOD;
    wi[x] = (wi[goleft(x)] + wi[goright(x)]) % MOD;
}

void build(int x, int l, int r) {
    if (l + 1 == r) {
        init(x, l);
    } else {
        int c = (l + r) / 2;
        build(goleft(x), l, c);
        build(goright(x), c, r);
        upd(x);
    }
}

void modify(int x, int l, int r, int p, int v) {
    if (l + 1 == r) {
        assert(p == l);
        init(x, l);
        return;
    }
    int c = (l + r) / 2;
    if (p < c) {
        modify(goleft(x), l, c, p, v);
    } else {
        modify(goright(x), c, r, p, v);
    }
    upd(x);
}

ll findsum(int x, int l, int r, int a, int b) {
    if (a <= l && r - 1 <= b) {
        (WA += wa[x]) %= MOD;
        (WI += wi[x]) %= MOD;
        return f[x];
    }
    int c = (l + r) / 2;
    ll ret = 0;
    if (a < c) {
        ret += findsum(goleft(x), l, c, a, b);
    }
    if (c <= b) {
        ret += findsum(goright(x), c, r, a, b);
    }
    return ret;
}

int findcnt(int x, int l, int r, int p, ll& s) {
    if (s <= 0) {
        return 0;
    }

    if (p <= l) {
        if (f[x] <= s) {
            s -= f[x];
            return r - l;
        }

        if (l + 1 == r) {
            s = -1;
            return 0;
        }
        int c = (l + r) / 2;

        return
            findcnt(goleft(x), l, c, p, s) +
            findcnt(goright(x), c, r, p, s);
    }

    int c = (l + r) / 2;
    int ret = 0;
    if (p < c) {
        ret += findcnt(goleft(x), l, c, p, s);
    }
    ret += findcnt(goright(x), c, r, p, s);
    return ret;
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    int q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    build(1, 0, n);

    while (q--) {
        int x, y;
        cin >> x >> y;
        if (x < 0) {
            x = -x - 1;
            w[x] = y;
            modify(1, 0, n, x, y);
        } else {
            --x;
            --y;
            ll sum = findsum(1, 0, n, x, y);
            ll limit = sum / 2;
            int k = findcnt(1, 0, n, x, limit);
            // cout << endl;
            // for (int i = x; i <= y; ++i) {
            //     cout << w[i] << " ";
            // }
            // cout << endl;
            // cout << sum << ": " << x << " " << y << " = " << k << endl;

            ll t;

            WA = WI = 0;
            ll lsum = findsum(1, 0, n, x, x + k - 1);

            t = x + k - 1;

            // cout << WA << " " << WI << " " << lsum << " " << t << endl;
            ll lr = (WI + lsum % MOD * (a[x + k - 1] - t) % MOD) % MOD - WA;

            WA = WI = 0;
            ll rsum = findsum(1, 0, n, x + k, y);

            t = x + k;

            // cout << WA << " " << WI << " " << rsum << " " << t << endl;
            ll rr = WA - (WI + rsum % MOD * (a[x + k] - t) % MOD) % MOD;

            // cout << idbg(lr) << " " << idbg(rr) << endl;
            ll res = lr + rr;
            if (k) {
                res += lsum % MOD * (a[x + k] - a[x + k - 1] - 1) % MOD;
            }

            res = (res % MOD + MOD) % MOD;
            cout << res << "\n";
        }
    }
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}