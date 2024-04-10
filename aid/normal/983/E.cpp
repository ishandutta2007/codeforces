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

const int maxn = (int) 2e5 + 5, logn = 20;
int n, m, q;
vector<int> g[maxn];
int as[maxn], bs[maxn];
int qs[maxn][2];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 1; i < n; i++) {
    int p;
    scanf("%d", &p);
    p--;
    g[p].push_back(i);
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &as[i], &bs[i]);
    as[i]--;
    bs[i]--;
  }
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    for (int j = 0; j < 2; j++) {
      scanf("%d", &qs[i][j]);
      qs[i][j]--;
    }
  }
  return true;
}

int tin[maxn], tout[maxn], t;
int p[maxn][logn];
int go[maxn][logn];
int dep[maxn], ts[maxn];

void getLca(int v) {
  tin[v] = t++;
  for (int i = 1; i < logn; i++) {
    p[v][i] = p[p[v][i - 1]][i - 1];
  }
  ts[v] = 1;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    p[u][0] = v;
    dep[u] = dep[v] + 1;
    getLca(u);
    ts[v] += ts[u];
  }
  tout[v] = t;
}

bool anc(int v, int u) {
  return tin[v] <= tin[u] && tout[u] <= tout[v];
}

int lca(int v, int u) {
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

vector<pair<int, int>> toadd[maxn];
vector<pair<int, int>> todel[maxn];
set<pair<int, int>> *st[maxn];

void getGo(int v) {
  int maxu = -1;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    getGo(u);
    if (maxu == -1 || ts[u] > ts[maxu]) {
      maxu = u;
    }
  }
  if (maxu == -1) {
    st[v] = new set<pair<int, int>>();
  } else {
    st[v] = st[maxu];
  }
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == maxu) {
      continue;
    }
    for (auto it = st[u]->begin(); it != st[u]->end(); it++) {
      st[v]->insert(*it);
    }
  }
  for (int i = 0; i < sz(toadd[v]); i++) {
    st[v]->insert(toadd[v][i]);
  }
  go[v][0] = (st[v]->empty() ? dep[v] : st[v]->begin()->first);
  for (int i = 0; i < sz(todel[v]); i++) {
    st[v]->erase(todel[v][i]);
  }
}

int goDep(int v, int d) {
  for (int i = 0; i < logn; i++) {
    if (d & (1 << i)) {
      v = p[v][i];
    }
  }
  return v;
}

vector<pair<int, int>> evs[maxn][3];
int sts[4 * maxn];

void buildst(int v, int tl, int tr) {
  sts[v] = 0;
  if (tl == tr - 1) {
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
}

void update(int v, int tl, int tr, int pos, int toadd) {
  if (tl == tr - 1) {
    sts[v] += toadd;
    return;
  }
  int tm = (tl + tr) / 2;
  if (pos < tm) {
    update(2 * v, tl, tm, pos, toadd);
  } else {
    update(2 * v + 1, tm, tr, pos, toadd);
  }
  sts[v] = sts[2 * v] + sts[2 * v + 1];
}

int get(int v, int tl, int tr, int l, int r) {
  if (l == tl && r == tr) {
    return sts[v];
  }
  int tm = (tl + tr) / 2;
  int res = 0;
  if (l < tm) {
    res += get(2 * v, tl, tm, l, min(r, tm));
  }
  if (r > tm) {
    res += get(2 * v + 1, tm, tr, max(l, tm), r);
  }
  return res;
}

int ans[maxn];
int vals[maxn];

void solve() {
  t = 0;
  p[0][0] = 0;
  dep[0] = 0;
  getLca(0);
  for (int i = 0; i < n; i++) {
    toadd[i].clear();
    todel[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int v = as[i], u = bs[i];
    int w = lca(v, u);
    for (int it = 0; it < 2; it++) {
      toadd[v].push_back(make_pair(dep[w], 2 * i + it));
      todel[w].push_back(make_pair(dep[w], 2 * i + it));
      swap(v, u);
    }
  }
  getGo(0);
  for (int v = 0; v < n; v++) {
    go[v][0] = goDep(v, dep[v] - go[v][0]);
  }
  for (int i = 1; i < logn; i++) {
    for (int v = 0; v < n; v++) {
      go[v][i] = go[go[v][i - 1]][i - 1];
    }
  }
  for (int i = 0; i <= t; i++) {
    for (int j = 0; j < 3; j++) {
      evs[i][j].clear();
    }
  }
  for (int i = 0; i < m; i++) {
    int v = as[i], u = bs[i];
    for (int it = 0; it < 2; it++) {
      evs[tin[v]][1].push_back(make_pair(u, -1));
      swap(v, u);
    }
  }
  for (int qq = 0; qq < q; qq++) {
    vals[qq] = -inf;
    int v = qs[qq][0], u = qs[qq][1];
    auto &res = ans[qq];
    res = 0;
    if (anc(v, u)) {
      swap(v, u);
    }
    if (anc(u, v)) {
      for (int i = logn - 1; i >= 0; i--) {
        if (!anc(go[v][i], u)) {
          res += (1 << i);
          v = go[v][i];
        }
      }
      if (!anc(go[v][0], u)) {
        res = inf;
      } else {
        res++;
      }
    } else {
      for (int it = 0; it < 2; it++) {
        for (int i = logn - 1; i >= 0; i--) {
          if (!anc(go[v][i], u)) {
            res += (1 << i);
            v = go[v][i];
          }
        }
        if (!anc(go[v][0], u)) {
          res = inf;
          break;
        }
        swap(v, u);
      }
      if (res < inf) {
        res += 2;
        evs[tin[v]][0].push_back(make_pair(u, qq));
        evs[tout[v]][2].push_back(make_pair(u, qq));
        vals[qq] = 0;
      }
    }
  }
  buildst(1, 0, t);
  for (int i = 0; i <= t; i++) {
    for (int j = 0; j < sz(evs[i][0]); j++) {
      int v = evs[i][0][j].first, id = evs[i][0][j].second;
      vals[id] -= get(1, 0, t, tin[v], tout[v]);
    }
    for (int j = 0; j < sz(evs[i][2]); j++) {
      int v = evs[i][2][j].first, id = evs[i][2][j].second;
      vals[id] += get(1, 0, t, tin[v], tout[v]);
    }
    for (int j = 0; j < sz(evs[i][1]); j++) {
      int v = evs[i][1][j].first;
      update(1, 0, t, tin[v], 1);
    }
  }
  for (int i = 0; i < q; i++) {
    if (vals[i] > 0) {
      ans[i]--;
    }
  }
  for (int i = 0; i < q; i++) {
    if (ans[i] >= inf) {
      ans[i] = -1;
    }
    printf("%d\n", ans[i]);
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