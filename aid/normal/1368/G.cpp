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
char tmp[maxn];
int n, m;
vector<string> c;

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  c.resize(n);
  for (int i = 0; i < n; i++) {
    scanf("%s", tmp);
    c[i] = tmp;
  }
  return true;
}

const string dirs = "ULDR";
const int gox[] = {1, 0, -1, 0};
const int goy[] = {0, 1, 0, -1};

vector<vector<int>> ids;
int vs;
vector<vector<int>> g[2];
vector<int> p[2];
vector<int> onc[2];
vector<int> tin[2], tout[2];
vector<int> used;
int t;

bool inside(int x, int y) {
  return 0 <= x && x < n && 0 <= y && y < m;
}

void dfs(int s, int v) {
  tin[s][v] = t++;
  used[v] = true;
  for (int i = 0; i < sz(g[s][v]); i++) {
    int u = g[s][v][i];
    if (!used[u]) {
      dfs(s, u);
    }
  }
  tout[s][v] = t;
}

vector<pair<pair<int, int>, pair<int, int>>> evs;

struct node {
  int val, cnt, toadd;
};

node st[4 * maxn];

void buildst(int v, int tl, int tr) {
  st[v].val = 0;
  st[v].cnt = tr - tl;
  st[v].toadd = 0;
  if (tl == tr - 1) {
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
}

void push(int v) {
  if (!st[v].toadd) {
    return;
  }
  for (int i = 0; i < 2; i++) {
    int u = 2 * v + i;
    st[u].val += st[v].toadd;
    st[u].toadd += st[v].toadd;
  }
  st[v].toadd = 0;
}

void update(int v, int tl, int tr, int l, int r, int toadd) {
  if (l == tl && r == tr) {
    st[v].val += toadd;
    st[v].toadd += toadd;
    return;
  }
  push(v);
  int tm = (tl + tr) / 2;
  if (l < tm) {
    update(2 * v, tl, tm, l, min(r, tm), toadd);
  }
  if (r > tm) {
    update(2 * v + 1, tm, tr, max(l, tm), r, toadd);
  }
  if (st[2 * v].val < st[2 * v + 1].val) {
    st[v].val = st[2 * v].val;
    st[v].cnt = st[2 * v].cnt;
  } else if (st[2 * v + 1].val < st[2 * v].val) {
    st[v].val = st[2 * v + 1].val;
    st[v].cnt = st[2 * v + 1].cnt;
  } else {
    st[v].val = st[2 * v].val;
    st[v].cnt = st[2 * v].cnt + st[2 * v + 1].cnt;
  }
}

void solve() {
  vs = 0;
  ids = vector<vector<int>>(n, vector<int>(m, -1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (ids[i][j] != -1) {
        continue;
      }
      ids[i][j] = vs;
      int dir = find(dirs.begin(), dirs.end(), c[i][j]) - dirs.begin();
      int x = i + gox[dir], y = j + goy[dir];
      ids[x][y] = vs;
      vs++;
    }
  }
  for (int s = 0; s < 2; s++) {
    g[s].clear();
    g[s].resize(vs);
    p[s].clear();
    p[s].resize(vs, -1);
    onc[s].clear();
    onc[s].resize(vs);
    tin[s].clear();
    tin[s].resize(vs);
    tout[s].clear();
    tout[s].resize(vs);
    t = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (((i + j) & 1) != s) {
          continue;
        }
        int dir = find(dirs.begin(), dirs.end(), c[i][j]) - dirs.begin();
        int x = i + 2 * gox[dir], y = j + 2 * goy[dir];
        if (inside(x, y)) {
          g[s][ids[x][y]].push_back(ids[i][j]);
          p[s][ids[i][j]] = ids[x][y];
        }
      }
    }
    used.clear();
    used.resize(vs);
    for (int v = 0; v < vs; v++) {
      if (used[v]) {
        continue;
      }
      int u = v;
      vector<int> path;
      while (true) {
        if (used[u]) {
          for (int i = 0; i < sz(path); i++) {
            used[path[i]] = false;
          }
          int pos = 0;
          while (path[pos] != u) {
            pos++;
          }
          path.erase(path.begin(), path.begin() + pos);
          break;
        }
        used[u] = true;
        path.push_back(u);
        if (p[s][u] == -1) {
          for (int i = 0; i < sz(path); i++) {
            used[path[i]] = false;
          }
          path.clear();
          break;
        }
        u = p[s][u];
      }
      dfs(s, u);
      for (int i = 0; i < sz(path); i++) {
        onc[s][path[i]] = true;
        tin[s][path[i]] = tin[s][u];
        tout[s][path[i]] = tout[s][u];
      }
    }
  }
  evs.clear();
  for (int v = 0; v < vs; v++) {
    int l = tin[0][v], r = tout[0][v];
    int d = tin[1][v], u = tout[1][v];
    evs.push_back(make_pair(make_pair(l, 1), make_pair(d, u)));
    evs.push_back(make_pair(make_pair(r, -1), make_pair(d, u)));
  }
  buildst(1, 0, vs);
  sort(evs.begin(), evs.end());
  long long res = 0;
  for (int i = 0; i < sz(evs); i++) {
    if (i && evs[i].first.first != evs[i - 1].first.first) {
      long long x = evs[i].first.first - evs[i - 1].first.first;
      long long y = (st[1].val == 0 ? st[1].cnt : 0);
      y = vs - y;
      res += x * y;
    }
    int val = evs[i].first.second;
    int l = evs[i].second.first, r = evs[i].second.second;
    update(1, 0, vs, l, r, val);
  }
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