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
int f[maxn];
int der[maxn];
int pder[maxn][maxn];
int dp[maxn][maxn];

void precalc() {
  f[0] = 1;
  for (int i = 1; i < maxn; i++) {
    f[i] = mul(f[i - 1], i);
  }
  der[0] = 1;
  der[1] = 0;
  for (int i = 2; i < maxn; i++) {
    der[i] = der[i - 1];
    add(der[i], der[i - 2]);
    der[i] = mul(der[i], i - 1);
  }
  for (int i = 0; i < maxn; i++) {
    pder[i][0] = 1;
    for (int j = 1; j < maxn; j++) {
      pder[i][j] = mul(pder[i][j - 1], der[i]);
    }
  }
  for (int i = 0; i < maxn; i++) {
    dp[i][0] = f[i];
    for (int j = 1; j <= i; j++) {
      dp[i][j] = mul(i - j, dp[i - 1][j - 1]);
      if (j >= 2) {
        int x = dp[i - 1][j - 1];
        add(x, dp[i - 2][j - 2]);
        add(dp[i][j], mul(j - 1, x));
      }
    }
  }
}

int n;
int a[maxn][maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
      a[i][j]--;
    }
  }
  return true;
}

int b[2][maxn];
int fen[3][maxn];
int k;

void update(int t, int i, int val) {
  for (; i < n; i |= i + 1) {
    fen[t][i] += val;
  }
}

int get(int t, int i) {
  int res = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    res += fen[t][i];
  }
  return res;
}

void upd(int t, int x) {
  if (!b[0][x] && !b[1][x]) {
    update(2, x, 1);
    k--;
  }
  b[t][x] = true;
  update(t, x, 1);
}

void solve() {
  int res = 0;
  for (int i = 0; i < n; i++) {
    memset(b, 0, sizeof(b));
    memset(fen, 0, sizeof(fen));
    if (!i) {
      for (int j = 0; j < n; j++) {
        int cnt = a[i][j] - get(0, a[i][j] - 1);
        int cur = mul(cnt, f[n - j - 1]);
        cur = mul(cur, pder[n][n - i - 1]);
        add(res, cur);
        update(0, a[i][j], 1);
      }
      continue;
    }
    k = n;
    for (int j = 0; j < n; j++) {
      int cur = 0;
      {
        int cnt = a[i][j] - get(2, a[i][j] - 1);
        int val = 0;
        if (!b[0][a[i - 1][j]]) {
          val = dp[n - j - 1][k - 1];
          if (k >= 2) {
            add(val, dp[n - j - 2][k - 2]);
          }
          val = mul(cnt - (a[i - 1][j] < a[i][j]), val);
        } else {
          val = dp[n - j - 1][k - 1];
          val = mul(cnt, val);
        }
        add(cur, val);
      }
      {
        int cnt = get(2, a[i][j] - 1) - get(0, a[i][j] - 1);
        int val = 0;
        if (!b[0][a[i - 1][j]]) {
          val = dp[n - j - 1][k - 1];
          val = mul(cnt, val);
        } else {
          val = dp[n - j - 1][k];
          val = mul(cnt, val);
        }
        add(cur, val);
      }
      cur = mul(cur, pder[n][n - i - 1]);
      add(res, cur);
      upd(0, a[i][j]);
      upd(1, a[i - 1][j]);
    }
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