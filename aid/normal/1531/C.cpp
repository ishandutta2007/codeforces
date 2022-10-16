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

int n;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  return true;
}

const int maxn = 105;
char c[maxn][maxn];

void solve() {
  if (n == 2) {
    printf("-1\n");
    return;
  }
  for (int m = 1;; ++m) {
    if (m * m < n) {
      continue;
    }
    for (int k = 1; k <= m; ++k) {
      if ((k & 1) != (n & 1) || m * m - (m - k) * (m - k) < n) {
        continue;
      }
      int cur = k * k + 2 * (m - k);
      if (cur > n) {
        break;
      }
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
          c[i][j] = '.';
          if (i == 0 || j == 0 || (i < k && j < k)) {
            c[i][j] = 'o';
          }
        }
        c[i][m] = 0;
      }
      for (int i = 1; i < k && cur < n; ++i) {
        for (int j = k; j < m && cur < n; ++j) {
          c[i][j] = 'o';
          c[j][i] = 'o';
          cur += 2;
        }
      }
      for (int i = 0; i < m - i - 1; ++i) {
        for (int j = 0; j < m; ++j) {
          swap(c[i][j], c[m - i - 1][j]);
        }
      }
      printf("%d\n", m);
      for (int i = 0; i < m; ++i) {
        printf("%s\n", c[i]);
      }
      return;
    }
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