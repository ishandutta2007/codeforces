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
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int mod = (int) 1e9 + 7;

int mul(int a, int b) {
  return (long long) a * b % mod;
}

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

const int maxn = (int) 2e5 + 5;
int n;
int a[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

int inv[maxn];

void getC(int n, int c[maxn]) {
  inv[1] = 1;
  for (int i = 2; i <= n; i++) {
    inv[i] = (mod - (long long) inv[mod % i] * (mod / i) % mod) % mod;
  }
  c[0] = 1;
  for (int i = 0; i < n; i++) {
    c[i + 1] = mul(c[i], mul(n - i, inv[i + 1]));
  }
}

int c[maxn], cc[maxn];

void solve() {
  /*vector< vector<int> > sgn(n - 1);
  {
    int cur = 1;
    for (int i = 0; i < n - 1; i++) {
      sgn[i].resize(n - 1 - i);
      for (int j = 0; j < sz(sgn[i]); j++, cur *= -1) {
        sgn[i][j] = (cur + mod) % mod;
      }
    }
  }
  vector<int> rc(1, 1);
  for (int i = n - 2; i >= 0; i--) {
    vector<int> nc(sz(rc) + 1, 0);
    for (int j = 0; j < sz(rc); j++) {
      add(nc[j], rc[j]);
      add(nc[j + 1], mul(sgn[i][j], rc[j]));
    }
    rc = nc;
  }
  eprintf("%d: ", n);
  for (int i = 0; i < n; i++) {
    eprintf("%d ", rc[i]);
  }
  eprintf("\n");*/
  if (n % 4 == 0) {
    getC(n / 2 - 1, cc);
    for (int i = 0; i < n; i++) {
      c[i] = cc[i / 2];
      if (i & 1) {
        c[i] = mod - c[i];
        if (c[i] >= mod) {
          c[i] -= mod;
        }
      }
    }
  } else if (n % 4 == 1) {
    getC(n / 2, cc);
    for (int i = 0; i < n; i++) {
      if (i & 1) {
        c[i] = 0;
      } else {
        c[i] = cc[i / 2];
      }
    }
  } else if (n % 4 == 2) {
    getC(n / 2 - 1, cc);
    for (int i = 0; i < n; i++) {
      c[i] = cc[i / 2];
    }
  } else {
    getC(n / 2 - 1, cc);
    for (int i = 0; i < n; i++) {
      if (i & 1) {
        c[i] = mul(cc[i / 2], 2);
      }
    }
    getC(n / 2 - 2, cc);
    for (int i = 0; 2 * i < n; i++) {
      if (!(i & 1)) {
        c[i] = cc[i / 2];
        if (i / 2 >= 2) {
          add(c[i], mod - cc[i / 2 - 2]);
        }
        c[n - 1 - i] = mod - c[i];
        if (c[n - 1 - i] >= mod) {
          c[n - 1 - i] -= mod;
        }
      }
    }
  }
  /*eprintf("n = %d\n", n);
  for (int i = 0; i < n; i++) {
    assert(rc[i] == c[i]);
  }*/
  int res = 0;
  for (int i = 0; i < n; i++) {
    add(res, mul(a[i], c[i]));
  }
  printf("%d\n", res);
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  /*for (n = 1; n <= 1000; n++) {
    solve();
  }
  exit(0);*/
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}