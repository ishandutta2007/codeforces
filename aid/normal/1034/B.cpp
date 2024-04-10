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

const int gox[] = {3, 2, 1, 0, -1, -2, -3, -2, -1, 0, 1, 2};
const int goy[] = {0, 1, 2, 3, 2, 1, 0, -1, -2, -3, -2, -1};
const int k = 6;
int ans[2 * k + 1][2 * k + 1];
int used[2 * k + 1][2 * k + 1];

bool inside(int n, int m, int x, int y) {
  return 0 <= x && x < n && 0 <= y && y < m;
}

int gen(int n, int m, int dep, int x, int y) {
  int mx = n * m - (n * m % 2);
  int res = dep;
  while (res < mx) {
    while (x < n && used[x][y]) {
      y++;
      if (y >= m) {
        x++;
        y = 0;
      }
    }
    if (x >= n) {
      return res;
    }
    for (int dir = 0; dir < 12; dir++) {
      int nx = x + gox[dir], ny = y + goy[dir];
      if (!inside(n, m, nx, ny) || nx < x || (nx == x && ny < y) || used[nx][ny]) {
        continue;
      }
      used[x][y] = true;
      used[nx][ny] = true;
      res = max(res, gen(n, m, dep + 2, x, y));
      used[x][y] = false;
      used[nx][ny] = false;
    }
    y++;
    if (y >= m) {
      x++;
      y = 0;
    }
  }
  return res;
}

void precalc() {
  for (int n = 1; n < 2 * k; n++) {
    for (int m = n; m < 2 * k; m++) {
      for (int i = 1; i < m; i++) {
        ans[n][m] = max(ans[n][m], ans[n][i] + ans[n][m - i]);
      }
      int mx = n * m - (n * m % 2);
      if (ans[n][m] < mx) {
        ans[n][m] = gen(n, m, 0, 0, 0);
      }
      eprintf("%d %d %d\n", n, m, ans[n][m]);
      ans[m][n] = ans[n][m];
      if (n >= k) {
        assert(ans[n][m] == mx);
      }
    }
  }
}

int n, m;

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  return true;
}

void solve() {
  if (n > m) {
    swap(n, m);
  }
  long long mx = (long long) n * m - ((long long) n * m % 2);
  if (n >= 3) {
    printf("%lld\n", mx);
    return;
  }
  if (n == 2) {
    if (m == 2) {
      printf("0\n");
      return;
    }
    if (m == 3) {
      printf("4\n");
      return;
    }
    if (m == 7) {
      printf("12\n");
      return;
    }
    printf("%lld\n", mx);
    return;
  }
  int res = (m / 6) * 6;
  m %= 6;
  if (m > 3) {
    res += 2 * (m - 3);
  }
  printf("%d\n", res);
}

int main() {
  //precalc();
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