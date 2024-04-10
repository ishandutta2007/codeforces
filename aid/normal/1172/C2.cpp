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

pair<int, int> gcd(int a, int b) {
  if (!b) {
    return make_pair(1, 0);
  }
  pair<int, int> p = gcd(b, a % b);
  return make_pair(p.second, p.first - (a / b) * p.second);
}

int inv(int x) {
  int res = gcd(x, mod).first % mod;
  if (res < 0) {
    res += mod;
  }
  return res;
}

const int maxn = (int) 2e5 + 5, maxm = 3005;
int n, m;
int a[maxn], w[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &w[i]);
  }
  return true;
}


int invs[4 * maxm];
int x[2];
int dp[maxm][maxm];

void solve() {
  x[0] = 0;
  x[1] = 0;
  for (int i = 0; i < n; i++) {
    x[a[i]] += w[i];
  }
  for (int i = 0; i < 4 * maxm; i++) {
    int y = x[0] + x[1] - 2 * maxm + i;
    if (y <= 0 || y >= mod) {
      invs[i] = -1;
      continue;
    }
    invs[i] = inv(y);
  }
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int k = 0; k < m; k++) {
    for (int i = 0; i <= k; i++) {
      int j = k - i;
      auto &cur = dp[k][i];
      if (!cur) {
        continue;
      }
      int xx = x[0] - i, yy = x[1] + j;
      int q = invs[xx + yy - (x[0] + x[1] - 2 * maxm)];
      if (xx) {
        add(dp[k + 1][i + 1], mul(mul(xx, q), cur));
      }
      if (yy) {
        add(dp[k + 1][i], mul(mul(yy, q), cur));
      }
    }
  }
  int xi[2] = {(x[0] ? inv(x[0]) : -1), (x[1] ? inv(x[1]) : -1)};
  int vals[2] = {0, 0};
  for (int t = 0; t < 2; t++) {
    if (x[t] == 0) {
      continue;
    }
    for (int i = 0; i <= m; i++) {
      auto &cur = dp[m][i];
      if (!cur) {
        continue;
      }
      int cnt = (t == 0 ? i : m - i);
      int val = mul(cur, mul(cnt, xi[t]));
      if (t == 0) {
        val = mul(val, mod - 1);
      }
      add(vals[t], val);
    }
  }
  for (int i = 0; i < n; i++) {
    int res = w[i];
    add(res, mul(vals[a[i]], w[i]));
    printf("%d\n", res);
  }
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