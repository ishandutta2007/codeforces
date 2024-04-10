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
int n, m;
char tmp[maxn];
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

int z[maxn];

void getZ(const string &s) {
  int n = sz(s);
  for (int i = 0; i < n; i++) {
    z[i] = 0;
  }
  for (int i = 1, l = 0, r = -1; i < n; i++) {
    if (i + z[i - l] < r) {
      z[i] = z[i - l];
    } else {
      l = i;
      r = max(r, i);
      while (r < n && s[r - l] == s[r]) {
        r++;
      }
      z[i] = r - l;
    }
  }
}

int nxt[maxn];
int dp[maxn];
int toadd[maxn];

void solve() {
  getZ(t + s);
  nxt[n] = n;
  for (int i = n - 1; i >= 0; i--) {
    if (z[m + i] >= m) {
      nxt[i] = i;
    } else {
      nxt[i] = nxt[i + 1];
    }
  }
  for (int i = 0; i <= n; i++) {
    dp[i] = 1;
    toadd[i] = 0;
  }
  int curadd0 = 0;
  int curadd1 = 0;
  for (int i = 0; i <= n; i++) {
    auto &cur = dp[i];
    add(curadd0, toadd[i]);
    add(curadd1, curadd0);
    add(cur, curadd1);
    int j = nxt[i];
    if (j < n) {
      j += m;
      add(toadd[j], cur);
    }
  }
  int res = dp[n];
  add(res, mod - 1);
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