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

const int maxn = (int) 5e5 + 5;
int n;
vector<int> g[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
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

int ts[maxn];

void getTs(int v, int p) {
  ts[v] = 1;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    getTs(u, v);
    ts[v] += ts[u];
  }
}

struct T {
  int x, mnx, cnt;

  T(): x(0), mnx(0), cnt(1) {}

  T(int _x, int _mnx, int _cnt): x(_x), mnx(_mnx), cnt(_cnt) {}

  T operator + (const T &t) const {
    if (mnx + t.x < x + t.mnx) {
      return T(x + t.x, mnx + t.x, cnt);
    } else if (x + t.mnx < mnx + t.x) {
      return T(x + t.x, x + t.mnx, t.cnt);
    } else {
      return T(x + t.x, mnx + t.x, cnt + t.cnt);
    }
  }
};

T dp[maxn];

void getDp(int v, int p) {
  dp[v] = T();
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    getDp(u, v);
    T cur = dp[u];
    if (ts[u] & 1) {
      cur.x++;
    } else {
      cur.mnx++;
    }
    dp[v] = dp[v] + cur;
  }
}

long long res;

void addRes(const T &a, const T &b) {
  if (2 * (a.mnx + b.mnx + 1) == n) {
    res += (long long) a.cnt * b.cnt;
  }
}

void dfs(int v, int p, T up) {
  vector<T> pref(sz(g[v]) + 1), suff(sz(g[v]) + 1);
  pref[0] = T();
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      pref[i + 1] = pref[i];
    } else {
      T cur = dp[u];
      if (ts[u] & 1) {
        cur.x++;
      } else {
        cur.mnx++;
      }
      pref[i + 1] = pref[i] + cur;
    }
  }
  suff[sz(g[v])] = up;
  for (int i = sz(g[v]) - 1; i >= 0; i--) {
    int u = g[v][i];
    if (u == p) {
      suff[i] = suff[i + 1];
    } else {
      T cur = dp[u];
      if (ts[u] & 1) {
        cur.x++;
      } else {
        cur.mnx++;
      }
      suff[i] = suff[i + 1] + cur;
    }
  }
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    T cur = pref[i] + suff[i + 1];
    if (ts[u] & 1) {
      addRes(dp[u], cur);
      cur.x++;
    } else {
      cur.mnx++;
    }
    dfs(u, v, cur);
  }
}

void solve() {
  if (n & 1) {
    printf("0\n");
    return;
  }
  getTs(0, -1);
  res = 0;
  {
    int cnt = 0;
    for (int i = 1; i < n; i++) {
      cnt += (ts[i] & 1);
    }
    if (2 * cnt == n) {
      for (int i = 1; i < n; i++) {
        if (!(ts[i] & 1)) {
          res += (long long) ts[i] * (n - ts[i]);
        }
      }
    }
  }
  getDp(0, -1);
  dfs(0, -1, T(0, inf, 0));
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