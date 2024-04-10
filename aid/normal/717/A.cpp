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
#define sz(x) ((int)(x).size())
#define TASK "text"

const int inf = (int)1.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld)-1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int mod = (int) 1e9 + 7;

int add(int a, int b) {
  int res = a + b;
  if (res >= mod) {
    res -= mod;
  }
  return res;
}

int sub(int a, int b) {
  int res = a - b;
  if (res < 0) {
    res += mod;
  }
  return res;
}

int mul(int a, int b) {
  return (long long)a * b % mod;
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
  if (res < 0) {
    res += mod;
  }
  return res;
}

pair<int, int> intersect(int a0, int b0, int c0,
                         int a1, int b1, int c1) {
  int d = inv(sub(mul(a0, b1), mul(a1, b0)));
  return make_pair(mul(sub(mul(c0, b1), mul(c1, b0)), d),
                   mul(sub(mul(a0, c1), mul(a1, c0)), d));
}

struct Num {
  int a, b;

  Num() {}

  Num(int _a, int _b): a(_a), b(_b) {}

  Num operator +(const Num &n) const {
    return Num(add(a, n.a), add(b, n.b));
  }

  Num operator -(const Num &n) const {
    return Num(sub(a, n.a), sub(b, n.b));
  }

  Num operator *(const Num &n) const {
    return Num(add(mul(b, n.a), mul(a, n.b)), add(mul(5, mul(a, n.a)), mul(b, n.b)));
  }

  Num inv() const {
    pair<int, int> p = intersect(b, a, 0, mul(5, a), b, 1);
    return Num(p.first, p.second);
  }

  Num operator /(const Num &n) const {
    return *this * n.inv();
  }
};

Num powMod(Num x, long long n) {
  Num res(0, 1);
  while (n) {
    if (n & 1ll) {
      res = res * x;
    }
    n >>= 1ll;
    x = x * x;
  }
  return res;
}

int k;
long long l, r;

int read() {
  if (scanf("%d%lld%lld", &k, &l, &r) < 3) {
    return false;
  }
  return true;
}

const int maxk = 205;
Num phi[maxk], psi[maxk];
int sf[maxk], cc[maxk][maxk], c[maxk][maxk];

int solve(int k, long long n) {
  phi[0] = Num(0, 1);
  phi[1] = Num(1, 1) / Num(0, 2);
  for (int i = 2; i <= k; i++) {
    phi[i] = phi[i - 1] * phi[1];
  }
  psi[0] = Num(0, 1);
  psi[1] = Num(mod - 1, 1) / Num(0, 2);
  for (int i = 2; i <= k; i++) {
    psi[i] = psi[i - 1] * psi[1];
  }
  for (int i = 0; i <= k; i++) {
    cc[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      cc[i][j] = add(cc[i - 1][j - 1], cc[i - 1][j]);
    }
  }
  sf[0] = n % mod;
  for (int i = 1; i <= k; i++) {
    Num x(0, 0);
    for (int j = 0; j <= i; j++) {
      Num d = phi[i - j] * psi[j];
      Num y;
      if (d.a == 0 && d.b == 1) {
        y = Num(0, n % mod);
      }
      else {
        y = (Num(0, 1) - powMod(d, n + 1)) / (Num(0, 1) - d);
      }
      y = y * Num(0, cc[i][j]);
      if (j & 1) {
        y = y * Num(0, mod - 1);
      }
      x = x + y;
    }
    sf[i] = (x / powMod(Num(1, 0), i)).b;
  }
  c[0][0] = 1;
  for (int i = 1; i <= k; i++) {
    c[i][0] = 0;
    for (int j = 1; j <= i; j++) {
      c[i][j] = add(c[i - 1][j - 1], mul((mod - i + 1) % mod, c[i - 1][j]));
    }
  }
  int res = 0;
  for (int i = 0; i <= k; i++) {
    res = add(res, mul(c[k][i], sf[i]));
  }
  for (int i = 1; i <= k; i++) {
    res = mul(res, inv(i));
  }
  return res;
}

void solve() {
  l += 2;
  r += 2;
  printf("%d\n", sub(solve(k, r), solve(k, l - 1)));
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
    eprintf("Time %.2f\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}