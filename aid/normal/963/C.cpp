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

#define ws wwwwwwwwwwwwwws

const int maxn = (int) 2e5 + 5;
int n;
long long ws[maxn], hs[maxn], cs[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%lld%lld%lld", &ws[i], &hs[i], &cs[i]);
  }
  return true;
}

long long gcd(long long a, long long b) {
  return (b ? gcd(b, a % b) : a);
}

vector<long long> xs, ys;
vector<vector<long long>> a;

void solve() {
  xs.clear();
  ys.clear();
  for (int i = 0; i < n; i++) {
    xs.push_back(ws[i]);
    ys.push_back(hs[i]);
  }
  sort(xs.begin(), xs.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());
  sort(ys.begin(), ys.end());
  ys.erase(unique(ys.begin(), ys.end()), ys.end());
  if ((long long) sz(xs) * sz(ys) != n) {
    printf("0\n");
    return;
  }
  a.clear();
  a.resize(sz(xs), vector<long long>(sz(ys), 0));
  for (int i = 0; i < n; i++) {
    int x = lower_bound(xs.begin(), xs.end(), ws[i]) - xs.begin();
    int y = lower_bound(ys.begin(), ys.end(), hs[i]) - ys.begin();
    if (a[x][y]) {
      printf("0\n");
      return;
    }
    a[x][y] = cs[i];
  }
  for (int i = 0; i < sz(xs); i++) {
    for (int j = 0; j < sz(ys); j++) {
      if (!a[i][j]) {
        printf("0\n");
        return;
      }
    }
  }
  for (int i = 0; i < sz(xs); i++) {
    long long p0 = a[i][0], q0 = a[0][0];
    {
      long long g = gcd(p0, q0);
      p0 /= g;
      q0 /= g;
    }
    for (int j = 0; j < sz(ys); j++) {
      long long p = a[i][j], q = a[0][j];
      {
        long long g = gcd(p, q);
        p /= g;
        q /= g;
      }
      if (p != p0 || q != q0) {
        printf("0\n");
        return;
      }
    }
  }
  long long mx = 0, mn = 1;
  for (int i = 0; i < sz(ys); i++) {
    mx = gcd(mx, a[0][i]);
  }
  for (int i = 0; i < sz(xs); i++) {
    long long p = a[i][0], q = a[0][0];
    {
      long long g = gcd(p, q);
      p /= g;
      q /= g;
    }
    long long g = gcd(mn, q);
    if ((ld) mn * q / g >= infll) {
      printf("0\n");
      return;
    }
    mn = mn * q / g;
  }
  if (mn > mx) {
    printf("0\n");
    return;
  }
  int res = 0;
  for (long long d = 1; d * d <= mx; d++) {
    if (mx % d) {
      continue;
    }
    if (!(d % mn)) {
      res++;
    }
    if (d * d != mx && !((mx / d) % mn)) {
      res++;
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