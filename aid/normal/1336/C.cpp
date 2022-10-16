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

const int maxn = 3005;
char tmp[maxn];
int n, m;
string s, t;

bool read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  s = tmp;
  n = sz(s);
  scanf("%s", tmp);
  t = tmp;
  m = sz(t);
  return true;
}

int dp[maxn], ndp[maxn];

void solve() {
  memset(dp, 0, sizeof(dp));
  for (int i = n; i > 0; i--) {
    memset(ndp, 0, sizeof(ndp));
    if (i >= m) {
      add(dp[0], 1);
    }
    char c = s[i - 1];
    for (int l = 0; l <= n - i; l++) {
      auto &cur = dp[l];
      if (!cur) {
        continue;
      }
      int r = (n - i) - l;
      int rpos = n - r - 1;
      if (l >= m || t[l] == c) {
        add(ndp[l + 1], cur);
      }
      if (rpos >= m || t[rpos] == c) {
        add(ndp[l], cur);
      }
    }
    swap(dp, ndp);
  }
  int res = 0;
  for (int i = 0; i <= n; i++) {
    add(res, dp[i]);
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