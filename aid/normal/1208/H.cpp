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

const int maxn = (int) 1e5 + 5;
int n, k;
vector<int> g[maxn];
int s[maxn];

bool read() {
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
  for (int i = 0; i < n; i++) {
    scanf("%d", &s[i]);
  }
  return true;
}

int ts[maxn];
int p[maxn];

void dfs0(int v, int pr) {
  ts[v] = 1;
  p[v] = pr;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == pr) {
      swap(g[v][i], g[v].back());
      g[v].pop_back();
      i--;
      continue;
    }
    dfs0(u, v);
    ts[v] += ts[u];
    if (ts[u] > ts[g[v][0]]) {
      swap(g[v][0], g[v][i]);
    }
  }
}

int root[maxn];
int ps[maxn], rs[maxn];
int a[maxn];
vector<int> xs[maxn];
int lvs[maxn][2];
pair<int, int> st[4 * maxn];

pair<int, int> calc(const pair<int, int> &l, const pair<int, int> &r) {
  int blue = (l.first < r.first ? l.first : max(r.first, l.second));
  int red = (l.first < r.second ? l.first : max(r.second, l.second));
  return make_pair(blue, red);
}

void buildst(int v, int tl, int tr) {
  if (tl == tr - 1) {
    st[v] = make_pair(-n, -n);
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
  st[v] = calc(st[2 * v], st[2 * v + 1]);
}

pair<int, int> get1(int v) {
  if (s[v] == 0) {
    return make_pair(-n, -n);
  }
  if (s[v] == 1) {
    return make_pair(n + 1, n + 1);
  }
  int res[2];
  for (int it = 0; it < 2; it++) {
    int l = -1, r = sz(xs[v]);
    while (l < r - 1) {
      int m = (l + r) / 2;
      int bal = sz(xs[v]) - 2 * m + lvs[v][1] - lvs[v][0] + (!it ? 1 : -1);
      if (bal >= xs[v][m]) {
        l = m;
      } else {
        r = m;
      }
    }
    res[it] = sz(xs[v]) - 2 * r + lvs[v][1] - lvs[v][0] + (!it ? 1 : -1) + 1;
  }
  return make_pair(res[0], res[1]);
}

void update(int v, int tl, int tr, int pos) {
  if (tl == tr - 1) {
    st[v] = get1(a[tl]);
    return;
  }
  int tm = (tl + tr) / 2;
  if (pos < tm) {
    update(2 * v, tl, tm, pos);
  } else {
    update(2 * v + 1, tm, tr, pos);
  }
  st[v] = calc(st[2 * v], st[2 * v + 1]);
}

pair<int, int> get(int v, int tl, int tr, int l, int r) {
  if (l == tl && r == tr) {
    return st[v];
  }
  int tm = (tl + tr) / 2;
  if (r <= tm) {
    return get(2 * v, tl, tm, l, r);
  }
  if (l >= tm) {
    return get(2 * v + 1, tm, tr, l, r);
  }
  return calc(get(2 * v, tl, tm, l, tm), get(2 * v + 1, tm, tr, tm, r));
}

int getX(int v) {
  return get(1, 0, n, ps[v], rs[root[v]]).first;
}

void changeX(int v, int x, int nx) {
  assert(abs(nx - x) <= 2);
  while (x != nx) {
    if (x < nx) {
      int pos = upper_bound(xs[v].begin(), xs[v].end(), x) - xs[v].begin() - 1;
      assert(xs[v][pos] == x);
      xs[v][pos]++;
      x++;
    } else {
      int pos = lower_bound(xs[v].begin(), xs[v].end(), x) - xs[v].begin();
      assert(xs[v][pos] == x);
      xs[v][pos]--;
      x--;
    }
  }
}

void dfs1(int v) {
  xs[v].clear();
  lvs[v][0] = 0;
  lvs[v][1] = 0;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    dfs1(u);
    if (i) {
      if (s[u] != -1) {
        lvs[v][s[u]]++;
      } else {
        xs[v].push_back(getX(u));
      }
    }
  }
  sort(xs[v].begin(), xs[v].end());
  update(1, 0, n, ps[v]);
}

void solve() {
  dfs0(0, -1);
  for (int s = 0, pos = 0; s < n; s++) {
    if (p[s] != -1 && s == g[p[s]][0]) {
      continue;
    }
    for (int v = s; v != -1; v = (g[v].empty() ? -1 : g[v][0])) {
      ps[v] = pos;
      a[pos++] = v;
      root[v] = s;
    }
    rs[s] = pos;
  }
  buildst(1, 0, n);
  dfs1(0);
  int q;
  scanf("%d", &q);
  for (int qq = 0; qq < q; qq++) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int v;
      scanf("%d", &v);
      v--;
      int x = getX(v);
      printf("%d\n", (int) (k < x));
    } else if (t == 2) {
      int v, c;
      scanf("%d%d", &v, &c);
      v--;
      int was = s[v];
      s[v] = c;
      while (true) {
        int u = root[v];
        int x = getX(u);
        update(1, 0, n, ps[v]);
        if (p[u] == -1) {
          break;
        }
        int nx = getX(u);
        if (s[u] != -1) {
          lvs[p[u]][was]--;
          lvs[p[u]][c]++;
        } else {
          changeX(p[u], x, nx);
        }
        v = p[u];
      }
    } else {
      int h;
      scanf("%d", &h);
      k = h;
    }
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