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
#define sz(x) ((int) (x).size())
#define TASK "text"

const long long inf = (long long) 1.01e18;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

int n, m, k, g, invn;

int read() {
  if (scanf("%d%d%d", &n, &m, &k) < 3) {
    return false;
  }
  n *= 2;
  m *= 2;
  return true;
}

int gcd(int a, int b) {
  return b? gcd(b, a % b) : a;
}

pair<int, int> extGcd(int a, int b) {
  if (!b) {
    return make_pair(1, 0);
  }
  pair<int, int> p = extGcd(b, a % b);
  return make_pair(p.second, p.first - (a / b) * p.second);
}

int inv(int x, int mod) {
  return extGcd(x, mod).first;
}

long long solve(int x, int y) {
  if (x % g != y % g) {
    return inf;
  }
  int b = (long long) ((y - x) / g) * invn % (m / g);
  b = (b + (m / g)) % (m / g);
  return (long long)b * n + x;
}

void solve() {
  g = gcd(n, m);
  invn = inv(n / g, m / g);
  for (int i = 0; i < k; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    long long ans = min(min(solve(x, y), solve(x, m - y)),
                        min(solve(n - x, y), solve(n - x, m - y)));
    if (ans == inf) {
      ans = -1;
    }
    printf("%lld\n", ans);
  }
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
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}