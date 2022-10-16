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

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 1e5 + 5;
int n, m, l;
int a[maxn];

int read() {
  if (scanf("%d%d%d", &n, &m, &l) < 3) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

int p[maxn], ts[maxn];
int res;

int get(int v) {
  return (p[v] == v ? v : p[v] = get(p[v]));
}

void unite(int v, int u) {
  v = get(v);
  u = get(u);
  if (v == u) {
    return;
  }
  res--;
  if (ts[v] < ts[u]) {
    swap(v, u);
  }
  p[u] = v;
  ts[v] += ts[u];
}

void solve() {
  for (int i = 0; i < n; i++) {
    p[i] = i;
    ts[i] = 1;
  }
  res = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > l) {
      res++;
      if (i && a[i - 1] > l) {
        unite(i - 1, i);
      }
      if (i + 1 < n && a[i + 1] > l) {
        unite(i, i + 1);
      }
    }
  }
  for (int i = 0; i < m; i++) {
    int t;
    scanf("%d", &t);
    if (!t) {
      printf("%d\n", res);
    } else {
      int id, d;
      scanf("%d%d", &id, &d);
      id--;
      int wasa = a[id];
      a[id] = min(l + 1, a[id] + d);
      if (wasa <= l && a[id] > l) {
        res++;
        if (id && a[id - 1] > l) {
          unite(id - 1, id);
        }
        if (id + 1 < n && a[id + 1] > l) {
          unite(id, id + 1);
        }
      }
    }
  }
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