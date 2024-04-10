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

int powMod(int x, int k) {
  int res = 1;
  while (k) {
    if (k & 1) {
      res = mul(res, x);
    }
    k >>= 1;
    x = mul(x, x);
  }
  return res;
}

const int maxn = (int) 1e6 + 5;
int n, p;
int a[maxn];

bool read() {
  if (scanf("%d%d", &n, &p) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

void solve() {
  sort(a, a + n);
  long long bal = 0;
  int res = 0;
  int k = inf;
  for (int i = n - 1; i >= 0; i--) {
    int nk = a[i];
    if (bal && p > 1) {
      int diff = k - nk;
      res = mul(res, powMod(p, diff));
      while (bal < maxn && diff) {
        bal *= p;
        diff--;
      }
    }
    k = nk;
    if (bal) {
      bal--;
      add(res, mod - 1);
    } else {
      bal = 1;
      res = 1;
    }
  }
  res = mul(res, powMod(p, k));
  printf("%d\n", res);
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  int t;
  scanf("%d", &t);
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}