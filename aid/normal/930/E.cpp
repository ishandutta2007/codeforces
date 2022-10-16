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

int powMod(int x, int p) {
  int res = 1;
  while (p) {
    if (p & 1) {
      res = mul(res, x);
    }
    p >>= 1;
    x = mul(x, x);
  }
  return res;
}

const int maxn = (int) 4e5 + 5;
int k, n;
int ls[maxn], rs[maxn], need[maxn];

int read() {
  int a, b;
  if (scanf("%d%d%d", &k, &a, &b) < 3) {
    return false;
  }
  n = a + b;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &ls[i], &rs[i]);
    ls[i]--;
    need[i] = (i >= a);
  }
  return true;
}

vector<int> xs;
int rmin[maxn][2];
int dp[maxn][3];
int adddp[maxn][3];

void solve() {
  for (int i = 0; i < n; i++) {
    xs.push_back(ls[i]);
    xs.push_back(rs[i]);
  }
  xs.push_back(0);
  xs.push_back(k);
  sort(xs.begin(), xs.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());
  for (int i = 0; i < sz(xs); i++) {
    for (int j = 0; j < 2; j++) {
      rmin[i][j] = sz(xs);
    }
  }
  for (int i = 0; i < n; i++) {
    int x = lower_bound(xs.begin(), xs.end(), ls[i]) - xs.begin();
    int r = lower_bound(xs.begin(), xs.end(), rs[i]) - xs.begin();
    rmin[x][need[i]] = min(rmin[x][need[i]], r);
  }
  for (int i = sz(xs) - 2; i >= 0; i--) {
    for (int j = 0; j < 2; j++) {
      rmin[i][j] = min(rmin[i][j], rmin[i + 1][j]);
    }
  }
  memset(dp, 0, sizeof(dp));
  memset(adddp, 0, sizeof(adddp));
  dp[0][0] = 1;
  for (int i = 0; i < sz(xs); i++) {
    for (int j = 0; j < 3; j++) {
      if (i) {
        add(adddp[i][j], adddp[i - 1][j]);
      }
      auto &cur = dp[i][j];
      add(cur, adddp[i][j]);
      eprintf("%d %d: %d\n", xs[i], j, cur);
      if (!cur || i + 1 >= sz(xs)) {
        continue;
      }
      {
        int tomul = powMod(2, xs[i + 1] - xs[i]);
        add(tomul, mod - 2);
        add(dp[i + 1][0], mul(tomul, cur));
      }
      for (int it = 0; it < 2; it++) {
        if (it == j - 1) {
          continue;
        }
        add(adddp[i + 1][it + 1], cur);
        add(adddp[rmin[i][!it]][it + 1], mod - cur);
      }
    }
  }
  int res = 0;
  for (int i = 0; i < 3; i++) {
    eprintf("%d %d: %d\n", xs.back(), i, dp[sz(xs) - 1][i]);
    add(res, dp[sz(xs) - 1][i]);
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