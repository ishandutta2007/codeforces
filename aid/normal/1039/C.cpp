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

const int maxn = (int) 5e5 + 5;
int p2[maxn];

void precalc() {
  p2[0] = 1;
  for (int i = 1; i < maxn; i++) {
    p2[i] = mul(p2[i - 1], 2);
  }
}

int n, m, k;
long long cs[maxn];
int es[maxn][2];

int read() {
  if (scanf("%d%d%d", &n, &m, &k) < 3) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%lld", &cs[i]);
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 2; j++) {
      scanf("%d", &es[i][j]);
      es[i][j]--;
    }
  }
  return true;
}

vector<int> g[maxn];
map<long long, vector<pair<int, int>>> mp;
set<int> vs;
int used[maxn];
int curu;

void dfs(int v) {
  used[v] = curu;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (used[u] != curu) {
      dfs(u);
    }
  }
}

void solve() {
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  mp.clear();
  for (int i = 0; i < m; i++) {
    int v = es[i][0], u = es[i][1];
    mp[cs[v] ^ cs[u]].push_back(make_pair(v, u));
  }
  int res = 0;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    const auto &e = it->second;
    vs.clear();
    for (int i = 0; i < sz(e); i++) {
      int v = e[i].first, u = e[i].second;
      vs.insert(v);
      vs.insert(u);
      g[v].push_back(u);
      g[u].push_back(v);
    }
    int cnt = n - sz(vs);
    curu++;
    for (auto vit = vs.begin(); vit != vs.end(); vit++) {
      int v = *vit;
      if (used[v] != curu) {
        dfs(v);
        cnt++;
      }
    }
    add(res, p2[cnt]);
    for (auto vit = vs.begin(); vit != vs.end(); vit++) {
      int v = *vit;
      g[v].clear();
    }
  }
  int rem = p2[k];
  add(rem, mod - sz(mp));
  add(res, mul(rem, p2[n]));
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