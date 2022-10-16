#ifdef DEBUG
//#define _GLIBCXX_DEBUG
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

long long mul(long long a, long long b, long long mod) {
  long long d = (long long) ((ld) a * b / mod);
  long long res = a * b - d * mod;
  res %= mod;
  if (res < 0) {
    res += mod;
  }
  return res;
}

const long long m = (long long) 1e18;

pair<long long, long long> f(long long n) {
  if (!n) {
    return make_pair(0ll, 1ll);
  }
  if (n & 1) {
    pair<long long, long long> p = f(n - 1);
    return make_pair(p.second, (p.first + p.second) % m);
  }
  pair<long long, long long> p = f(n >> 1);
  return make_pair(mul(p.first, (2 * p.second + m - p.first) % m, m), (mul(p.first, p.first, m) + mul(p.second, p.second, m)) % m);
}

pair<long long, long long> gcd(long long a, long long b) {
  if (!b) {
    return make_pair(1, 0);
  }
  pair<long long, long long> p = gcd(b, a % b);
  return make_pair(p.second, p.first - (a / b) * p.second);
}

long long inv(long long x, long long mod) {
  long long res = gcd(x, mod).first % mod;
  if (res < 0) {
    res += mod;
  }
  return res;
}

const long long p = (long long) 1.5e9;

void precalc() {
  /*const int k = 200;
  long long ff[k];
  for (int i = 0; i < k; i++) {
    ff[i] = f(i * p).first;
    eprintf("%lld\n", ff[i]);
  }
  eprintf("\n");
  for (int i = 0; i + 1 < k; i++) {
    eprintf("%lld\n", (ff[i + 1] + m - ff[i]) % m);
  }*/
}

const long long x = 168354898 / 2;
const long long invx = inv(x, (long long) 1e9);

long long n, a, d;

bool read() {
  if (scanf("%lld%lld%lld", &n, &a, &d) < 3) {
    return false;
  }
  return true;
}

void solve() {
  a *= 5;
  d *= 5;
  long long b = (a * invx) % (long long) 1e9;
  long long e = (d * invx) % (long long) 1e9;
  b *= p;
  e *= p;
  printf("%lld %lld\n", b, e);
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