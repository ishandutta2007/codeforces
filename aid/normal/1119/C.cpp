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

const int maxn = 505;
int n, m;
int a[2][maxn][maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int t = 0; t < 2; t++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        scanf("%d", &a[t][i][j]);
      }
    }
  }
  return true;
}

int rs[2][maxn], cs[2][maxn];

void solve() {
  for (int t = 0; t < 2; t++) {
    for (int i = 0; i < n; i++) {
      rs[t][i] = 0;
    }
    for (int i = 0; i < m; i++) {
      cs[t][i] = 0;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        rs[t][i] ^= a[t][i][j];
        cs[t][j] ^= a[t][i][j];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (rs[0][i] != rs[1][i]) {
      printf("No\n");
      return;
    }
  }
  for (int i = 0; i < m; i++) {
    if (cs[0][i] != cs[1][i]) {
      printf("No\n");
      return;
    }
  }
  printf("Yes\n");
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