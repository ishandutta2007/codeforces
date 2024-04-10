#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const long long infll = (long long) 1.01e18;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

#ifdef DEBUG
mt19937 mrand(300); 
#else
mt19937 mrand(chrono::steady_clock::now().time_since_epoch().count()); 
#endif

int rnd(int x) {
  return mrand() % x;
}

const int mod = 998244353;

int mul(int a, int b) {
  return (long long) a * b % mod;
}

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

const int maxn = 4055;
int c[maxn][maxn];

void precalc() {
  for (int i = 0; i < maxn; ++i) {
    c[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      c[i][j] = c[i - 1][j - 1];
      add(c[i][j], c[i - 1][j]);
    }
  }
}

int n, m;

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  return true;
}

int get(int i, int j) {
  return mul(c[i - 1 + m - j][i - 1], c[n - i + m - j - 1][n - i]);
}

int s[maxn];

void solve() {
  int res = 0;
  for (int rot = 0; rot < 2; ++rot) {
    for (int i = 1; i < m; ++i) {
      s[i] = 0;
    }
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < m; ++j) {
        if (!rot) {
          add(s[j], get(i, j));
          add(res, mul(s[j], get(n - i, m - j)));
        } else {
          add(res, mul(s[j], get(n - i, m - j)));
          add(s[j], get(i, j));
        }
      }
    }
    swap(n, m);
  }
  res = mul(res, 2);
  printf("%d\n", res);
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}