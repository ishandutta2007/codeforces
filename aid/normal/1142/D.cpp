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

const int k = 11;
int go[k][k];

void precalc() {
  int cur = 10;
  for (int r = 0; r < k; r++) {
    for (int i = 0; i < k; i++) {
      go[r][i] = -1;
    }
    for (int d = 0; d < r; d++) {
      go[r][d] = cur;
      cur = (cur + 1) % k;
    }
  }
}

const int maxn = (int) 1e5 + 5;
int n;
string s;
char tmp[maxn];

bool read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  s = tmp;
  n = sz(s);
  return true;
}

int dp[maxn][k];

void solve() {
  for (int i = 0; i < k; i++) {
    dp[n][i] = 0;
  }
  for (int i = n - 1; i >= 0; i--) {
    int d = (s[i] - '0');
    for (int r = 0; r < k; r++) {
      auto &cur = dp[i][r];
      cur = 0;
      if (go[r][d] == -1) {
        continue;
      }
      cur = 1 + dp[i + 1][go[r][d]];
    }
  }
  long long res = 0;
  for (int i = 0; i < n; i++) {
    int d = (s[i] - '0');
    if (!d) {
      continue;
    }
    res += 1 + dp[i + 1][d];
  }
  printf("%lld\n", res);
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