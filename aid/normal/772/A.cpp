#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define sz(s) ((int) ((s).size()))

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

typedef long long ll;
typedef long double ld;

const int inf = (int) 1.01e9;
const ld eps = 1e-11;
const ld pi = acos(-1.0L);

mt19937 mrand(random_device{} ());
int rnd(int x) {
  return mrand() % x;
}

const int mod = (int) 1e9 + 7;

void add(int & x, int y) {
  if ((x += y) >= mod) {
    x -= mod;
  }
}

int sum(int x, int y) {
  add(x, y);
  return x;
}

int mult(int x, int y) {
  return (ll) x * y % mod;
}

int power(int x, ll p) {
  int res = 1;
  while (p) {
    if (p & 1) {
      res = mult(res, x);
    }
    x = mult(x, x);
    p >>= 1;
  }
  return res;
}

int inv(int x) {
  return power(x, mod - 2);
}

void precalc() {
}

const int maxn = 1e5 + 100;

int n, p;
int a[maxn], b[maxn];

bool read() {
  if (scanf("%d%d", &n, &p) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d", a + i, b + i);
  }
  return true;
}

void solve() {
  ll suma = 0;
  for (int i = 0; i < n; i++) {
    suma += a[i];
  }
  if (suma <= p) {
    printf("-1\n");
    return;
  }
  ld l = 0, r = 1e30;
  for (int it = 0; it < 200; it++) {
    ld mid = (l + r) / 2;
    ld val = 0;
    for (int i = 0; i < n; i++) {
      ld cur = a[i] - b[i] / mid;
      if (cur < 0) {
        continue;
      }
      val += cur;
    }
    if (val < p) {
      l = mid;
    } else {
      r = mid;
    }
  }
  if (l > 1e30 / 2) {
    printf("-1\n");
    return;
  }
  printf("%.18f\n", (double) l);
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen("text.in", "r", stdin));
  assert(freopen("text.out", "w", stdout));
#endif

  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time: %.3f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}