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

const int maxn = 2005;
int n, p;

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  int a, b;
  scanf("%d%d", &a, &b);
  p = mul(a, inv(b));
  return true;
}

int dp[maxn][maxn], pc[maxn], ans[maxn];
int ps[2][maxn];

void solve() {
  for (int t = 0; t < 2; t++) {
    ps[t][0] = 1;
    if (!t) {
      ps[t][1] = p;
    } else {
      ps[t][1] = 1;
      add(ps[t][1], mod - p);
    }
    for (int i = 2; i <= n; i++) {
      ps[t][i] = mul(ps[t][i - 1], ps[t][1]);
    }
  }
  for (int i = 1; i <= n; i++) {
    dp[i][0] = 1;
    for (int j = 1; j < i; j++) {
      dp[i][j] = mul(dp[i - 1][j], ps[0][j]);
      add(dp[i][j], mul(dp[i - 1][j - 1], ps[1][i - j]));
    }
    dp[i][i] = 1;
  }
  pc[1] = 1;
  for (int i = 2; i <= n; i++) {
    pc[i] = 1;
    for (int j = 1; j < i; j++) {
      add(pc[i], mod - mul(pc[j], dp[i][j]));
    }
  }
  ans[0] = 0;
  ans[1] = 0;
  for (int i = 2; i <= n; i++) {
    ans[i] = 0;
    for (int j = 1; j < i; j++) {
      int x = j * (j - 1) / 2 + j * (i - j);
      add(x, ans[j]);
      add(x, ans[i - j]);
      add(ans[i], mul(mul(pc[j], dp[i][j]), x));
    }
    int a = ans[i];
    add(a, mul(pc[i], i * (i - 1) / 2));
    int b = 1;
    add(b, mod - pc[i]);
    ans[i] = mul(a, inv(b));
  }
  printf("%d\n", ans[n]);
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