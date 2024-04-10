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

long long rndll(long long x) {
  return (((long long) mrand() << 31) ^ mrand()) % x;
}

void precalc() {
}

namespace Pollard {
  long long mod;

  void add(long long &a, long long b) {
    a += b;
    if (a >= mod) {
      a -= mod;
    }
  }

  long long mul(long long a, long long b) {
    long long res = a * b - (long long) ((ld) a * b / mod) * mod;
    if (res < 0) {
      res += mod;
    }
    if (res >= mod) {
      res -= mod;
    }
    return res;
  }

  long long gcd(long long a, long long b) {
    return (b ? gcd(b, a % b) : a);
  }

  long long powMod(long long x, long long p) {
    long long res = 1;
    while (p) {
      if (p & 1) {
        res = mul(res, x);
      }
      p >>= 1;
      x = mul(x, x);
    }
    return res;
  }

  const vector<long long> as = {2, 3, 5, 7, 11, 13, 17, 19, 23};

  bool isPrime(long long n) {
    if (n == 1) {
      return false;
    }
    long long x = n - 1;
    int k = 0;
    while (!(x & 1)) {
      x >>= 1;
      k++;
    }
    mod = n;
    for (auto a : as) {
      if (n == a) {
        return true;
      }
      if (!(n % a)) {
        return false;
      }
    }
    for (auto a : as) {
      long long cur = powMod(a, x);
      if (cur == 1) {
        continue;
      }
      bool found = false;
      for (int i = 0; i < k && cur != 1; i++) {
        if (cur == n - 1) {
          found = true;
          break;
        }
        cur = mul(cur, cur);
      }
      if (!found) {
        return false;
      }
    }
    return true;
  }

  void pollard(long long n, vector<long long> &f) {
    if (n == 1) {
      return;
    }
    if (isPrime(n)) {
      f.push_back(n);
      return;
    }
    mod = n;
    while (true) {
      long long x = rndll(n), y = x;
      const int m = (1 << 18), k = (1 << 7);
      bool easy = false;
      long long px = x, py = y;
      long long s = 1, d = 0;
      for (int i = 1; i < m; i++) {
        x = mul(x, x);
        add(x, 1);
        long long cur = x;
        add(cur, mod - y);
        s = mul(s, cur);
        if (!(i & (i - 1))) {
          y = x;
        }
        if (easy || !(i % k)) {
          d = gcd(s, n);
          if (!easy && d == n) {
            easy = true;
            i -= k;
            x = px;
            y = py;
          } else if (d > 1) {
            break;
          }
          s = 1;
          px = x;
          py = y;
        }
      }
      if (1 < d && d < n) {
        pollard(d, f);
        pollard(n / d, f);
        return;
      }
    }
  }

  vector<long long> fact(long long n) {
    vector<long long> f;
    for (long long d = 2; d < 100 && d * d <= n; d++) {
      while (!(n % d)) {
        f.push_back(d);
        n /= d;
      }
    }
    pollard(n, f);
    return f;
  }
}

const int maxn = (int) 2e5 + 5;
int n;
long long a[maxn];

ld t0;

bool read() {
  t0 = (double) clock() / CLOCKS_PER_SEC;
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  return true;
}

long long dist(long long x, long long p) {
  if (x < p) {
    return p - x;
  }
  x %= p;
  return min(x, p - x);
}

long long solve1(long long p) {
  long long res = 0;
  for (int i = 0; i < n; i++) {
    res += dist(a[i], p);
  }
  return res;
}

int solve2(long long x) {
  vector<long long> f = Pollard::fact(x);
  sort(f.begin(), f.end());
  f.erase(unique(f.begin(), f.end()), f.end());
  int res = n;
  for (int i = 0; i < sz(f); i++) {
    res = min((long long) res, solve1(f[i]));
  }
  return res;
}

void solve() {
  int res = n;
  while ((double) clock() / CLOCKS_PER_SEC - t0 < 2.2) {
    int i = rnd(n);
    for (int d = -1; d <= 1; d++) {
      long long cur = a[i] + d;
      if (cur > 0) {
        res = min(res, solve2(cur));
      }
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