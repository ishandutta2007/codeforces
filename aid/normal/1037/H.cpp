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
char tmp[maxn];
string s;
int q;
int ql[maxn], qr[maxn];
string qx[maxn];

bool read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  s = tmp;
  n = sz(s);
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d%d%s", &ql[i], &qr[i], tmp);
    ql[i]--;
    qx[i] = tmp;
  }
  return true;
}

const int sigma = 26;
int go[maxn][sigma];
int len[maxn];
int link[maxn];
int vs;

int newNode(int l) {
  for (int i = 0; i < sigma; i++) {
    go[vs][i] = -1;
  }
  len[vs] = l;
  link[vs] = -1;
  return vs++;
}

int addChar(int c, int v) {
  int u = newNode(len[v] + 1);
  while (v != -1 && go[v][c] == -1) {
    go[v][c] = u;
    v = link[v];
  }
  if (v == -1) {
    link[u] = 0;
    return u;
  }
  int w = go[v][c];
  if (len[w] == len[v] + 1) {
    link[u] = w;
    return u;
  }
  int nw = newNode(len[v] + 1);
  memcpy(go[nw], go[w], sizeof(go[w]));
  link[nw] = link[w];
  link[w] = nw;
  link[u] = nw;
  while (v != -1 && go[v][c] == w) {
    go[v][c] = nw;
    v = link[v];
  }
  return u;
}

int ps[maxn];
vector<int> g[maxn];
int tin[maxn], tout[maxn], t;

void dfs(int v) {
  tin[v] = t++;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    dfs(u);
  }
  tout[v] = t;
}

int st[4 * maxn];

void buildst(int v, int tl, int tr) {
  st[v] = -1;
  if (tl == tr - 1) {
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
}

void update(int v, int tl, int tr, int pos, int val) {
  if (tl == tr - 1) {
    st[v] = max(st[v], val);
    return;
  }
  int tm = (tl + tr) / 2;
  if (pos < tm) {
    update(2 * v, tl, tm, pos, val);
  } else {
    update(2 * v + 1, tm, tr, pos, val);
  }
  st[v] = max(st[2 * v], st[2 * v + 1]);
}

int get(int v, int tl, int tr, int l, int r) {
  if (l == tl && r == tr) {
    return st[v];
  }
  int tm = (tl + tr) / 2;
  int res = -1;
  if (l < tm) {
    res = max(res, get(2 * v, tl, tm, l, min(r, tm)));
  }
  if (r > tm) {
    res = max(res, get(2 * v + 1, tm, tr, max(l, tm), r));
  }
  return res;
}

int getPos(int v, int len) {
  return get(1, 0, vs, tin[v], tout[v]) - len;
}

vector<int> qs[maxn];
string qans[maxn];

void solve() {
  {
    vs = 0;
    int curv = newNode(0);
    ps[0] = curv;
    for (int i = 0; i < n; i++) {
      curv = addChar(s[i] - 'a', curv);
      ps[i + 1] = curv;
    }
  }
  for (int i = 0; i < vs; i++) {
    g[i].clear();
  }
  for (int i = 1; i < vs; i++) {
    g[link[i]].push_back(i);
  }
  t = 0;
  dfs(0);
  buildst(1, 0, vs);
  for (int i = 0; i <= n; i++) {
    qs[i].clear();
  }
  for (int i = 0; i < q; i++) {
    qs[qr[i]].push_back(i);
  }
  for (int r = 0; r <= n; r++) {
    {
      int v = ps[r];
      update(1, 0, vs, tin[v], r);
    }
    for (int it = 0; it < sz(qs[r]); it++) {
      int id = qs[r][it];
      int v = 0;
      const auto &x = qx[id];
      int anslen = -1;
      char ansc = 'a';
      for (int i = 0; i <= sz(x); i++) {
        int c = (i < sz(x) ? x[i] - 'a' : -1);
        for (int cc = c + 1; cc < sigma; cc++) {
          if (go[v][cc] == -1) {
            continue;
          }
          int u = go[v][cc];
          if (getPos(u, i + 1) < ql[id]) {
            continue;
          }
          anslen = i;
          ansc = (char) ('a' + cc);
          break;
        }
        if (i >= sz(x)) {
          break;
        }
        if (go[v][c] == -1) {
          break;
        }
        int u = go[v][c];
        if (getPos(u, i + 1) < ql[id]) {
          break;
        }
        v = u;
      }
      if (anslen == -1) {
        qans[id] = "-1";
      } else {
        qans[id] = x.substr(0, anslen) + ansc;
      }
    }
  }
  for (int i = 0; i < q; i++) {
    printf("%s\n", qans[i].c_str());
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