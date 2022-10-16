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

const int maxn = 505, logx = 60;
int n, m;
bitset<maxn> a[logx][2][maxn];
bitset<maxn> at[logx][2][maxn];

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    a[0][0][i].reset();
    a[0][1][i].reset();
  }
  for (int i = 0; i < m; i++) {
    int v, u, t;
    scanf("%d%d%d", &v, &u, &t);
    v--;
    u--;
    a[0][t][v][u] = true;
  }
  return true;
}

bitset<maxn> cur[maxn];
bitset<maxn> nxt[maxn];

long long get(int t, int h, long long l, long long r) {
  if (!h) {
    return l;
  }
  long long m = (l + r) / 2;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      nxt[i][j] = (cur[i] & at[h - 1][t][j]).any();
    }
  }
  if (nxt[0].any()) {
    for (int i = 0; i < n; i++) {
      cur[i] = nxt[i];
    }
    return get((t ^ 1), h - 1, m, r);
  } else {
    return get(t, h - 1, l, m);
  }
}

void solve() {
  for (int t = 0; t < 2; t++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        at[0][t][i][j] = a[0][t][j][i];
      }
    }
  }
  for (int it = 0; it + 1 < logx; it++) {
    for (int t = 0; t < 2; t++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          a[it + 1][t][i][j] = (a[it][t][i] & at[it][t ^ 1][j]).any();
        }
      }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          at[it + 1][t][i][j] = a[it + 1][t][j][i];
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cur[i][j] = (i == j);
    }
  }
  long long res = get(0, logx, 0, (1ll << ((long long) logx)));
  if (res > (long long) 1e18) {
    res = -1;
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