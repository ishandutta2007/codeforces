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

const int mod = (int) 1e9 + 9;

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

pair<int, int> gcd(int a, int b) {
  if (!b) {
    return make_pair(1, 0);
  }
  pair<int, int> p = gcd(b, a % b);
  return make_pair(p.second, p.first - (a / b) * p.second);
}

int inv(int x) {
  return ((gcd(x, mod).first % mod) + mod) % mod;
}

const int maxk = (int) 1e5 + 5;
int n, a, b, k;
string s;
char tmp[maxk];

int read() {
  if (scanf("%d%d%d%d", &n, &a, &b, &k) < 4) {
    return false;
  }
  scanf("%s", tmp);
  s = tmp;
  return true;
}

void solve() {
  int x;
  {
    int p = powMod(a, n);
    add(p, mod - mul(inv(a), powMod(b, n + 1)));
    int q = 1;
    int v = powMod(mul(inv(a), b), k);
    if (v == 1) {
      x = mul(powMod(a, n), (n + 1) / k);
    } else {
      add(q, mod - v);
      x = mul(p, inv(q));
    }
  }
  int y;
  {
    y = 0;
    int ainv = inv(a);
    int cur = 1;
    for (int i = 0; i < k; i++) {
      add(y, mul((s[i] == '+' ? 1 : mod - 1), cur));
      cur = mul(cur, mul(ainv, b));
    }
  }
  int res = mul(x, y);
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