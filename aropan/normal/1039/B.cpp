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
#include "pretty_print.h"
#else
#define dbg(x)
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

const int MOD = (int)1e+9 + 7;

ll n, k, p;
ll t;

bool get(ll l, ll r) {
#ifdef LOCAL
    ++t;
    cout << t << ". ";
#endif
    cout << l << " " << r << endl;
    cout.flush();
#ifdef LOCAL
    assert(1 <= l);
    assert(r <= n);
    assert(l <= r);
    bool ret = l <= p && p <= r;
    p += rand() % (2 * k + 1) - k;
    p = max(1LL, p);
    p = min(n, p);
#else
    string c;
    getline(cin, c);
    if (c == "Bad") {
        exit(0);
    }
    bool ret = c == "Yes";
#endif

    if (ret && l == r) {
        exit(0);
    }
    return ret;
}


int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef LOCAL
    assert(freopen("inp", "r", stdin));
#endif

    srand(time(NULL));

#ifdef LOCAL
    cin >> n >> k >> p;
    t = 0;
#else
    cin >> n >> k;
    string c;
    getline(cin, c);
#endif

    ll l = 1;
    ll r = n;
    for (;;) {
        ll c = (l + r) / 2;
        if ((r - l + 1) <= (r - l + 1) / 2 + 3 * k) {
            ll x = l + (ll)(rand() / (double)RAND_MAX * (r - l + 1));
            assert(l <= x && x <= r);
            get(x, x);
        } else {
            bool ok = get(l, c);
            if (ok) {
                r = c;
            } else {
                l = c + 1;
            }
        }

        l = max(1LL, l - k);
        r = min(n, r + k);
    }

    return 0;
}