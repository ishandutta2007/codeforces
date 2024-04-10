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

const int maxn = (int) 4e5 + 5;
int q;

int read() {
  if (scanf("%d", &q) < 1) {
    return false;
  }
  return true;
}

map<int, int> ids;
int p[maxn], ts[maxn], d[maxn];

int getId(int i) {
  if (!ids.count(i)) {
    int id = sz(ids);
    ids[i] = id;
    p[id] = id;
    ts[id] = 1;
    d[id] = 0;
    return id;
  }
  return ids[i];
}

int get(int v) {
  if (p[v] == v) {
    return v;
  }
  int root = get(p[v]);
  d[v] ^= d[p[v]];
  p[v] = root;
  return root;
}

void unite(int v, int u, int x) {
  int rv = get(v), ru = get(u);
  if (rv == ru) {
    return;
  }
  x ^= d[v];
  x ^= d[u];
  v = rv;
  u = ru;
  if (ts[v] < ts[u]) {
    swap(v, u);
  }
  p[u] = v;
  d[u] = x;
  ts[v] += ts[u];
}

int getRes(int v, int u) {
  int rv = get(v), ru = get(u);
  if (rv != ru) {
    return -1;
  }
  return (d[v] ^ d[u]);
}

void solve() {
  ids.clear();
  int lst = 0;
  for (int qq = 0; qq < q; qq++) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int l, r, x;
      scanf("%d%d%d", &l, &r, &x);
      l ^= lst;
      r ^= lst;
      x ^= lst;
      if (l > r) {
        swap(l, r);
      }
      r++;
      unite(getId(l), getId(r), x);
    } else {
      int l, r;
      scanf("%d%d", &l, &r);
      l ^= lst;
      r ^= lst;
      if (l > r) {
        swap(l, r);
      }
      r++;
      int res = getRes(getId(l), getId(r));
      printf("%d\n", res);
      lst = (res == -1 ? 1 : res);
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