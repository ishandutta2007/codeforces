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
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

pair<long long, long long> gcd(long long a, long long b) {
  if (!b) {
    return make_pair(1ll, 0ll);
  }
  pair<long long, long long> p = gcd(b, a % b);
  return make_pair(p.second, p.first - (a / b) * p.second);
}

long long x, y, p, q;

int read() {
  if (scanf("%lld%lld%lld%lld", &x, &y, &p, &q) < 4) {
    return false;
  }
  return true;
}

void solve() {
  if (x * q == p * y) {
    printf("0\n");
    return;
  }
  if (!p || p == q) {
    printf("-1\n");
    return;
  }
  long long k = max(max((x + p - 1) / p, (y + q - 1) / q), (y - x + q - p - 1) / (q - p));
  p *= k;
  q *= k;
  printf("%lld\n", q - y);
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  int t;
  scanf("%d", &t);
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}