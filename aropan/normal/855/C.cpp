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

const int MAXT = 12;
const int MAXN = 1e+5 + 42;
const int MOD = 1e+9 + 7;

vector<vector<int>> e;
ll f[MAXN][MAXT][3];

int n, m, k, t;
int k1, m1;

template <typename T, typename S> void add(T& x, S d) { x += d; if (x >= MOD) x %= MOD; }

void dfs(int x, int p = -1) {
  memset(f[x], 0, sizeof(f[x]));
  f[x][0][0] = 1;
  f[x][1][2] = 1;
  for (auto& y : e[x]) {
    if (y == p) {
      continue;
    }
    dfs(y, x);
    for (int i = t; i >= 0; --i) {
      ll f1, f2, f3;
      f1 = f2 = f3 = 0;
      for (int j = 0; j <= i; ++j) {
        add(f1, f[x][i - j][0] * (f[y][j][0] * m1 % MOD + f[y][j][1] * k1 % MOD) % MOD);
        add(f2,
            (f[x][i - j][0] + f[x][i - j][1]) * f[y][j][2] % MOD +
            f[x][i - j][1] * (f[y][j][0] * m1 % MOD + f[y][j][1] * k1 % MOD) % MOD
        );
        add(f3,
            f[x][i - j][2] * (f[y][j][0] * k1 % MOD + f[y][j][1] * k1 % MOD) % MOD
        );
      }
      f[x][i][0] = f1;
      f[x][i][1] = f2;
      f[x][i][2] = f3;
    }
  }
  // cout << x << ":" << endl;
  // for (int i = 0; i <= t; ++i) {
  //   for (int j = 0; j < 3; ++j) {
  //     cout << " " << f[x][i][j];
  //   }
  //   cout << endl;
  // }
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    while (cin >> n && n) {
      e.clear();
      e.resize(n);
      cin >> m;
      for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        e[u].push_back(v);
        e[v].push_back(u);
      }
      cin >> k >> t;
      k1 = k - 1;
      m1 = m - 1;
      dfs(0);
      ll answer = 0;
      for (int i = 0; i <= t; ++i) {
        add(answer, f[0][i][0] * m1 % MOD);
        add(answer, f[0][i][1] * k1 % MOD);
        add(answer, f[0][i][2]);
      }
      cout << answer << endl;
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}