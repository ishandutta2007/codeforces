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
int m, n;
int a[maxn], b[maxn];
pair<int, pair<int, int>> es[maxn];
int ecnt;

bool read() {
  if (scanf("%d%d", &m, &n) < 2) {
    return false;
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
  }
  ecnt = 0;
  for (int i = 0; i < m; ++i) {
    int v = n + i;
    int k;
    scanf("%d", &k);
    for (int j = 0; j < k; ++j) {
      int u;
      scanf("%d", &u);
      --u;
      es[ecnt++] = make_pair(a[i] + b[u], make_pair(v, u));
    }
  }
  return true;
}

int p[maxn], ts[maxn];

int get(int x) {
  return (p[x] == x ? x : p[x] = get(p[x]));
}

bool unite(int x, int y) {
  x = get(x);
  y = get(y);
  if (x == y) {
    return false;
  }
  if (ts[x] < ts[y]) {
    swap(x, y);
  }
  ts[x] += ts[y];
  p[y] = x;
  return true;
}

void solve() {
  for (int i = 0; i < n + m; ++i) {
    p[i] = i;
    ts[i] = 1;
  }
  sort(es, es + ecnt);
  long long res = 0;
  for (int i = ecnt - 1; i >= 0; --i) {
    int w = es[i].first, v = es[i].second.first, u = es[i].second.second;
    if (!unite(v, u)) {
      res += w;
    }
  }
  printf("%lld\n", res);
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