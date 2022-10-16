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

int seed, base;

int rng() {
  int res = seed;
  seed = ((long long) seed * base + 233) % mod;
  return res;
}

const int maxn = (int) 5e6 + 5;
int n;
int t[maxn], a[maxn];

bool read() {
  int m;
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  int pr = 0;
  for (int i = 0; i < m; ++i) {
    int p, k, b, w;
    scanf("%d%d%d%d", &p, &k, &b, &w);
    seed = b;
    base = w;
    for (int j = pr; j < p; ++j) {
      t[j] = rng() % 2;
      a[j] = (rng() % k) + 1;
    }
    pr = p;
  }
  return true;
}

int ans[maxn];

void solve() {
  long long bal = 0;
  for (int i = 0; i < n; ++i) {
    if (t[i]) {
      bal += a[i];
    } else {
      bal -= a[i];
    }
  }
  if (bal < 0) {
    for (int i = 0; i < n; ++i) {
      t[i] ^= 1;
    }
  }
  bal = 0;
  for (int i = 0; i < n; ++i) {
    ans[i] = 0;
  }
  if (t[0]) {
    --a[0];
    ++ans[0];
  }
  for (int i = 0; i < n; ++i) {
    if (!t[i]) {
      ans[i] = a[i];
      bal += a[i];
      continue;
    }
    int take = min((long long) a[i], bal);
    a[i] -= take;
    ans[i] += take;
    bal -= take;
  }
  for (int i = 0; i < n && bal; ++i) {
    if (!t[i]) {
      continue;
    }
    int take = min((long long) a[i], bal);
    a[i] -= take;
    ans[i] += take;
    bal -= take;
  }
  int res = 1;
  for (int i = 0; i < n; ++i) {
    long long cur = (long long) (i + 1) * (i + 1);
    cur ^= (long long) ans[i];
    ++cur;
    res = mul(res, cur % mod);
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