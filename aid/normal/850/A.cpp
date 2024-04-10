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
const int d = 5;
int n;
int a[maxn][d];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < d; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  return true;
}

void solve() {
  if (n > 50) {
    printf("0\n");
    return;
  }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    bool ok = true;
    for (int j = 0; j < n && ok; j++) {
      if (j == i) {
        continue;
      }
      for (int k = j + 1; k < n && ok; k++) {
        int s = 0;
        for (int ii = 0; ii < d; ii++) {
          s += (a[j][ii] - a[i][ii]) * (a[k][ii] - a[i][ii]);
        }
        if (s > 0) {
          ok = false;
        }
      }
    }
    if (ok) {
      ans.push_back(i);
    }
  }
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); i++) {
    printf("%d\n", ans[i] + 1);
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