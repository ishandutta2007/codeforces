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

const int maxn = 105;
int n, m;
int b[maxn][maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &b[i][j]);
    }
  }
  return true;
}

pair<int, pair<int, int>> tosort[maxn * maxn];
int c[maxn][maxn];
int used[maxn];

void solve() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      tosort[i * m + j] = make_pair(b[i][j], make_pair(i, j));
    }
  }
  sort(tosort, tosort + n * m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      c[i][j] = false;
    }
  }
  for (int i = 0; i < m; ++i) {
    int x = tosort[i].second.first, y = tosort[i].second.second;
    c[x][y] = true;
  }
  int p = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      used[j] = false;
    }
    int cur = 0;
    for (int j = 0; j < m && cur < p; ++j) {
      if (c[i][j] || used[j]) {
        continue;
      }
      printf("%d ", b[i][j]);
      ++cur;
      used[j] = true;
    }
    for (int j = 0; j < m; ++j) {
      if (!c[i][j] || used[j]) {
        continue;
      }
      printf("%d ", b[i][j]);
      ++cur;
      ++p;
      used[j] = true;
    }
    for (int j = 0; j < m; ++j) {
      if (c[i][j] || used[j]) {
        continue;
      }
      printf("%d ", b[i][j]);
      ++cur;
      used[j] = true;
    }
    printf("\n");
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