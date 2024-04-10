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

const int maxn = (int) 2e5 + 5;
int n, m;
long long a[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  return true;
}

const int maxm = 60;
int k;
int bit[maxm];
long long x[maxm];
int bad[maxm];
long long y[maxm];
int ans[maxm];
const int K = 16, PK = (1 << K);
int dp[maxm][PK];

bool addVec(long long a) {
  for (int i = 0; i < k; i++) {
    if (a & (1ll << bit[i])) {
      a ^= x[i];
    }
  }
  if (!a) {
    return false;
  }
  auto &b = bit[k];
  b = 0;
  while (!(a & (1ll << b))) {
    b++;
  }
  for (int i = 0; i < k; i++) {
    if (x[i] & (1ll << b)) {
      x[i] ^= a;
    }
  }
  x[k] = a;
  k++;
  return true;
}

void solve() {
  for (int i = 0; i <= m; i++) {
    ans[i] = 0;
  }
  k = 0;
  int tomul = 1;
  for (int i = 0; i < n; i++) {
    if (!addVec(a[i])) {
      tomul = mul(tomul, 2);
    }
  }
  if (k <= 20) {
    for (int msk = 0; msk < (1 << k); msk++) {
      long long cur = 0;
      for (int i = 0; i < k; i++) {
        if (msk & (1 << i)) {
          cur ^= x[i];
        }
      }
      ans[__builtin_popcountll(cur)]++;
    }
  } else {
    for (int i = 0; i < m; i++) {
      bad[i] = false;
    }
    for (int i = 0; i < k; i++) {
      bad[bit[i]] = true;
    }
    for (int i = 0; i < k; i++) {
      y[i] = 0;
      int pos = 0;
      for (int j = 0; j < m; j++) {
        if (bad[j]) {
          continue;
        }
        int cur = ((x[i] >> j) & 1);
        y[i] |= (cur << pos);
        pos++;
      }
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i < k; i++) {
      for (int j = i; j >= 0; j--) {
        for (int msk = 0; msk < (1 << (m - k)); msk++) {
          auto cur = dp[j][msk];
          if (!cur) {
            continue;
          }
          add(dp[j + 1][msk ^ y[i]], cur);
        }
      }
    }
    for (int i = 0; i <= k; i++) {
      for (int msk = 0; msk < (1 << (m - k)); msk++) {
        auto cur = dp[i][msk];
        if (!cur) {
          continue;
        }
        add(ans[i + __builtin_popcount(msk)], cur);
      }
    }
  }
  for (int i = 0; i <= m; i++) {
    ans[i] = mul(ans[i], tomul);
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