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

int n, mod;

bool read() {
  if (scanf("%d%d", &n, &mod) < 2) {
    return false;
  }
  return true;
}

int mul(int a, int b) {
  return (long long) a * b % mod;
}

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

const int maxn = (int) 4e6 + 5;
int a[maxn];

void solve() {
  for (int x = 1; x <= n; ++x) {
    a[x] = 0;
  }
  a[0] = 0;
  a[1] = 1;
  a[2] = mod - 1;
  for (int x = 1; x <= n; ++x) {
    add(a[x], a[x - 1]);
    add(a[x + 1], a[x]);
    add(a[n + 1], mod - a[x]);
    for (int k = 2; k * x <= n; ++k) {
      int l = k * x, r = min(n + 1, l + k);
      add(a[l], a[x]);
      add(a[r], mod - a[x]);
    }
  }
  printf("%d\n", a[n]);
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