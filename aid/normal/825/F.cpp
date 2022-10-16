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

const int maxn = 8005;
int len[maxn];

void precalc() {
  for (int i = 1; i < maxn; i++) {
    auto &cur = len[i];
    int x = i;
    while (x) {
      x /= 10;
      cur++;
    }
  }
}

int n;
char s[maxn];

int read() {
  if (scanf("%s", s) < 1) {
    return false;
  }
  n = strlen(s);
  return true;
}

int dp[maxn];
int p[maxn];

void getP(char *s, int n) {
  p[0] = -1;
  p[1] = 0;
  for (int i = 1; i < n; i++) {
    auto &x = p[i + 1];
    for (x = p[i]; x >= 0 && s[x] != s[i]; x = p[x]) ;
    x++;
  }
}

void solve() {
  for (int i = 0; i <= n; i++) {
    dp[i] = inf;
  }
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    getP(s + i, n - i);
    for (int j = i + 1; j <= n; j++) {
      int per = j - i - p[j - i];
      if (!((j - i) % per)) {
        int k = (j - i) / per;
        dp[j] = min(dp[j], dp[i] + len[k] + per);
      }
      dp[j] = min(dp[j], dp[i] + 1 + j - i);
    }
  }
  printf("%d\n", dp[n]);
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