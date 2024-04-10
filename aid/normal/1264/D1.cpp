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

const int mod = 998244353;

int mul(int a, int b) {
  return (long long) a * b % mod;
}

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

const int maxn = 2005;
char tmp[maxn];
int n;
string s;

bool read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  s = tmp;
  n = sz(s);
  return true;
}

int dp[maxn][maxn][2], cnt[maxn][maxn][2];

void solve() {
  memset(dp, 0, sizeof(dp));
  memset(cnt, 0, sizeof(cnt));
  cnt[0][n][0] = 1;
  for (int len = n; len >= 1; len--) {
    for (int i = 0; i + len <= n; i++) {
      for (int t = 0; t < 2; t++) {
        int j = i + len;
        auto cur = dp[i][j][t];
        auto curcnt = cnt[i][j][t];
        if (!cur && !curcnt) {
          continue;
        }
        if (s[i] != '(' && !t) {
          auto &nxt = dp[i + 1][j][0];
          auto &nxtcnt = cnt[i + 1][j][0];
          add(nxt, cur);
          add(nxtcnt, curcnt);
        }
        if (s[i] != ')' && s[j - 1] != ')') {
          auto &nxt = dp[i][j - 1][1];
          auto &nxtcnt = cnt[i][j - 1][1];
          add(nxt, cur);
          add(nxtcnt, curcnt);
        }
        if (s[i] != ')' && s[j - 1] != '(') {
          auto &nxt = dp[i + 1][j - 1][0];
          auto &nxtcnt = cnt[i + 1][j - 1][0];
          add(nxt, cur);
          add(nxt, curcnt);
          add(nxtcnt, curcnt);
        }
      }
    }
  }
  int res = 0;
  for (int i = 0; i <= n; i++) {
    add(res, dp[i][i][0]);
    add(res, dp[i][i][1]);
  }
  printf("%d\n", res);
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