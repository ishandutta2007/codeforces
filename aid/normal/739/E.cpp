#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
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

const int maxn = (int) 2e3 + 5;
int n, cnta, cntb;
ld a[maxn], b[maxn], c[maxn];

int read() {
  if (scanf("%d%d%d", &n, &cnta, &cntb) < 3) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    double x;
    scanf("%lf", &x);
    a[i] = x;
  }
  for (int i = 0; i < n; i++) {
    double x;
    scanf("%lf", &x);
    b[i] = x;
  }
  return true;
}

ld dp[maxn][maxn];
int p[maxn][maxn];

bool check(ld x) {
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= cnta; j++) {
      dp[i][j] = -inf;
      p[i][j] = -1;
    }
  }
  dp[0][0] = 0;
  p[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= cnta; j++) {
      if (p[i][j] == -1) {
        continue;
      }
      if (dp[i][j] > dp[i + 1][j]) {
        dp[i + 1][j] = dp[i][j];
        p[i + 1][j] = p[i][j];
      }
      if (dp[i][j] + b[i] + x > dp[i + 1][j]) {
        dp[i + 1][j] = dp[i][j] + b[i] + x;
        p[i + 1][j] = p[i][j] + 1;
      }
      if (dp[i][j] + a[i] > dp[i + 1][j + 1]) {
        dp[i + 1][j + 1] = dp[i][j] + a[i];
        p[i + 1][j + 1] = p[i][j];
      }
      if (dp[i][j] + c[i] + x > dp[i + 1][j + 1]) {
        dp[i + 1][j + 1] = dp[i][j] + c[i] + x;
        p[i + 1][j + 1] = p[i][j] + 1;
      }
    }
  }
  return p[n][cnta] <= cntb;
}

void solve() {
  for (int i = 0; i < n; i++) {
    c[i] = a[i] + b[i] - a[i] * b[i];
  }
  ld l = -1e4, r = 1e4;
  for (int it = 0; it < 50; it++) {
    ld m = (l + r) / 2;
    if (check(m)) {
      l = m;
    } else {
      r = m;
    }
  }
  check(l);
  printf("%.20f\n", (double) (dp[n][cnta] - l * cntb));
}

int main() {
  precalc();
#ifdef LOCAL
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}