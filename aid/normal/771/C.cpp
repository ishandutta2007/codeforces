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
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 2e5 + 5, maxk = 7;
int n, k;
vector<int> g[maxn];
long long d[maxn][maxk];
int cnt[maxn][maxk];

int read() {
  if (scanf("%d%d", &n, &k) < 2) {
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

long long nd[maxk];
int ncnt[maxk];
long long res;

void dfs(int v, int p) {
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    dfs(u, v);
  }
  for (int i = 0; i < k; i++) {
    d[v][i] = 0;
    cnt[v][i] = 0;
  }
  cnt[v][0] = 1;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    for (int r = 0; r < k; r++) {
      int nr = (r + 1) % k;
      nd[nr] = d[u][r];
      ncnt[nr] = cnt[u][r];
      if (!nr) {
        nd[nr] += ncnt[nr];
      }
    }
    for (int rv = 0; rv < k; rv++) {
      for (int ru = 0; ru < k; ru++) {
        res += d[v][rv] * ncnt[ru] + nd[ru] * cnt[v][rv];
        int rem = (rv + ru + k - 1) / k;
        res += (long long) rem * cnt[v][rv] * ncnt[ru];
      }
    }
    for (int r = 0; r < k; r++) {
      d[v][r] += nd[r];
      cnt[v][r] += ncnt[r];
    }
  }
}

void solve() {
  res = 0;
  dfs(0, -1);
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