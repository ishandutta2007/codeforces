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

const int maxn = (int) 5e4 + 5, m = 5;
int n;
int a[maxn][m];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  return true;
}

bool cmp(int i, int j) {
  int cnt = 0;
  for (int k = 0; k < m; ++k) {
    if (a[i][k] < a[j][k]) {
      ++cnt;
    }
  }
  return cnt >= 3;
}

void solve() {
  int p = 0;
  for (int i = 1; i < n; ++i) {
    if (cmp(i, p)) {
      p = i;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (cmp(i, p)) {
      printf("-1\n");
      return;
    }
  }
  printf("%d\n", p + 1);
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