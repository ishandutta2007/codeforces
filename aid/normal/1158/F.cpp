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

pair<int, int> gcd(int a, int b) {
  if (!b) {
    return make_pair(1, 0);
  }
  pair<int, int> p = gcd(b, a % b);
  return make_pair(p.second, p.first - (a / b) * p.second);
}

int inv(int x) {
  int res = gcd(x, mod).first;
  res %= mod;
  if (res < 0) {
    res += mod;
  }
  return res;
}

const int maxn = 3005;
int subs[maxn], subsinv[maxn];

void precalc() {
  subs[0] = 1;
  for (int i = 1; i < maxn; i++) {
    subs[i] = mul(subs[i - 1], 2);
  }
  for (int i = 0; i < maxn; i++) {
    add(subs[i], mod - 1);
  }
  for (int i = 1; i < maxn; i++) {
    subsinv[i] = inv(subs[i]);
  }
}

int n, c;
int a[maxn];

bool read() {
  if (scanf("%d%d", &n, &c) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i]--;
  }
  return true;
}

int go[maxn][maxn];
int cnt[maxn];
int dp[maxn][maxn];
int ans[maxn];

void solveCube() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < c; j++) {
      cnt[j] = 0;
    }
    int bad = c;
    go[i][i] = 0;
    int cur = 1;
    for (int j = i; j < n; j++) {
      if (cnt[a[j]]) {
        cur = mul(cur, subsinv[cnt[a[j]]]);
      } else {
        bad--;
      }
      go[i][j + 1] = (bad ? 0 : cur);
      cnt[a[j]]++;
      cur = mul(cur, subs[cnt[a[j]]]);
    }
  }
  memset(dp, 0, sizeof(dp));
  memset(ans, 0, sizeof(ans));
  dp[0][0] = 1;
  for (int it = 0;; it++) {
    bool found = false;
    for (int i = 0; i <= n; i++) {
      auto cur = dp[it][i];
      if (!cur) {
        continue;
      }
      found = true;
      for (int j = i + 1; j <= n; j++) {
        add(dp[it + 1][j], mul(cur, go[i][j]));
      }
    }
    if (!found) {
      break;
    }
    for (int i = 0; i <= n; i++) {
      auto cur = dp[it][i];
      int tomul = subs[n - i];
      add(tomul, 1);
      add(ans[it], mul(cur, tomul));
    }
  }
  for (int i = 0; i < n; i++) {
    add(ans[i], mod - ans[i + 1]);
  }
  add(ans[0], mod - 1);
  for (int i = 0; i <= n; i++) {
    printf("%d ", ans[i]);
  }
  printf("\n");
}

void solve() {
  if (c > 11) {
    solveCube();
    return;
  }
  memset(ans, 0, sizeof(ans));
  ans[0] = subs[n];
  add(ans[0], 1);
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int it = 0;; it++) {
    bool found = false;
    for (int i = 0; i < n; i++) {
      for (int msk = 0; msk < (1 << c) - 1; msk++) {
        auto cur = dp[i][msk];
        if (!cur) {
          continue;
        }
        found = true;
        add(dp[i + 1][msk], cur);
        add(dp[i + 1][msk | (1 << a[i])], cur);
      }
    }
    if (!found) {
      break;
    }
    for (int i = 0; i <= n; i++) {
      auto cur = dp[i][(1 << c) - 1];
      for (int j = 0; j < (1 << c); j++) {
        dp[i][j] = 0;
      }
      dp[i][0] = cur;
      int tomul = subs[n - i];
      add(tomul, 1);
      add(ans[it + 1], mul(cur, tomul));
    }
  }
  for (int i = 0; i < n; i++) {
    add(ans[i], mod - ans[i + 1]);
  }
  add(ans[0], mod - 1);
  for (int i = 0; i <= n; i++) {
    printf("%d ", ans[i]);
  }
  printf("\n");
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