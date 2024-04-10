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

const int mod = (int) 1e9 + 7;

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

int powMod(int x, int p) {
  int res = 1;
  while (p) {
    if (p & 1) {
      res = mul(res, x);
    }
    p >>= 1;
    x = mul(x, x);
  }
  return res;
}

const int maxn = (int) 1e5 + 5;
int n;
vector< pair<int, pair<int, int> > > g[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
    int v, u, x, c;
    scanf("%d%d%d%d", &v, &u, &x, &c);
    v--;
    u--;
    g[v].push_back(make_pair(u, make_pair(x, c)));
    g[u].push_back(make_pair(v, make_pair(x, c)));
  }
  return true;
}

struct node {
  int val;
  node *l, *r;
};

const int maxs = 1e7;
node nodes[maxs];
int freeNode;
node *st[3 * maxn];

node *newNode(int val) {
  auto &cur = nodes[freeNode++];
  cur.val = val;
  cur.l = 0;
  cur.r = 0;
  return &cur;
}

node *newNode(node *l, node *r) {
  auto &cur = nodes[freeNode++];
  cur.val = l->val + r->val;
  cur.l = l;
  cur.r = r;
  return &cur;
}

node *buildst() {
  node *res = newNode(0);
  for (int i = 0; i < 21; i++) {
    res = newNode(res, res);
  }
  return res;
}

node *update(node *v, int tl, int tr, int pos, int toadd) {
  if (tl == tr - 1) {
    return newNode(v->val + toadd);
  }
  int tm = (tl + tr) / 2;
  if (pos < tm) {
    return newNode(update(v->l, tl, tm, pos, toadd), v->r);
  } else {
    return newNode(v->l, update(v->r, tm, tr, pos, toadd));
  }
}

int get(node *v, int tl, int tr, int l, int r) {
  if (l == tl && r == tr) {
    return v->val;
  }
  int tm = (tl + tr) / 2;
  int res = 0;
  if (l < tm) {
    res += get(v->l, tl, tm, l, min(r, tm));
  }
  if (r > tm) {
    res += get(v->r, tm, tr, max(l, tm), r);
  }
  return res;
}

int get(vector< pair<pair<int, int>, int> > &ps) {
  sort(ps.begin(), ps.end());
  int l = ps[0].first.first, r = ps.back().first.first + 1;
  freeNode = 0;
  st[r - l] = buildst();
  for (int i = r - 1, j = sz(ps) - 1; i >= l; i--) {
    auto &cur = st[i - l];
    cur = st[i - l + 1];
    while (j >= 0 && ps[j].first.first >= i) {
      cur = update(cur, 0, 3 * maxn, maxn + ps[j].first.second, 1);
      j--;
    }
  }
  int res = 1;
  for (int i = 0; i < sz(ps); i++) {
    int x = max(l, -ps[i].first.first);
    int y = max(0, maxn + -ps[i].first.second);
    if (x < r && y < 3 * maxn) {
      res = mul(res, powMod(ps[i].second, get(st[x - l], 0, 3 * maxn, y, 3 * maxn)));
    }
  }
  return res;
}

int res, todiv;
int del[maxn];
int ts[maxn];

void getTs(int v, int p) {
  ts[v] = 1;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i].first;
    if (del[u] || u == p) {
      continue;
    }
    getTs(u, v);
    ts[v] += ts[u];
  }
}

void dfs(int v, int p, int r, int b, int val, vector< pair<pair<int, int>, int> > &ps) {
  {
    int x = r * 2 - b * 1;
    int y = b * 2 - r * 1;
    ps.push_back(make_pair(make_pair(x, y), val));
  }
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i].first, x = g[v][i].second.first, c = g[v][i].second.second;
    if (del[u] || u == p) {
      continue;
    }
    dfs(u, v, r + !c, b + c, mul(val, x), ps);
  }
}

vector< pair<pair<int, int>, int> > ps;

void solve(int v) {
  getTs(v, -1);
  {
    int alls = ts[v];
    int p = -1;
    while (true) {
      int nv = -1;
      for (int i = 0; i < sz(g[v]); i++) {
        int u = g[v][i].first;
        if (del[u] || u == p) {
          continue;
        }
        if (2 * ts[u] > alls) {
          nv = u;
        }
      }
      if (nv == -1) {
        break;
      }
      p = v;
      v = nv;
    }
  }
  ps.clear();
  dfs(v, -1, 0, 0, 1, ps);
  res = mul(res, get(ps));
  del[v] = true;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i].first, x = g[v][i].second.first, c = g[v][i].second.second;
    if (del[u]) {
      continue;
    }
    ps.clear();
    dfs(u, -1, !c, c, x, ps);
    todiv = mul(todiv, get(ps));
  }
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i].first;
    if (del[u]) {
      continue;
    }
    solve(u);
  }
}

void solve() {
  res = 1;
  todiv = 1;
  for (int i = 0; i < n; i++) {
    del[i] = false;
  }
  solve(0);
  res = mul(res, inv(todiv));
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