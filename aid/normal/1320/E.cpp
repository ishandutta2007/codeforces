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

const int maxn = (int) 2e5 + 5;
int n;
vector<int> g[maxn];

bool read() {
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

const int logn = 20;
int p[maxn][logn];
int tin[maxn], tout[maxn], t;
int dep[maxn];

void dfs0(int v) {
  for (int i = 1; i < logn; i++) {
    p[v][i] = p[p[v][i - 1]][i - 1];
  }
  tin[v] = t++;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p[v][0]) {
      continue;
    }
    p[u][0] = v;
    dep[u] = dep[v] + 1;
    dfs0(u);
  }
  tout[v] = t;
}

bool anc(int v, int u) {
  return tin[v] <= tin[u] && tout[u] <= tout[v];
}

int getLca(int v, int u) {
  if (anc(v, u)) {
    return v;
  }
  if (anc(u, v)) {
    return u;
  }
  for (int i = logn - 1; i >= 0; i--) {
    if (!anc(p[v][i], u)) {
      v = p[v][i];
    }
  }
  return p[v][0];
}

vector<pair<int, int>> gg[maxn];
vector<int> vs, v0, vneed;
int s[maxn];
int who[maxn];
priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>,
               greater<pair<pair<int, int>, pair<int, int>>>> pq;

bool cmp(int v, int u) {
  return tin[v] < tin[u];
}

void go(int v, int d) {
  for (int i = 0; i < sz(gg[v]); i++) {
    int u = gg[v][i].first, dd = d + gg[v][i].second;
    if (who[u] != -1) {
      continue;
    }
    pq.push(make_pair(make_pair((dd + s[who[v]] - 1) / s[who[v]], who[v]), make_pair(dd, u)));
  }
}

void solve() {
  t = 0;
  p[0][0] = 0;
  dep[0] = 0;
  dfs0(0);
  int q;
  scanf("%d", &q);
  for (int qq = 0; qq < q; qq++) {
    int k, m;
    scanf("%d%d", &k, &m);
    vs.clear();
    v0.clear();
    vneed.clear();
    for (int i = 0; i < k; i++) {
      int v;
      scanf("%d%d", &v, &s[i]);
      v--;
      v0.push_back(v);
      vs.push_back(v);
    }
    for (int i = 0; i < m; i++) {
      int v;
      scanf("%d", &v);
      v--;
      vneed.push_back(v);
      vs.push_back(v);
    }
    {
      sort(vs.begin(), vs.end(), cmp);
      vs.erase(unique(vs.begin(), vs.end()), vs.end());
      int l = sz(vs);
      for (int i = 0; i + 1 < l; i++) {
        int v = vs[i], u = vs[i + 1];
        int w = getLca(v, u);
        vs.push_back(w);
      }
      sort(vs.begin(), vs.end(), cmp);
      vs.erase(unique(vs.begin(), vs.end()), vs.end());
    }
    {
      for (int i = 0; i < sz(vs); i++) {
        int v = vs[i];
        gg[v].clear();
        who[v] = -1;
      }
      vector<int> p;
      for (int i = 0; i < sz(vs); i++) {
        int v = vs[i];
        while (!p.empty() && !anc(p.back(), v)) {
          p.pop_back();
        }
        if (!p.empty()) {
          int u = p.back();
          int d = dep[v] - dep[u];
          gg[v].push_back(make_pair(u, d));
          gg[u].push_back(make_pair(v, d));
        }
        p.push_back(v);
      }
    }
    while (!pq.empty()) {
      pq.pop();
    }
    for (int i = 0; i < k; i++) {
      who[v0[i]] = i;
    }
    for (int i = 0; i < k; i++) {
      go(v0[i], 0);
    }
    while (!pq.empty()) {
      int v = pq.top().second.second;
      int id = pq.top().first.second;
      int d = pq.top().second.first;
      pq.pop();
      if (who[v] != -1) {
        continue;
      }
      who[v] = id;
      go(v, d);
    }
    for (int i = 0; i < m; i++) {
      printf("%d ", who[vneed[i]] + 1);
    }
    printf("\n");
  }
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