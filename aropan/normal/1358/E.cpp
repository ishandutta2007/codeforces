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


int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    int n;
    while (cin >> n) {
        int m = (n + 1) / 2;
        int k = n / 2;
        vector<ll> a(m);
        for (int i = 0; i < m; ++i) {
            cin >> a[i];
        }

        for (int i = m - 2; i >= 0; --i) {
            a[i] += a[i + 1];
        }

        ll x;
        cin >> x;
        if (x >= 0) {
            cout << (a[0] + x * k > 0? n : -1) << endl;
            continue;
        }


        int ans = -1;
        ll limit = 0;
        for (int i = 0; i < m; ++i) {
            if (a[i] <= 0) {
                break;
            }
            ll t = (a[i] - 1) / -x;
            if (limit <= i && t >= k) {
                ans = m - i + k;
                break;
            }
            chmax(limit, i + k - t);
        }
        cout << ans << endl;
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}