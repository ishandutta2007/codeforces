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

const int maxn = (int) 2e5 + 5;
int n;
int p[maxn];
int x, a, y, b;
long long k;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
  }
  scanf("%d%d%d%d%lld", &x, &a, &y, &b, &k);
  return true;
}

bool check(int m) {
  int kab = 0, ka = 0, kb = 0;
  for (int i = 0; i < m; i++) {
    if (i % a == a - 1) {
      if (i % b == b - 1) {
        kab++;
      } else {
        ka++;
      }
    } else if (i % b == b - 1) {
      kb++;
    }
  }
  long long s = 0;
  for (int i = 0; i < kab; i++) {
    s += p[i] * (x + y);
  }
  for (int i = 0; i < ka; i++) {
    s += p[kab + i] * x;
  }
  for (int i = 0; i < kb; i++) {
    s += p[kab + ka + i] * y;
  }
  return s >= k;
}

void solve() {
  sort(p, p + n, greater<int>());
  for (int i = 0; i < n; i++) {
    p[i] /= 100;
  }
  if (x < y) {
    swap(x, y);
    swap(a, b);
  }
  int l = 0, r = n + 1;
  while (l < r - 1) {
    int m = (l + r) / 2;
    if (check(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  int res = r;
  if (res == n + 1) {
    res = -1;
  }
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