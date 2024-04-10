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

const int maxn = 105;
int n, m;
int a[maxn][maxn];

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  return true;
}

int rs[maxn], cs[maxn];

void solve() {
  int res = inf;
  vector< pair<int, int> > ans;
  for (int r0 = 0; r0 <= a[0][0]; r0++) {
    rs[0] = r0;
    bool ok = true;
    for (int i = 1; i < n; i++) {
      rs[i] = rs[0] + a[i][0] - a[0][0];
      if (rs[i] < 0) {
        ok = false;
      }
    }
    if (!ok) {
      continue;
    }
    cs[0] = a[0][0] - r0;
    for (int i = 1; i < m; i++) {
      cs[i] = cs[0] + a[0][i] - a[0][0];
      if (cs[i] < 0) {
        ok = false;
      }
    }
    if (!ok) {
      continue;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] != rs[i] + cs[j]) {
          ok = false;
        }
      }
    }
    if (!ok) {
      continue;
    }
    int cur = 0;
    for (int i = 0; i < n; i++) {
      cur += rs[i];
    }
    for (int i = 0; i < m; i++) {
      cur += cs[i];
    }
    if (cur < res) {
      res = cur;
      ans.clear();
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < rs[i]; j++) {
          ans.push_back(make_pair(0, i));
        }
      }
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < cs[i]; j++) {
          ans.push_back(make_pair(1, i));
        }
      }
    }
  }
  if (res >= inf) {
    printf("-1\n");
    return;
  }
  assert(sz(ans) == res);
  printf("%d\n", res);
  for (int i = 0; i < res; i++) {
    printf("%s %d\n", (ans[i].first ? "col" : "row"), ans[i].second + 1);
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