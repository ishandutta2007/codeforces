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
int n;
char c[2][maxn][maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%s", c[i][j]);
    }
  }
  return true;
}

char tmp[maxn][maxn];

void solve() {
  for (int flip = 0; flip < 2; flip++) {
    for (int rot = 0; rot < 4; rot++) {
      bool ok = true;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (c[0][i][j] != c[1][i][j]) {
            ok = false;
          }
        }
      }
      if (ok) {
        printf("Yes\n");
        return;
      }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          tmp[n - j - 1][i] = c[0][i][j];
        }
      }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          c[0][i][j] = tmp[i][j];
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        tmp[i][n - j - 1] = c[0][i][j];
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        c[0][i][j] = tmp[i][j];
      }
    }
  }
  printf("No\n");
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