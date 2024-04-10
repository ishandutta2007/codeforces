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

const int maxn = (int) 2e5 + 5, maxk = 2005, maxcnt = 22, mod = (int) 1e9 + 7;
int inv[maxn], f[maxn], finv[maxn];
int n, m, k, s;
pair<int, int> p[maxk];

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

int mul(int a, int b) {
  return (long long) a * b % mod;
}

void precalc() {
  inv[1] = 1;
  for (int i = 2; i < maxn; i++) {
    inv[i] = (mod - mul(mod / i, inv[mod % i])) % mod;
  }
  f[0] = 1;
  for (int i = 1; i < maxn; i++) {
    f[i] = mul(f[i - 1], i);
  }
  finv[0] = 1;
  for (int i = 1; i < maxn; i++) {
    finv[i] = mul(finv[i - 1], inv[i]);
  }
}

int c(int n, int k) {
  return mul(f[n], mul(finv[k], finv[n - k]));
}

int read() {
  if (scanf("%d%d%d%d", &n, &m, &k, &s) < 4) {
    return false;
  }
  for (int i = 0; i < k; i++) {
    scanf("%d%d", &p[i].first, &p[i].second);
    p[i].first--;
    p[i].second--;
  }
  return true;
}

int x[maxk], y[maxk];
int dp[maxk][maxcnt];

void solve() {
  sort(p, p + k);
  if (p[k - 1] != make_pair(n - 1, m - 1)) {
    s *= 2;
    p[k++] = make_pair(n - 1, m - 1);
  }
  for (int i = 0; i < k; i++) {
    x[i] = p[i].first;
    y[i] = p[i].second;
  }
  for (int i = 0; i < k; i++) {
    dp[i][0] = 0;
    for (int j = 1; j < maxcnt; j++) {
      dp[i][j] = c(x[i] + y[i], x[i]);
      for (int pi = 0; pi < i; pi++) {
        if (x[pi] <= x[i] && y[pi] <= y[i]) {
          add(dp[i][j], mod - mul(dp[pi][j], c(x[i] - x[pi] + y[i] - y[pi], x[i] - x[pi])));
        }
      }
    }
    for (int j = maxcnt - 1; j > 0; j--) {
      add(dp[i][j], mod - dp[i][j - 1]);
    }
  }
  int res = 0;
  int all = c(n - 1 + m - 1, n - 1);
  for (int i = 0; i < maxcnt; i++) {
    add(res, mul(s, dp[k - 1][i]));
    add(all, mod - dp[k - 1][i]);
    s = (s + 1) / 2;
  }
  add(res, all);
  res = mul(res, mul(mul(f[n - 1], f[m - 1]), finv[n - 1 + m - 1]));
  printf("%d\n", res);
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