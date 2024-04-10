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

const int maxn = 1005;
int n;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  return true;
}

int a[maxn][maxn];

void solve() {
  int cur = 0;
  for (int i = 0; i < n; i += 4) {
    for (int j = 0; j < n; j += 4) {
      for (int ii = 0; ii < 4; ii++) {
        for (int jj = 0; jj < 4; jj++) {
          a[i + ii][j + jj] = cur++;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    int s = 0;
    for (int j = 0; j < n; j++) {
      s ^= a[i][j];
    }
    assert(!s);
  }
  for (int j = 0; j < n; j++) {
    int s = 0;
    for (int i = 0; i < n; i++) {
      s ^= a[i][j];
    }
    assert(!s);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", a[i][j]);
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
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}