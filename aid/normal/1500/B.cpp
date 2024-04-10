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

pair<int, int> extGcd(int a, int b) {
  if (!b) {
    return make_pair(1, 0);
  }
  auto p = extGcd(b, a % b);
  return make_pair(p.second, p.first - (a / b) * p.second);
}

int inv(int x, int mod) {
  int res = extGcd(x, mod).first % mod;
  if (res < 0) {
    res += mod;
  }
  return res;
}

const int maxn = (int) 5e5 + 5;
int n, m;
long long k;
int a[maxn], b[maxn];

bool read() {
  if (scanf("%d%d%lld", &n, &m, &k) < 3) {
    return false;
  }
  --k;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d", &b[i]);
  }
  return true;
}

long long per;
int g, bl, step;
int c[maxn];
vector<int> ps[2 * maxn];

int getCnt(int l, int r, int x) {
  int ll = lower_bound(ps[x].begin(), ps[x].end(), l) - ps[x].begin();
  int rr = lower_bound(ps[x].begin(), ps[x].end(), r) - ps[x].begin();
  return rr - ll;
}

long long check(int p) {
  long long cnt = 0;
  for (int i = 0; i < n; ++i) {
    int id = i % g;
    int l = id * bl, r = l + bl;
    int sh = (i - id) / g;
    sh = (long long) sh * step % bl;
    int ll = l + sh, rr = ll + p;
    int cur = 0;
    if (rr <= r) {
      cur = getCnt(ll, rr, a[i]);
    } else {
      rr -= bl;
      cur = getCnt(ll, r, a[i]) + getCnt(l, rr, a[i]);
    }
    cur = p - cur;
    cnt += cur;
  }
  return cnt;
}

void solve() {
  g = gcd(n, m);
  bl = m / g;
  step = inv(n / g, bl);
  per = (long long) n * bl;
  int pos = 0;
  for (int s = 0; s < g; ++s) {
    for (int i = s, it = 0; it < bl; i = (i + n) % m, ++it) {
      c[pos++] = b[i];
    }
  }
  int mx = 2 * max(n, m) + 1;
  for (int i = 0; i < mx; ++i) {
    ps[i].clear();
  }
  for (int i = 0; i < m; ++i) {
    ps[c[i]].push_back(i);
  }
  long long cnt1 = 0;
  for (int i = 0; i < n; ++i) {
    int id = i % g;
    int l = id * bl, r = l + bl;
    int cur = bl - getCnt(l, r, a[i]);
    cnt1 += cur;
  }
  long long percnt = k / cnt1;
  k %= cnt1;
  int l = 0, r = bl;
  while (l < r - 1) {
    int mm = (l + r) / 2;
    if (check(mm) <= k) {
      l = mm;
    } else {
      r = mm;
    }
  }
  k -= check(l);
  long long res = percnt * per + (long long) l * n;
  while (k >= 0) {
    if (a[res % n] != b[res % m]) {
      --k;
    }
    ++res;
  }
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