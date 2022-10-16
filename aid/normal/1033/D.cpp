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

const int mod = 998244353;

int mul(int a, int b) {
  return (long long) a * b % mod;
}

long long gcd(long long a, long long b) {
  return (b ? gcd(b, a % b) : a);
}

const int maxn = 505;
int n;
long long a[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  return true;
}

map<long long, int> pr, comp;

void addPrime(long long p, int k) {
  if (pr.count(p)) {
    pr[p] += k;
    return;
  }
  pr[p] += k;
  for (auto it = comp.begin(); it != comp.end();) {
    if (!(it->first % p)) {
      pr[p] += it->second;
      pr[it->first / p] += it->second;
      auto del = it;
      it++;
      comp.erase(del);
    } else {
      it++;
    }
  }
}

void add(long long x) {
  {
    long long p = (long long) pow(x, (ld) 1 / 4);
    while (p * p * p * p > x) {
      p--;
    }
    while ((p + 1) * (p + 1) * (p + 1) * (p + 1) <= x) {
      p++;
    }
    if (p * p * p * p == x) {
      addPrime(p, 4);
      return;
    }
  }
  {
    long long p = (long long) pow(x, (ld) 1 / 3);
    while (p * p * p > x) {
      p--;
    }
    while ((p + 1) * (p + 1) * (p + 1) <= x) {
      p++;
    }
    if (p * p * p == x) {
      addPrime(p, 3);
      return;
    }
  }
  {
    long long p = (long long) pow(x, (ld) 1 / 2);
    while (p * p > x) {
      p--;
    }
    while ((p + 1) * (p + 1) <= x) {
      p++;
    }
    if (p * p == x) {
      addPrime(p, 2);
      return;
    }
  }
  if (comp.count(x)) {
    comp[x]++;
    return;
  }
  for (auto it = pr.begin(); it != pr.end(); it++) {
    if (!(x % it->first)) {
      long long p = it->first, q = x / it->first;
      addPrime(p, 1);
      addPrime(q, 1);
      return;
    }
  }
  for (auto it = comp.begin(); it != comp.end(); it++) {
    long long g = gcd(x, it->first);
    if (g != 1) {
      long long p = g, q = x / g;
      addPrime(p, 1);
      addPrime(q, 1);
      return;
    }
  }
  comp[x]++;
}

void solve() {
  pr.clear();
  comp.clear();
  for (int i = 0; i < n; i++) {
    add(a[i]);
  }
  int res = 1;
  for (auto it = pr.begin(); it != pr.end(); it++) {
    res = mul(res, it->second + 1);
  }
  for (auto it = comp.begin(); it != comp.end(); it++) {
    res = mul(res, it->second + 1);
    res = mul(res, it->second + 1);
  }
  printf("%d\n", res);
  fflush(stdout);
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  read();
  solve();
#ifdef DEBUG
  eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}