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

const int maxn = 55, maxt = 5005;
int n, tmax;
int f[maxn], s[maxn];
ld p[maxn];

int read() {
  if (scanf("%d%d", &n, &tmax) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    int pp;
    scanf("%d%d%d", &f[i], &s[i], &pp);
    p[i] = (ld) pp / 100;
  }
  return true;
}

ld dp[maxn][maxt];

bool check(ld x) {
  for (int i = 0; i <= n; i++) {
    for (int t = 0; t <= tmax; t++) {
      dp[i][t] = -1;
    }
  }
  for (int t = 0; t <= tmax; t++) {
    dp[n][t] = 0;
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int t = 0; t < tmax; t++) {
      auto &cur = dp[i][t];
      cur = 0;
      for (int it = 0; it < 2; it++) {
        int addt = (!it ? f[i] : s[i]);
        int nt = t + addt;
        ld pr = (!it ? p[i] : 1 - p[i]);
        ld val = addt + ((nt > tmax || dp[i + 1][nt] < 0) ? x : min(x, dp[i + 1][nt]));
        cur += pr * val;
      }
    }
  }
  return dp[0][0] > x;
}

void solve() {
  ld l = 0, r = 1e10;
  for (int it = 0; it < 100; it++) {
    ld m = (l + r) / 2;
    if (check(m)) {
      l = m;
    } else {
      r = m;
    }
  }
  printf("%.12f\n", (double) r);
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