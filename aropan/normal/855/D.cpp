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

const int MAXN = 1e+5 + 42;
const int MAXT = 20;

int f[2][MAXN][MAXT];
int d[MAXN];
int lg[MAXN];

#define NO cout << "NO\n"
#define YES cout << "YES\n"

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif

    lg[1] = 0;
    for (int i = 2; i < MAXN; ++i) {
      lg[i] = lg[i >> 1] + 1;
    }


    int n;
    while (cin >> n && n) {
      memset(f, 0, sizeof(f));
      memset(d, 0, sizeof(d));
      for (int x = 1; x <= n; ++x) {
        int u, t;
        cin >> u >> t;
        if (u == -1) {
          continue;
        }
        d[x] = d[u] + 1;
        f[t][x][0] = u;
        for (int j = 1; j < MAXT; ++j) {
          f[t][x][j] = f[t][f[t][x][j - 1]][j - 1];
          if (f[t][x][j] == 0) {
            break;
          }
        }
      }
      int q;
      cin >> q;
      while (q--) {
        int c, x, y;
        cin >> c >> x >> y;
        if (x == y) {
          NO;
          continue;
        }
        if (c == 1) {
          while (y && d[x] < d[y]) {
            y = f[0][y][lg[d[y] - d[x]]];
          }
          x == y? YES : NO;
          continue;
        }
        while (x && y && d[x] > d[y]) {
            x = f[0][x][lg[d[x] - d[y]]];
        }
        bool up_y = false;
        while (x && y && d[x] < d[y]) {
            y = f[1][y][lg[d[y] - d[x]]];
            up_y = true;
        }
        if (x == 0 || y == 0) {
          NO;
          continue;
        }
        if (x == y) {
          up_y? YES : NO;
          continue;
        }
        for (int i = MAXT - 1; i >= 0; --i) {
          while (f[0][x][i] && f[1][y][i] && f[0][x][i] != f[1][y][i]) {
            x = f[0][x][i];
            y = f[1][y][i];
          }
        }
        f[0][x][0] && f[0][x][0] == f[1][y][0]? YES : NO;
      }
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}