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

const int maxn = (int) 1e6 + 5;
int f[maxn], inv[maxn], finv[maxn];

void precalc() {
  f[0] = 1;
  for (int i = 1; i < maxn; i++) {
    f[i] = mul(f[i - 1], i);
  }
  inv[1] = 1;
  for (int i = 2; i < maxn; i++) {
    inv[i] = (mod - (long long) (mod / i) * inv[mod % i] % mod) % mod;
  }
  finv[0] = 1;
  for (int i = 1; i < maxn; i++) {
    finv[i] = mul(finv[i - 1], inv[i]);
  }
}

char tmp[maxn];
int n;
string s;

bool read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  s = tmp;
  n = sz(s);
  return true;
}

void getC(int c[maxn], int n) {
  for (int i = 0; i <= n; i++) {
    c[i] = mul(f[n], mul(finv[i], finv[n - i]));
  }
  c[n + 1] = 0;
  for (int i = n; i >= 0; i--) {
    add(c[i], c[i + 1]);
  }
}

int c0[maxn], c1[maxn];
int pref[maxn], suff[maxn];

void solve() {
  int q = 0;
  for (int i = 0; i < n; i++) {
    q += (s[i] == '?');
  }
  getC(c0, q);
  if (q) {
    getC(c1, q - 1);
  }
  pref[0] = 0;
  for (int i = 0; i < n; i++) {
    pref[i + 1] = pref[i] + (s[i] == '(');
  }
  suff[n] = 0;
  for (int i = n - 1; i >= 0; i--) {
    suff[i] = suff[i + 1] + (s[i] == ')');
  }
  int a = 0;
  int res = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == ')') {
      continue;
    }
    if (s[i] == '(') {
      int need = pref[i + 1] - suff[i + 1] + a;
      need = min(q + 1, max(0, need));
      add(res, c0[need]);
    } else {
      int need = pref[i + 1] + 1 - suff[i + 1] + a;
      need = min(q, max(0, need));
      add(res, c1[need]);
      a++;
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