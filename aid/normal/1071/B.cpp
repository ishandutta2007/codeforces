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

const int maxn = 2005;
int n, k;
char c[maxn][maxn];

int read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%s", c[i]);
  }
  return true;
}

int dp[maxn][maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dp[i][j] = -1;
    }
  }
  string ans;
  if (c[0][0] == 'a') {
    ans += c[0][0];
    dp[0][0] = k;
  } else if (k) {
    ans += 'a';
    dp[0][0] = k - 1;
  } else {
    ans += c[0][0];
    dp[0][0] = k;
  }
  for (int len = 1; len < 2 * n - 1; len++) {
    char x = 'z';
    for (int i = 0; i < n; i++) {
      int j = len - 1 - i;
      if (j < 0 || n <= j || dp[i][j] == -1) {
        continue;
      }
      if (dp[i][j]) {
        x = 'a';
        break;
      }
      if (j + 1 < n) {
        x = min(x, c[i][j + 1]);
      }
      if (i + 1 < n) {
        x = min(x, c[i + 1][j]);
      }
    }
    ans += x;
    for (int i = 0; i < n; i++) {
      int j = len - 1 - i;
      if (j < 0 || n <= j || dp[i][j] == -1) {
        continue;
      }
      if (j + 1 < n) {
        dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] - (x != c[i][j + 1]));
      }
      if (i + 1 < n) {
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] - (x != c[i + 1][j]));
      }
    }
  }
  printf("%s\n", ans.c_str());
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