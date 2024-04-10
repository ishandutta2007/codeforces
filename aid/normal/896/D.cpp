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

const int maxn = (int) 1e5 + 5;
int n, p, l, r;

int read() {
  if (scanf("%d%d%d%d", &n, &p, &l, &r) < 4) {
    return false;
  }
  r++;
  return true;
}

int mul(int a, int b) {
  return (long long) a * b % p;
}

void add(int &a, int b) {
  a = ((long long) a + b) % p;
}

int powMod(int x, int t) {
  int res = 1;
  while (t) {
    if (t & 1) {
      res = mul(res, x);
    }
    t >>= 1;
    x = mul(x, x);
  }
  return res;
}

pair<long long, long long> gcd(long long a, long long b) {
  if (!b) {
    return make_pair(1ll, 0ll);
  }
  pair<long long, long long> p = gcd(b, a % b);
  return make_pair(p.second, p.first - (a / b) * p.second);
}

int inv(int x) {
  long long res = gcd(x, p).first;
  return (res % p + p) % p;
}

vector<int> ps;
vector<int> qs;
int f[maxn];
vector<int> fp[maxn];

int c(int n, int a, int b) {
  int res = mul(f[n], mul(mul(inv(f[a]), inv(f[b])), inv(f[n - a - b])));
  for (int i = 0; i < sz(ps); i++) {
    int t = fp[n][i] - fp[a][i] - fp[b][i] - fp[n - a - b][i];
    res = mul(res, powMod(ps[i], t));
  }
  return res;
}

int get(int k) {
  int res = 0;
  for (int i = 0; i <= n; i++) {
    if (((i + k) & 1) || i < k) {
      continue;
    }
    add(res, c(n, (i + k) / 2, (i - k) / 2));
  }
  return res;
}

void solve() {
  if (p == 1) {
    printf("0\n");
    return;
  }
  ps.clear();
  qs.clear();
  {
    int x = p;
    for (int d = 2; d * d <= x; d++) {
      if (!(x % d)) {
        ps.push_back(d);
        qs.push_back(0);
        while (!(x % d)) {
          x /= d;
          qs.back()++;
        }
      }
    }
    if (x > 1) {
      ps.push_back(x);
      qs.push_back(x);
    }
  }
  f[0] = 1;
  fp[0].clear();
  fp[0].resize(sz(ps));
  for (int i = 1; i < n + 1; i++) {
    int x = i;
    fp[i].clear();
    fp[i].resize(sz(ps));
    for (int j = 0; j < sz(ps); j++) {
      int q = ps[j];
      fp[i][j] = fp[i - 1][j];
      while (!(x % q)) {
        x /= q;
        fp[i][j]++;
      }
    }
    f[i] = mul(f[i - 1], x % p);
  }
  int res = get(l);
  add(res, get(l + 1));
  add(res, p - get(r));
  add(res, p - get(r + 1));
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