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

int sum(int a, int b) {
  add(a, b);
  return a;
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

int inv[105];

void precalc() {
  inv[1] = 1;
  for (int i = 2; i < 100; i++) {
    inv[i] = (mod - (long long) (mod / i) * inv[mod % i] % mod) % mod;
  }
}

long long m;

int read() {
  if (scanf("%lld", &m) < 1) {
    return false;
  }
  return true;
}

void solve() {
  int m1 = m % mod;
  int res = 0;
  for (long long x = 0; x * x <= m; x++) {
    long long my = (long long) (sqrt(m - x * x) - eps) - 1;
    while ((my + 1) * (my + 1) + x * x <= m) {
      my++;
    }
    int my1 = my % mod;
    int x1 = x % mod;
    int cur = 0;
    int s6 = 0;
    add(s6, mul(6, powMod(my1, 7)));
    add(s6, mul(21, powMod(my1, 6)));
    add(s6, mul(21, powMod(my1, 5)));
    add(s6, mod - mul(7, powMod(my1, 3)));
    add(s6, my1);
    s6 = mul(s6, inv[21]);
    add(cur, mul(mul(2, inv[3]), s6));
    int s4 = 0;
    add(s4, mul(6, powMod(my1, 5)));
    add(s4, mul(15, powMod(my1, 4)));
    add(s4, mul(10, powMod(my1, 3)));
    add(s4, mod - my1);
    s4 = mul(s4, inv[15]);
    int tomul = 0;
    add(tomul, mul(2, mul(x1, x1)));
    add(tomul, mod - m1);
    add(tomul, mod - 2);
    add(cur, mul(tomul, s4));
    int s2 = 0;
    add(s2, mul(2, powMod(my1, 3)));
    add(s2, mul(3, mul(my1, my1)));
    add(s2, my1);
    s2 = mul(s2, inv[3]);
    tomul = 0;
    add(tomul, mul(2, powMod(x1, 4)));
    add(tomul, mod - mul(mul(2, mul(x1, x1)), sum(m1, 2)));
    add(tomul, m1);
    add(tomul, mul(4, inv[3]));
    add(cur, mul(tomul, s2));
    tomul = 0;
    add(tomul, mul(mul(2, inv[3]), powMod(x1, 6)));
    add(tomul, mod - mul(sum(m1, 2), powMod(x1, 4)));
    add(tomul, mul(sum(m1, mul(4, inv[3])), mul(x1, x1)));
    add(tomul, mul(powMod(m1, 3), inv[3]));
    add(tomul, mul(m1, m1));
    add(tomul, mul(mul(2, inv[3]), m1));
    add(cur, mul(tomul, sum(mul(2, my1), 1)));
    if (!x) {
      cur = mul(cur, inv[2]);
    }
    add(res, cur);
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