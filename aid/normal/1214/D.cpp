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

const int maxn = (int) 1e6 + 5;
char tmp[maxn];
int n, m;
vector<string> c;

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  c.clear();
  c.resize(n);
  for (int i = 0; i < n; i++) {
    scanf("%s", tmp);
    c[i] = tmp;
  }
  return true;
}

bool inside(int x, int y) {
  return 0 <= x && x < n && 0 <= y && y < m;
}

vector<vector<int>> dp[2];
int cnt[2 * maxn];

void solve() {
  dp[0] = vector<vector<int>>(n, vector<int>(m, false));
  dp[0][0][0] = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!dp[0][i][j]) {
        continue;
      }
      if (inside(i, j + 1) && c[i][j + 1] == '.') {
        dp[0][i][j + 1] = true;
      }
      if (inside(i + 1, j) && c[i + 1][j] == '.') {
        dp[0][i + 1][j] = true;
      }
    }
  }
  if (!dp[0][n - 1][m - 1]) {
    printf("0\n");
    return;
  }
  dp[1] = vector<vector<int>>(n, vector<int>(m, false));
  dp[1][n - 1][m - 1] = true;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
      if (!dp[1][i][j]) {
        continue;
      }
      if (inside(i, j - 1) && c[i][j - 1] == '.') {
        dp[1][i][j - 1] = true;
      }
      if (inside(i - 1, j) && c[i - 1][j] == '.') {
        dp[1][i - 1][j] = true;
      }
    }
  }
  for (int i = 0; i < n + m - 1; i++) {
    cnt[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (dp[0][i][j] && dp[1][i][j]) {
        cnt[i + j]++;
      }
    }
  }
  for (int i = 1; i < n + m - 2; i++) {
    if (cnt[i] == 1) {
      printf("1\n");
      return;
    }
  }
  printf("2\n");
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