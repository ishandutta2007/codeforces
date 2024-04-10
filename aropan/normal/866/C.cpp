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

    int n, s;
    while (cin >> n >> s) {
        // n = 50;
        // s = 50;
        ld g[n + 1][s + 1];
        memset(g[n], 0, sizeof(g[n]));
        int f[n], r[n];
        ld p[n];
        for (int i = 0; i < n; ++i) {
            cin >> f[i] >> r[i] >> p[i];
            // f[i] = 1;
            // r[i] = 100;
            // p[i] = 80;
            p[i] /= 100;
        }
        ld left, right;
        left = 0;
        right = 1e+18;
        for (int iter = 0; iter < 242; ++iter) {
            ld x = (left + right) / 2;
            for (int i = n - 1; i >= 0; --i) {
                for (int j = 0; j <= s; ++j) {
                    g[i][j] =
                        (min(x, j + f[i] <= s? g[i + 1][j + f[i]] : x) + f[i]) * p[i] +
                        (min(x, j + r[i] <= s? g[i + 1][j + r[i]] : x) + r[i]) * (1 - p[i]);
                }
            }
            if (x > g[0][0]) {
                right = x;
            } else {
                left = x;
            }
        }
        cout.precision(10);
        cout << fixed << right << endl;
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}