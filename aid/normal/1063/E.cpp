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

const int maxn = 1005;
int n;
int p[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
    p[i]--;
  }
  return true;
}

char c[maxn][maxn];
int used[maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      c[i][j] = '.';
    }
    c[i][n] = 0;
    used[i] = false;
  }
  {
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (p[i] != i) {
        ok = false;
        break;
      }
    }
    if (ok) {
      printf("%d\n", n);
      for (int i = 0; i < n; i++) {
        printf("%s\n", c[i]);
      }
      return;
    }
  }
  int row = 0;
  for (int i = 0; i < n; i++) {
    if (used[i]) {
      continue;
    }
    if (p[i] == i) {
      used[i] = true;
      continue;
    }
    int r0 = row;
    if (i) {
      row++;
    }
    used[i] = true;
    for (int j = p[i]; !used[j]; j = p[j]) {
      c[row][j] = (p[j] > j ? '/' : '\\');
      c[row][p[j]] = (p[j] > j ? '/' : '\\');
      row++;
      used[j] = true;
    }
    if (!i) {
      continue;
    }
    row--;
    c[row][0] = '\\';
    c[r0][0] = '/';
    c[r0][p[i]] = '/';
    row++;
  }
  printf("%d\n", n - 1);
  for (int i = 0; i < n; i++) {
    printf("%s\n", c[i]);
  }
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