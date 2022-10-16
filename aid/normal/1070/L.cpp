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

const int maxn = 2005;
int n, m;
bitset<maxn> a[maxn];

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    a[i].reset();
  }
  for (int i = 0; i < m; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    a[v][u] = 1;
    a[u][v] = 1;
  }
  return true;
}

int bit[maxn];
int ans[maxn];

void solve() {
  {
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (a[i].count() & 1) {
        ok = false;
        a[i][i] = 1;
        a[i][n] = 1;
      }
    }
    if (ok) {
      printf("1\n");
      for (int i = 0; i < n; i++) {
        printf("1 ");
      }
      printf("\n");
      return;
    }
  }
  for (int i = 0; i < n; i++) {
    auto &x = bit[i];
    x = -1;
    for (int j = 0; j < n; j++) {
      if (a[i][j]) {
        x = j;
      }
    }
    if (x == -1) {
      assert(!a[i][n]);
      continue;
    }
    for (int j = 0; j < n; j++) {
      if (j != i && a[j][x]) {
        a[j] ^= a[i];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    ans[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    if (bit[i] == -1) {
      continue;
    }
    ans[bit[i]] = a[i][n];
  }
  printf("2\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", ans[i] + 1);
  }
  printf("\n");
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