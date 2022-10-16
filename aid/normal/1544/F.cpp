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

const int mod = 31607;

int mul(int a, int b) {
  return a * b % mod;
}

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

int inv[mod];

void precalc() {
  inv[1] = 1;
  for (int i = 2; i < mod; ++i) {
    inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
  }
}

const int maxn = 21, pown = (1 << maxn);
int n;
int a[maxn][maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &a[i][j]);
      a[i][j] = mul(a[i][j], inv[10000]);
    }
  }
  return true;
}

int b[maxn];
int cols[pown][maxn];
int cc[maxn];

void solve() {
  for (int i = 0; i < n; ++i) {
    b[i] = 1;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      b[j] = mul(b[j], a[i][j]);
    }
  }
  int res = 0;
  for (int msk = 1; msk < (1 << n); ++msk) {
    int cur = 1;
    for (int i = 0; i < n; ++i) {
      if (msk & (1 << i)) {
        cur = mul(cur, b[i]);
      }
    }
    if (!(__builtin_popcount(msk) & 1)) {
      cur = mul(cur, mod - 1);
    }
    add(res, cur);
  }
  for (int i = 0; i < n; ++i) {
    cols[0][i] = b[i];
  }
  for (int i = 0; i < n; ++i) {
    b[i] = 1;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      b[i] = mul(b[i], a[i][j]);
    }
  }
  for (int msk = 0; msk < (1 << n); ++msk) {
    if (msk) {
      int lbit = __builtin_ctz(msk);
      int pmsk = (msk ^ (1 << lbit));
      for (int i = 0; i < n; ++i) {
        cols[msk][i] = mul(cols[pmsk][i], inv[a[lbit][i]]);
      }
    }
    int sgn0 = (__builtin_popcount(msk) & 1);
    for (int d0 = 0; d0 < 2; ++d0) {
      for (int d1 = 0; d1 < 2; ++d1) {
        if (!msk && !d0 && !d1) {
          continue;
        }
        int cur = 1;
        for (int i = 0; i < n; ++i) {
          cc[i] = cols[msk][i];
        }
        for (int i = 0; i < n; ++i) {
          if (msk & (1 << i)) {
            cur = mul(cur, b[i]);
          } else {
            if (d0) {
              cur = mul(cur, a[i][i]);
              cc[i] = mul(cc[i], inv[a[i][i]]);
            }
            if (d1 && (!d0 || i != n - 1 - i)) {
              cur = mul(cur, a[i][n - 1 - i]);
              cc[n - 1 - i] = mul(cc[n - 1 - i], inv[a[i][n - 1 - i]]);
            }
          }
        }
        for (int i = 0; i < n; ++i) {
          int p = 1;
          add(p, mod - cc[i]);
          cur = mul(cur, p);
        }
        int sgn = (sgn0 ^ d0 ^ d1);
        if (!sgn) {
          cur = mul(cur, mod - 1);
        }
        add(res, cur);
      }
    }
  }
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