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

const int mod = (int) 1e9 + 7;

int mul(int a, int b) {
  return (long long) a * b % mod;
}

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

const int maxn = (int) 2e5 + 5;
int p2[maxn];

void precalc() {
  p2[0] = 1;
  for (int i = 1; i < maxn; ++i) {
    p2[i] = mul(p2[i - 1], 2);
  }
}

int n;
int a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  return true;
}

const int logn = 30;
int cnt[logn];

void solve() {
  for (int i = 0; i < logn; ++i) {
    cnt[i] = 0;
  }
  for (int i = 0; i < n; ++i) {
    int x = a[i];
    int k = 0;
    while (!(x & 1)) {
      x >>= 1;
      ++k;
    }
    ++cnt[k];
  }
  int r = n - cnt[0];
  int res = p2[cnt[0]];
  add(res, mod - 1);
  res = mul(res, p2[r]);
  for (int i = 1; i < logn; ++i) {
    r -= cnt[i];
    int cur = p2[max(0, cnt[i] - 1)];
    add(cur, mod - 1);
    cur = mul(cur, p2[r]);
    add(res, cur);
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