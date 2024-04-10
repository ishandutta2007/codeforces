#ifdef DEBUG
//#define _GLIBCXX_DEBUG
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
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int mod = (int) 1e9 + 7;

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

int mul(int a, int b) {
  return (long long) a * b % mod;
}

pair<int, int> gcd(int a, int b) {
  if (!b) {
    return make_pair(1, 0);
  }
  pair<int, int> p = gcd(b, a % b);
  return make_pair(p.second, p.first - (a / b) * p.second);
}

int inv(int x) {
  int res = gcd(x, mod).first;
  if (res < 0) {
    res += mod;
  }
  return res;
}

const int maxn = 1005, maxm = 13;
int n[2];
vector<int> g[2][maxn];
vector<int> ids[maxm];
int s[3 * maxm], t[3 * maxm];

int read() {
  for (int t = 0; t < 2; t++) {
    if (scanf("%d", &n[t]) < 1) {
      return false;
    }
    for (int i = 0; i < n[t]; i++) {
      g[t][i].clear();
      if (t) {
        ids[i].clear();
      }
    }
    if (t) {
      for (int i = 0; i < n[t]; i++) {
        s[i] = -1;
        ::t[i] = i;
      }
    }
    for (int i = 0; i < n[t] - 1; i++) {
      int v, u;
      scanf("%d%d", &v, &u);
      v--;
      u--;
      g[t][v].push_back(u);
      g[t][u].push_back(v);
      if (t) {
        ids[v].push_back(n[t] + 2 * i);
        ids[u].push_back(n[t] + 2 * i + 1);
        s[n[t] + 2 * i] = v;
        ::t[n[t] + 2 * i] = u;
        s[n[t] + 2 * i + 1] = u;
        ::t[n[t] + 2 * i + 1] = v;
      }
    }
  }
  return true;
}

int dp[maxn][3 * maxm];
int a[maxn][1 << maxm];

void dfs(int v, int p) {
  for (int i = 0; i < sz(g[0][v]); i++) {
    int u = g[0][v][i];
    if (u == p) {
      continue;
    }
    dfs(u, v);
  }
  for (int e = 0; e < n[1] + 2 * (n[1] - 1); e++) {
    vector<int> es;
    for (int i = 0; i < sz(g[1][t[e]]); i++) {
      if (g[1][t[e]][i] != s[e]) {
        es.push_back(ids[t[e]][i]);
      }
    }
    for (int i = 0; i <= sz(g[0][v]); i++) {
      for (int j = 0; j < (1 << sz(es)); j++) {
        a[i][j] = 0;
      }
    }
    a[0][0] = 1;
    for (int i = 0; i < sz(g[0][v]); i++) {
      int u = g[0][v][i];
      if (u == p) {
        for (int j = 0; j < (1 << sz(es)); j++) {
          a[i + 1][j] = a[i][j];
        }
        continue;
      }
      for (int j = 0; j < (1 << sz(es)); j++) {
        auto cur = a[i][j];
        if (!cur) {
          continue;
        }
        add(a[i + 1][j], cur);
        for (int k = 0; k < sz(es); k++) {
          if (j & (1 << k)) {
            continue;
          }
          add(a[i + 1][j | (1 << k)], mul(cur, dp[u][es[k]]));
        }
      }
    }
    dp[v][e] = a[sz(g[0][v])][(1 << sz(es)) - 1];
  }
}

int solve1() {
  dfs(0, -1);
  int res = 0;
  for (int i = 0; i < n[0]; i++) {
    for (int j = 0; j < n[1]; j++) {
      add(res, dp[i][j]);
    }
  }
  return res;
}

void solve() {
  int res = solve1();
  n[0] = n[1];
  for (int i = 0; i < n[0]; i++) {
    g[0][i] = g[1][i];
  }
  res = mul(res, inv(solve1()));
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