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
int n, m, ta, tb, k;
int a[maxn], b[maxn];

bool read() {
  if (scanf("%d%d%d%d%d", &n, &m, &ta, &tb, &k) < 5) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &b[i]);
  }
  return true;
}

void solve() {
  int res = -1;
  for (int i = 0; i <= n && i <= k; i++) {
    if (i == n) {
      res = max(res, 2 * inf);
      continue;
    }
    int t = a[i] + ta;
    int pos = lower_bound(b, b + m, t) - b;
    pos += k - i;
    if (pos >= m) {
      res = max(res, 2 * inf);
      continue;
    }
    res = max(res, b[pos] + tb);
  }
  if (res == 2 * inf) {
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
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}