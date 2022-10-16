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
char c[maxn][maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%s", c[i]);
  }
  return true;
}

void solve() {
  int i0 = 1;
  if (n % 3 == 1) {
    i0 = 0;
  }
  for (int i = i0; i < n; i += 3) {
    for (int j = 0; j < m; ++j) {
      c[i][j] = 'X';
    }
    if (i == i0) {
      continue;
    }
    int pos = -1;
    for (int j = 0; j < m; ++j) {
      if (c[i - 1][j] == 'X' || c[i - 2][j] == 'X') {
        pos = j;
        break;
      }
    }
    if (pos == -1) {
      pos = 0;
    }
    c[i - 2][pos] = 'X';
    c[i - 1][pos] = 'X';
  }
  for (int i = 0; i < n; ++i) {
    printf("%s\n", c[i]);
  }
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