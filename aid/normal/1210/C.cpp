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

long long gcd(long long a, long long b) {
  return (b ? gcd(b, a % b) : a);
}

const int maxn = (int) 1e5 + 5;
int n;
long long x[maxn];
vector<int> g[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%lld", &x[i]);
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  return true;
}

int dep[maxn];
int res;

void dfs(int v, int p, vector<pair<int, long long>> s) {
  {
    for (int i = 0; i < sz(s); i++) {
      s[i].second = gcd(s[i].second, x[v]);
    }
    s.push_back(make_pair(v, x[v]));
    int k = 1;
    for (int i = 1; i < sz(s); i++) {
      if (s[i].second == s[k - 1].second) {
        s[k - 1].first = s[i].first;
      } else {
        s[k++] = s[i];
      }
    }
    s.resize(k);
    for (int i = 0; i < sz(s); i++) {
      int cur = s[i].second % mod;
      int len = dep[s[i].first] - (i ? dep[s[i - 1].first] : -1);
      add(res, mul(cur, len));
    }
  }
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    dep[u] = dep[v] + 1;
    dfs(u, v, s);
  }
}

void solve() {
  res = 0;
  dep[0] = 0;
  dfs(0, -1, {});
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