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

const int maxn = 22, pown = (1 << maxn);
int n, m;
int used[pown];
int p[pown], ts[pown];
int isx[pown];
int as[pown];

int get(int x) {
  return (p[x] == x ? x : p[x] = get(p[x]));
}

void unite(int x, int y) {
  x = get(x);
  y = get(y);
  if (x == y) {
    return;
  }
  if (ts[x] < ts[y]) {
    swap(x, y);
  }
  ts[x] += ts[y];
  p[y] = x;
}

int read() {
  if (scanf("%d%d", &n, &m) < 1) {
    return false;
  }
  for (int i = 0; i < (1 << n); i++) {
    used[i] = false;
    p[i] = -1;
    ts[i] = 1;
    isx[i] = false;
  }
  for (int i = 0; i < m; i++) {
    int x;
    scanf("%d", &x);
    p[x] = x;
    isx[x] = true;
    as[i] = x;
  }
  return true;
}

bool dfs(int msk, int t) {
  if (used[msk]) {
    if (p[msk] != -1) {
      unite(t, msk);
    }
    return p[msk] != -1;
  }
  used[msk] = true;
  bool res = false;
  for (int i = 0; i < n; i++) {
    if (msk & (1 << i)) {
      if (dfs(msk ^ (1 << i), t)) {
        res = true;
      }
    }
  }
  if (isx[msk]) {
    res = true;
  }
  if (res) {
    p[msk] = msk;
    unite(t, msk);
  }
  return res;
}

void solve() {
  for (int i = 0; i < m; i++) {
    dfs(((1 << n) - 1) ^ as[i], as[i]);
  }
  int res = 0;
  for (int i = 0; i < (1 << n); i++) {
    res += (p[i] == i);
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