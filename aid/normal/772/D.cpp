#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define sz(s) ((int) ((s).size()))

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

typedef long long ll;
typedef long double ld;

const int inf = (int) 1.01e9;
const ld eps = 1e-11;
const ld pi = acos(-1.0L);

mt19937 mrand(random_device{} ());
int rnd(int x) {
  return mrand() % x;
}

const int mod = (int) 1e9 + 7;

void add(int & x, int y) {
  if ((x += y) >= mod) {
    x -= mod;
  }
}

int mult(int x, int y) {
  return (ll) x * y % mod;
}

int power(int x, ll p) {
  int res = 1;
  while (p) {
    if (p & 1) {
      res = mult(res, x);
    }
    x = mult(x, x);
    p >>= 1;
  }
  return res;
}

int inv(int x) {
  return power(x, mod - 2);
}

const int maxn = 1e6;

const int k = 6;
int prec[1 << k];
int pws[maxn + 100];

void precalc() {
  pws[0] = 1;
  for (int i = 1; i < maxn + 100; i++) {
    pws[i] = mult(pws[i - 1], 2);
  }
  for (int mask = 0; mask < (1 << k); mask++) {
    int cur = 0;
    int toadd = 1;
    for (int j = 0; j < k; j++) {
      if (mask & (1 << j)) {
        cur += toadd;
      }
      toadd *= 10;
    }
    prec[mask] = cur;
  }
}

int n;
int a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  return true;
}

int cnt[maxn], sum[maxn], dp[maxn];
int ncnt[maxn], nsum[maxn], ndp[maxn];

void solve() {
  memset(cnt, 0, sizeof(cnt));
  memset(sum, 0, sizeof(sum));
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++) {
    cnt[a[i]]++;
  }
  for (int i = 0; i < maxn; i++) {
    sum[i] = mult(cnt[i], i);
    dp[i] = mult((ll) cnt[i] * (cnt[i] + 1) / 2 % mod, mult(i, i));
  }
  for (int it = 0; it < 6; it++) {
    memset(ncnt, 0, sizeof(ncnt));
    memset(nsum, 0, sizeof(nsum));
    memset(ndp, 0, sizeof(ndp));
    int tomult = 1;
    for (int i = 0; i < it; i++) {
      tomult *= 10;
    }
    for (int i = 0; i < maxn; i++) {
      int from = (i / tomult) % 10;
      for (int j = i, it = from; it < 10; it++, j += tomult) {
        ncnt[i] += cnt[j];
        add(ndp[i], dp[j]);
        add(ndp[i], mult(nsum[i], sum[j]));
        add(nsum[i], sum[j]);
      }
    }
    for (int i = 0; i < maxn; i++) {
      cnt[i] = ncnt[i];
      sum[i] = nsum[i];
      dp[i] = ndp[i];
    }
  }
  for (int i = 0; i < maxn; i++) {
    dp[i] = mult(dp[i], pws[cnt[i] - 1]);
  }
  ll res = 0;
  for (int i = 1; i < maxn; i++) {
    int cur = 0;
    int all = 0;
    for (int j = 0, cur = 1; j < k; j++) {
      if (i / cur % 10 < 9) {
        all ^= 1 << j;
      }
      cur *= 10;
    }
    for (int mask = 0; mask < (1 << k); mask++) {
      if ((mask & all) != mask) {
        continue;
      }
      int j = i + prec[mask];
      if (__builtin_popcount(mask) & 1) {
        add(cur, mod - dp[j]);
      } else {
        add(cur, dp[j]);
      }
    }
    res ^= (ll) cur * i;
  }
  printf("%lld\n", res);
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen("text.in", "r", stdin));
  assert(freopen("text.out", "w", stdout));
#endif

  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time: %.3f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}