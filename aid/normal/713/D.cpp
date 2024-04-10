#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define sz(s) ((int) ((s).size()))
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

typedef long long ll;
typedef long double ld;

const int inf = (int) 1e9 + 100;
const ld eps = 1e-11;
const ld pi = acos(-1.0L);

mt19937 mrand(random_device{} ());
int rnd(int x) {
  return mrand() % x;
}

const int maxn = 1005, maxt = (int)1e6 + 5, logn = 11;
int n, m, t;
int a[maxn][maxn], dp[maxn][maxn], st[logn][maxn][logn][maxn], logs[maxn];

void precalc() {
  logs[1] = 0;
  for (int i = 2; i < maxn; i++) {
    logs[i] = logs[i / 2] + 1;
  }
}

bool read() {
  if (scanf("%d%d", &n, &m) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  scanf("%d", &t);
  return true;
}

int get(int x0, int y0, int x1, int y1) {
  int lx = logs[x1 - x0], ly = logs[y1 - y0];
  return max(max(st[lx][x0][ly][y0], st[lx][x0][ly][y1 - (1 << ly)]),
             max(st[lx][x1 - (1 << lx)][ly][y0],
                 st[lx][x1 - (1 << lx)][ly][y1 - (1 << ly)]));
}

void solve() {
  for (int i = 0; i < m; i++) {
    dp[0][i] = a[0][i];
  }
  for (int i = 1; i < n; i++) {
    dp[i][0] = a[i][0];
    for (int j = 1; j < m; j++) {
      if (a[i][j]) {
        dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
      }
      else {
        dp[i][j] = 0;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      st[0][i][0][j] = dp[i][j];
    for (int lj = 1; lj <= logs[m]; lj++) {
      for (int j = 0; j + (1 << lj) <= m; j++) {
        st[0][i][lj][j] = max(st[0][i][lj - 1][j],
                              st[0][i][lj - 1][j + (1 << (lj - 1))]);
      }
    }
  }
  for (int li = 1; li <= logs[n]; li++) {
    for (int i = 0; i + (1 << li) <= n; i++) {
      for (int lj = 0; lj <= logs[m]; lj++) {
        for (int j = 0; j + (1 << lj) <= m; j++) {
          st[li][i][lj][j] = max(st[li - 1][i][lj][j],
                                 st[li - 1][i + (1 << (li - 1))][lj][j]);
        }
      }
    }
  }
  for (int i = 0; i < t; i++) {
    int x0, y0, x1, y1;
    scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
    x0--;
    y0--;
    int l = 0, r = min(x1 - x0, y1 - y0) + 1;
    while (l < r - 1) {
      int mid = (l + r) / 2;
      if (get(x0 + mid - 1, y0 + mid - 1, x1, y1) >= mid) {
        l = mid;
      }
      else {
        r = mid;
      }
    }
    printf("%d\n", l);
  }
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen("text.in", "r", stdin));
  assert(freopen("text.out", "w", stdout));
#endif

  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}