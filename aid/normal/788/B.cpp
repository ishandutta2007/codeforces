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
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 1e6 + 5;
int n, m;
int deg[maxn];
int degl[maxn];
int p[maxn], ts[maxn];

int get(int x) {
  return x == p[x] ? x : p[x] = get(p[x]);
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
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  return true;
}

void solve() {
  for (int i = 0; i < n; i++) {
    deg[i] = 0;
    degl[i] = 0;
    p[i] = i;
    ts[i] = 1;
  }
  int loops = 0;
  for (int i = 0; i < m; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    unite(v, u);
    if (v != u) {
      deg[v]++;
      deg[u]++;
    } else {
      degl[v]++;
      loops++;
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 0 && degl[i] == 0) {
      continue;
    }
    if (get(i) == i) {
      cnt++;
    }
  }
  if (cnt > 1) {
    printf("0\n");
    return;
  }
  long long res = 0;
  for (int i = 0; i < n; i++) {
    res += (long long) deg[i] * (deg[i] - 1) / 2;
  }
  res += (long long) loops * (m - loops);
  res += (long long) loops * (loops - 1) / 2;
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