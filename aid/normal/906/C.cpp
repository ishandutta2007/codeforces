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
int g[maxn];

int read() {
  if (scanf("%d%d", &n, &m) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i] = (1 << i);
  }
  for (int i = 0; i < m; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    g[v] |= (1 << u);
    g[u] |= (1 << v);
  }
  return true;
}

int con[pown];

void solve() {
  {
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (g[i] != ((1 << n) - 1)) {
        ok = false;
        break;
      }
    }
    if (ok) {
      printf("0\n\n");
      return;
    }
  }
  int res = inf;
  int x = -1;
  for (int msk = 1; msk < (1 << n); msk++) {
    int cnt = __builtin_popcount(msk);
    if (cnt >= res) {
      continue;
    }
    auto &curcon = con[msk];
    curcon = false;
    if (__builtin_popcount(msk) == 1) {
      curcon = true;
    }
    for (int i = 0; i < n && !curcon; i++) {
      if (!(msk & (1 << i))) {
        continue;
      }
      if (con[msk ^ (1 << i)] && (g[i] & (msk ^ (1 << i)))) {
        curcon = true;
      }
    }
    if (!curcon) {
      continue;
    }
    int can = 0;
    for (int i = 0; i < n; i++) {
      if (!(msk & (1 << i))) {
        continue;
      }
      can |= g[i];
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
      auto cur = g[i];
      if (cur & msk) {
        cur |= can;
      }
      if (cur != ((1 << n) - 1)) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      continue;
    }
    res = cnt;
    x = msk;
  }
  printf("%d\n", res);
  for (int i = 0; i < n; i++) {
    if (x & (1 << i)) {
      printf("%d ", i + 1);
    }
  }
  printf("\n");
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