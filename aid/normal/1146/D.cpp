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

void precalc() {
}

int gcd(int a, int b) {
  return (b ? gcd(b, a % b) : a);
}

int n, a, b;

bool read() {
  if (scanf("%d%d%d", &n, &a, &b) < 3) {
    return false;
  }
  n++;
  return true;
}

const int maxn = 2e5 + 5;
int used[maxn];
int cur;

void dfs(int x, int n) {
  used[x] = true;
  cur++;
  for (int it = 0; it < 2; it++) {
    int y = (!it ? x + a : x - b);
    if (y < 0 || y >= n || used[y]) {
      continue;
    }
    dfs(y, n);
  }
}

void solve() {
  int g = gcd(a, b);
  a /= g;
  b /= g;
  int rem = n % g;
  n /= g;
  for (int i = 0; i <= a + b; i++) {
    used[i] = false;
  }
  cur = 0;
  long long res = 0;
  if (n) {
    used[0] = true;
    cur++;
    res += cur;
  }
  for (int i = 1; i < a + b && i < n; i++) {
    int p = i - a;
    if (p < 0 || !used[p]) {
      res += cur;
      continue;
    }
    dfs(i, i + 1);
    res += cur;
  }
  if (a + b < n) {
    long long l = a + b + 1, r = n;
    res += (l + r) * (r - l + 1) / 2;
    cur = n + 1;
  } else {
    if (!n) {
      used[0] = true;
      cur++;
    }
    int p = n - a;
    if (p < 0 || !used[p]) {
    } else {
      dfs(n, n + 1);
    }
  }
  res *= g;
  res += (long long) cur * rem;
  printf("%lld\n", res);
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