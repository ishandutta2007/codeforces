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

const int mod = (int) 1e9 + 7;

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
int n, m;
char c[maxn][maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%s", c[i]);
  }
  return true;
}

int sr[maxn][maxn], sd[maxn][maxn];
int dpr[maxn][maxn], dpd[maxn][maxn];
int ar[maxn][maxn], ad[maxn][maxn];

void solve() {
  if (n == 1 && m == 1) {
    printf("1\n");
    return;
  }
  memset(dpr, 0, sizeof(dpr));
  memset(dpd, 0, sizeof(dpd));
  dpr[0][0] = 1;
  dpd[0][0] = 1;
  memset(ar, 0, sizeof(ar));
  memset(ad, 0, sizeof(ad));
  for (int i = 0; i < n; i++) {
    sr[i][m - 1] = 0;
    for (int j = m - 2; j >= 0; j--) {
      sr[i][j] = sr[i][j + 1] + (c[i][j + 1] == 'R');
    }
  }
  for (int j = 0; j < m; j++) {
    sd[n - 1][j] = 0;
    for (int i = n - 2; i >= 0; i--) {
      sd[i][j] = sd[i + 1][j] + (c[i + 1][j] == 'R');
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j) {
        add(ar[i][j], ar[i][j - 1]);
      }
      if (i) {
        add(ad[i][j], ad[i - 1][j]);
      }
      add(dpr[i][j], ad[i][j]);
      add(dpd[i][j], ar[i][j]);
      {
        auto cur = dpr[i][j];
        int l = j + 1, r = m - sr[i][j];
        add(ar[i][l], cur);
        add(ar[i][r], mod - cur);
      }
      {
        auto cur = dpd[i][j];
        int l = i + 1, r = n - sd[i][j];
        add(ad[l][j], cur);
        add(ad[r][j], mod - cur);
      }
    }
  }
  int res = dpr[n - 1][m - 1];
  add(res, dpd[n - 1][m - 1]);
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