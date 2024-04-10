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

const int mod = 998244353;

int mul(int a, int b) {
  return (long long) a * b % mod;
}

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

pair<int, int> gcd(int a, int b) {
  if (!b) {
    return make_pair(1, 0);
  }
  auto p = gcd(b, a % b);
  return make_pair(p.second, p.first - (a / b) * p.second);
}

int inv(int x) {
  int res = gcd(x, mod).first % mod;
  if (res < 0) {
    add(res, mod);
  }
  return res;
}

const int maxn = (int) 3e5 + 5;
int n;
int a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

int s, sinv;
int fp[maxn];
int cs[maxn];

void solve() {
  s = 0;
  for (int i = 0; i < n; i++) {
    s += a[i];
  }
  sinv = inv(s);
  cs[0] = 0;
  for (int i = 1; i <= s; i++) {
    cs[i] = 0;
    int c1 = n - 1;
    add(c1, mod - mul(n - 2, mul(s - (i - 1), sinv)));
    add(cs[i], mul(c1, cs[i - 1]));
    if (i >= 2) {
      int c2 = mul(n - 1, mul(i - 1, sinv));
      add(cs[i], mod - mul(c2, cs[i - 2]));
    }
    add(cs[i], mod - (n - 1));
    int tomul = mul(s, inv(s - (i - 1)));
    cs[i] = mul(cs[i], tomul);
  }
  fp[0] = mul(mod - 1, cs[s]);
  for (int i = 1; i <= s; i++) {
    fp[i] = cs[i];
    add(fp[i], fp[0]);
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    add(res, fp[a[i]]);
  }
  add(res, mod - mul(n - 1, fp[0]));
  res = mul(res, inv(n));
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