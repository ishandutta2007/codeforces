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

const int maxn = 65;
int n, m;
char c[maxn][maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%s", c[i]);
  }
  return true;
}

void solve() {
  {
    bool ok = true;
    for (int i = 0; i < n && ok; i++) {
      for (int j = 0; j < m && ok; j++) {
        if (c[i][j] == 'P') {
          ok = false;
        }
      }
    }
    if (ok) {
      printf("0\n");
      return;
    }
  }
  {
    bool found = false;
    for (int i = 0; i < 2 && !found; i++) {
      int x = (!i ? 0 : n - 1);
      bool ok = true;
      for (int j = 0; j < m && ok; j++) {
        if (c[x][j] == 'P') {
          ok = false;
        }
      }
      if (ok) {
        found = true;
      }
    }
    for (int j = 0; j < 2 && !found; j++) {
      int y = (!j ? 0 : m - 1);
      bool ok = true;
      for (int i = 0; i < n && ok; i++) {
        if (c[i][y] == 'P') {
          ok = false;
        }
      }
      if (ok) {
        found = true;
      }
    }
    if (found) {
      printf("1\n");
      return;
    }
  }
  if (c[0][0] == 'A' || c[0][m - 1] == 'A' || c[n - 1][0] == 'A' || c[n - 1][m - 1] == 'A') {
    printf("2\n");
    return;
  }
  {
    bool found = false;
    for (int i = 0; i < n && !found; i++) {
      bool ok = true;
      for (int j = 0; j < m && ok; j++) {
        if (c[i][j] == 'P') {
          ok = false;
        }
      }
      if (ok) {
        found = true;
      }
    }
    for (int j = 0; j < m && !found; j++) {
      bool ok = true;
      for (int i = 0; i < n && ok; i++) {
        if (c[i][j] == 'P') {
          ok = false;
        }
      }
      if (ok) {
        found = true;
      }
    }
    if (found) {
      printf("2\n");
      return;
    }
  }
  {
    bool found = false;
    for (int i = 0; i < 2 && !found; i++) {
      int x = (!i ? 0 : n - 1);
      for (int j = 0; j < m && !found; j++) {
        if (c[x][j] == 'A') {
          found = true;
        }
      }
    }
    for (int j = 0; j < 2 && !found; j++) {
      int y = (!j ? 0 : m - 1);
      for (int i = 0; i < n && !found; i++) {
        if (c[i][y] == 'A') {
          found = true;
        }
      }
    }
    if (found) {
      printf("3\n");
      return;
    }
  }
  bool found = false;
  for (int i = 0; i < n && !found; i++) {
    for (int j = 0; j < m && !found; j++) {
      if (c[i][j] == 'A') {
        found = true;
      }
    }
  }
  if (found) {
    printf("4\n");
    return;
  }
  printf("MORTAL\n");
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