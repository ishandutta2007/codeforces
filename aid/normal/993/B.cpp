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

const int maxn = 15;
int n, m;
int a[maxn][2], b[maxn][2];
int fa[maxn][2], fb[maxn][2];

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      scanf("%d", &a[i][j]);
      fa[i][j] = false;
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 2; j++) {
      scanf("%d", &b[i][j]);
      fb[i][j] = false;
    }
  }
  return true;
}


void solve() {
  set<int> st;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int cnt = (a[i][0] == b[j][0]) + (a[i][0] == b[j][1]) + (a[i][1] == b[j][0]) + (a[i][1] == b[j][1]);
      if (cnt == 1) {
        for (int t = 0; t < 2; t++) {
          for (int s = 0; s < 2; s++) {
            if (a[i][t] == b[j][s]) {
              fa[i][t] = true;
              fb[j][s] = true;
              st.insert(a[i][t]);
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (fa[i][0] && fa[i][1]) {
      printf("-1\n");
      return;
    }
  }
  for (int i = 0; i < m; i++) {
    if (fb[i][0] && fb[i][1]) {
      printf("-1\n");
      return;
    }
  }
  if (sz(st) > 1) {
    printf("0\n");
    return;
  }
  printf("%d\n", *st.begin());
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