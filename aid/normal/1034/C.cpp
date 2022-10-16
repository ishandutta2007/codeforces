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

long long gcd(long long a, long long b) {
  return (b ? gcd(b, a % b) : a);
}

const int maxn = (int) 1e6 + 5;
int n;
int a[maxn];
vector<int> g[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    g[i].clear();
  }
  for (int i = 1; i < n; i++) {
    int p;
    scanf("%d", &p);
    p--;
    g[p].push_back(i);
  }
  return true;
}

long long s[maxn];
int cnt[maxn];
int dp[maxn];

void solve() {
  for (int v = n - 1; v >= 0; v--) {
    s[v] = a[v];
    for (int i = 0; i < sz(g[v]); i++) {
      int u = g[v][i];
      s[v] += s[u];
    }
  }
  for (int i = 0; i <= n; i++) {
    cnt[i] = 0;
    dp[i] = 0;
  }
  for (int v = 1; v < n; v++) {
    long long g = gcd(s[v], s[0]);
    long long k = s[0] / g;
    if (k <= n) {
      cnt[k]++;
    }
  }
  for (int i = n; i > 0; i--) {
    auto cur = cnt[i];
    if (!cur) {
      continue;
    }
    for (int j = 2 * i; j <= n; j += i) {
      cnt[j] += cur;
    }
  }
  for (int i = 2; i <= n; i++) {
    if (cnt[i] >= i - 1) {
      dp[i]++;
    }
  }
  int res = 1;
  for (int i = 2; i <= n; i++) {
    auto cur = dp[i];
    if (!cur) {
      continue;
    }
    add(res, cur);
    for (int j = 2 * i; j <= n; j += i) {
      if (cnt[j] >= j - 1) {
        add(dp[j], cur);
      }
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