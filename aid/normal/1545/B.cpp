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

const int maxn = (int) 1e5 + 5;
int f[maxn], inv[maxn], finv[maxn];

int c(int n, int k) {
  return mul(f[n], mul(finv[k], finv[n - k]));
}

void precalc() {
  f[0] = 1;
  for (int i = 1; i < maxn; ++i) {
    f[i] = mul(f[i - 1], i);
  }
  inv[1] = 1;
  for (int i = 2; i < maxn; ++i) {
    inv[i] = (mod - (long long) (mod / i) * inv[mod % i] % mod) % mod;
  }
  finv[0] = 1;
  for (int i = 1; i < maxn; ++i) {
    finv[i] = mul(finv[i - 1], inv[i]);
  }
}

char tmp[maxn];
int n;
string s;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  scanf("%s", tmp);
  s = tmp;
  return true;
}

void solve() {
  int m = 1;
  int k = 0;
  for (int j = 0; j < n;) {
    if (s[j] == '0') {
      ++m;
      ++j;
      continue;
    }
    int i = j;
    while (j < n && s[j] == '1') {
      ++j;
    }
    k += (j - i) / 2;
  }
  printf("%d\n", c(k + m - 1, k));
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