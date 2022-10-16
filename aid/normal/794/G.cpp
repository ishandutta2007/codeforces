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

int gcd(int a, int b) {
  return (b ? gcd(b, a % b) : a);
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

const int maxn = (int) 6e5 + 5;
int f[maxn], inv[maxn], finv[maxn];
int p2[maxn];

void precalc() {
  f[0] = 1;
  for (int i = 1; i < maxn; i++) {
    f[i] = mul(f[i - 1], i);
  }
  inv[1] = 1;
  for (int i = 2; i < maxn; i++) {
    inv[i] = (mod - (long long) (mod / i) * inv[mod % i] % mod) % mod;
  }
  finv[0] = 1;
  for (int i = 1; i < maxn; i++) {
    finv[i] = mul(finv[i - 1], inv[i]);
  }
  p2[0] = 1;
  for (int i = 1; i < maxn; i++) {
    p2[i] = mul(p2[i - 1], 2);
  }
}

int c(int n, int k) {
  return mul(f[n], mul(finv[k], finv[n - k]));
}

int n;
string s, t;
char tmp[maxn];

int read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  s = tmp;
  scanf("%s", tmp);
  t = tmp;
  scanf("%d", &n);
  return true;
}

int dp[maxn];

void solve() {
  int x0 = 0, y0 = 0;
  int qs = 0, qt = 0;
  for (int i = 0; i < sz(s); i++) {
    if (s[i] == 'A') {
      x0++;
    } else if (s[i] == 'B') {
      y0++;
    } else {
      qs++;
    }
  }
  for (int i = 0; i < sz(t); i++) {
    if (t[i] == 'A') {
      x0--;
    } else if (t[i] == 'B') {
      y0--;
    } else {
      qt++;
    }
  }
  int d = x0 + y0 + qs - qt;
  if (d) {
    int res = 0;
    int xl = x0 - qt, xr = x0 + qs;
    for (int x = xl; x <= xr; x++) {
      int y = d - x;
      if ((x <= 0 && y <= 0) || (x >= 0 && y >= 0)) {
        continue;
      }
      int p = abs(x), q = abs(y);
      {
        int g = gcd(p, q);
        p /= g;
        q /= g;
      }
      int maxk = n / max(p, q);
      int cnt = p2[maxk + 1];
      add(cnt, mod - 2);
      add(res, mul(c(xr - xl, x - xl), cnt));
    }
    printf("%d\n", res);
    return;
  }
  int res = 0;
  int xl = x0 - qt, xr = x0 + qs;
  int c0 = 0, c1 = p2[xr - xl];
  if (xl <= 0 && 0 <= xr) {
    c0 = c(xr - xl, 0 - xl);
    add(c1, mod - c0);
  }
  {
    int maxk = n;
    int cnt = p2[maxk + 1];
    add(cnt, mod - 2);
    add(res, mul(c1, cnt));
  }
  int res0 = 0;
  for (int i = n; i > 0; i--) {
    auto &cur = dp[i];
    cur = n / i;
    cur = mul(cur, cur);
    for (int j = 2 * i; j <= n; j += i) {
      add(cur, mod - dp[j]);
    }
    add(res0, mul(p2[i], cur));
  }
  add(res, mul(c0, res0));
  if (sz(s) == sz(t)) {
    bool eq = true;
    int cnt = 0;
    for (int i = 0; i < sz(s); i++) {
      if (s[i] == '?') {
        if (t[i] == '?') {
          cnt++;
        }
      } else {
        if (t[i] != '?' && t[i] != s[i]) {
          eq = false;
          break;
        }
      }
    }
    if (eq) {
      add(res, mod - mul(p2[cnt], res0));
      int val = p2[n + 1];
      add(val, mod - 2);
      add(res, mul(p2[cnt], mul(val, val)));
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