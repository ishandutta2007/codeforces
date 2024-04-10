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

const int maxm = 60;
int c[maxm][maxm];

void precalc() {
  for (int i = 0; i < maxm; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      c[i][j] = c[i - 1][j - 1];
      add(c[i][j], c[i - 1][j]);
    }
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

int k;
int bit[maxm];
long long x[maxm];
int l;
long long y[maxm];
int ans[maxm];
int ans0[maxm];

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

void rec(int i, long long cur) {
  if (i >= k) {
    ans[__builtin_popcountll(cur)]++;
    return;
  }
  rec(i + 1, cur);
  rec(i + 1, cur ^ x[i]);
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
  if (k <= m / 2) {
    rec(0, 0ll);
  } else {
    l = 0;
    for (int i = 0; i < m; i++) {
      {
        bool found = false;
        for (int j = 0; j < k; j++) {
          if (bit[j] == i) {
            found = true;
            break;
          }
        }
        if (found) {
          continue;
        }
      }
      auto &cur = y[l++];
      cur = (1ll << i);
      for (int j = 0; j < k; j++) {
        if (x[j] & (1ll << i)) {
          cur |= (1ll << bit[j]);
        }
      }
    }
    swap(x, y);
    swap(k, l);
    rec(0, 0ll);
    for (int i = 0; i <= m; i++) {
      ans0[i] = ans[i];
      ans[i] = 0;
    }
    int inv2 = (mod + 1) / 2;
    int todiv = 1;
    for (int i = 0; i < k; i++) {
      todiv = mul(todiv, inv2);
    }
    for (int i = 0; i <= m; i++) {
      for (int j = 0; j <= m; j++) {
        int cur = 0;
        for (int cnt = 0; cnt <= i && cnt <= j; cnt++) {
          int x = mul(c[j][cnt], c[m - j][i - cnt]);
          if (cnt & 1) {
            x = mul(x, mod - 1);
          }
          add(cur, x);
        }
        cur = mul(cur, ans0[j]);
        add(ans[i], cur);
      }
      ans[i] = mul(ans[i], todiv);
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