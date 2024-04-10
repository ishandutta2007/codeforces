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


int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif

    int n;
    ll t;
    while (cin >> n >> t) {
        ll a[n];
        int x[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> x[i];
            --x[i];
        }
        const ll MAX = (ll)1e+18 * 3 - 42;
        ll l[n];
        ll r[n];
        for (int i = 0; i < n; ++i) {
            l[i] = 1;
            r[i] = MAX;
        }

        for (int i = 0; i < n; ++i) {
            ll v = a[i] + t;
            chmax(l[x[i]], v);
            if (x[i] + 1 < n) {
                chmin(r[x[i]], a[x[i] + 1] + t - 1);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (i + 1 < n && x[i] > i) {
                chmax(l[i], a[i + 1] + t);
            }
        }

        ll b[n + 1];
        b[n] = MAX;
        bool ok = true;
        for (int i = n - 1; i >= 0; --i) {
            b[i] = min(b[i + 1] - 1, r[i]);
            ok &= b[i] >= l[i];
        }

        if (!ok) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
            for (int i = 0; i < n; ++i) {
                if (i) {
                    cout << " ";
                }
                cout << b[i];
            }
            cout << endl;
        }
    }


    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}