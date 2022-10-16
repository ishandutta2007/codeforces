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

const int n = 10;
char c[n + 1][n + 1];

int read() {
  for (int i = 0; i < n; i++) {
    if (scanf("%s", c[i]) < 1) {
      return false;
    }
  }
  return true;
}

bool inside(int x, int y) {
  return 0 <= x && x < n && 0 <= y && y < n;
}

bool check() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int dx = 0; dx < 2; dx++) {
        for (int dy = -1; dy < 2; dy++) {
          if (!dx && !dy) {
            continue;
          }
          bool ok = true;
          for (int it = 0; it < 5; it++) {
            int x = i + it * dx, y = j + it * dy;
            if (!inside(x, y) || c[x][y] != 'X') {
              ok = false;
              break;
            }
          }
          if (ok) {
            return true;
          }
        }
      }
    }
  }
  return false;
}

void solve() {
  bool ok = false;
  for (int i = 0; i < n && !ok; i++) {
    for (int j = 0; j < n && !ok; j++) {
      if (c[i][j] != '.') {
        continue;
      }
      c[i][j] = 'X';
      if (check()) {
        ok = true;
      }
      c[i][j] = '.';
    }
  }
  printf(ok ? "YES\n" : "NO\n");
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