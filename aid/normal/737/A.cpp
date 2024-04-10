#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 2.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 2e5 + 5;
int n, k, s, t;
int c[maxn], v[maxn];
int x[maxn];
int d[maxn];

int read() {
  if (scanf("%d%d%d%d", &n, &k, &s, &t) < 4) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &c[i], &v[i]);
  }
  for (int i = 0; i < k; i++) {
    scanf("%d", &x[i]);
  }
  return true;
}

bool check(long long v) {
  long long needt = 0;
  for (int i = 0; i < k; i++) {
    needt += max(3ll * d[i] - v, (long long) d[i]);
  }
  return needt <= t;
}

void solve() {
  if (t < s) {
    printf("-1\n");
    return;
  }
  sort(x, x + k);
  d[0] = x[0] - 0;
  for (int i = 1; i < k; i++) {
    d[i] = x[i] - x[i - 1];
  }
  d[k] = s - x[k - 1];
  k++;
  long long l = d[0];
  for (int i = 1; i < k; i++) {
    l = max(l, (long long) d[i]);
  }
  l--;
  long long r = inf;
  while (l < r - 1) {
    long long m = (l + r) / 2;
    if (check(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  int res = inf;
  for (int i = 0; i < n; i++) {
    if (v[i] >= r) {
      res = min(res, c[i]);
    }
  }
  if (res == inf) {
    res = -1;
  }
  printf("%d\n", res);
}

int main() {
  precalc();
#ifdef LOCAL
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}