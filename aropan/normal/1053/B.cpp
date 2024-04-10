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
        vector <int> a(n, 0);
        vector <int> f(n, 0);
        vector <int> g(n, 0);
        for (int i = 0; i < n; ++i) {
            ll x;
            cin >> x;
            while (x) {
                ++a[i];
                x = x & (x - 1);
            }
        }
        for (int i = 0; i < n; ++i) {
            g[i] = (a[i] & 1) ^ (i > 0? g[i - 1] : 0);
            f[i] = g[i] + (i > 0? f[i - 1] : 0);
        }

        ll ans = 0;
        for (int l = 0; l <= 60; l++) {
            int s = 0;
            int j = 0;
            int left = 0, right = -1;
            for (int i = 0; i < n; ++i) {
                if (a[i] > l) {
                    left = i + 1;
                    j = i + 1;
                    right = -1;
                    s = 0;
                    continue;
                }

                if (a[i] == l) {
                    right = i;
                }

                s += a[i];
                while (j <= right && s >= 2 * l) {
                    s -= a[j];
                    ++j;
                }

                if (right != -1) {
                    int k = 0;
                    k += (j > 1)? f[j - 2] : 0;
                    k -= (left > 1)? f[left - 2] : 0;
                    if ((g[i] & 1) == 0) {
                        k = (j - left) - k;
                    }
                    // cout << l << ": " << i << ". " << left << " " << j << " " << right << " = " << k << endl;
                    ans += k;
                }
            }
        }
        cout << ans << endl;

// #ifdef LOCAL
//         cerr << idbg(ans) << endl;
//         int res = 0;
//         for (int i = 0; i < n; ++i) {
//             int s = 0;
//             int t = 0;
//             int m = 0;
//             for (int j = i; j < n; ++j) {
//                 m = max(a[j], m);
//                 s += a[j];
//                 t ^= a[j] & 1;
//                 if (m * 2 <= s && t == 0) {
//                     res += 1;
//                 }
//             }
//         }
//         cout << idbg(res) << endl;
//         assert(res == ans);
// #endif
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}