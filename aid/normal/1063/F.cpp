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

const int maxn = (int) 1e6 + 5;
int n;
string s;
char tmp[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  scanf("%s", tmp);
  s = tmp;
  return true;
}

const int sigma = 26;
int go[maxn][sigma];
int len[maxn], link[maxn];
int vs;
int ps[maxn];

int add(int v, int c) {
  int u = vs++;
  len[u] = len[v] + 1;
  ps[len[u]] = u;
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
  int nw = vs++;
  memcpy(go[nw], go[w], sizeof(go[w]));
  len[nw] = len[v] + 1;
  link[nw] = link[w];
  link[w] = nw;
  link[u] = nw;
  for (; v != -1 && go[v][c] == w; v = link[v]) {
    go[v][c] = nw;
  }
  return u;
}

const int logn = 20;
vector<int> g[maxn];
int tin[maxn], tout[maxn], t;
int p[maxn][logn];

void dfs(int v) {
  tin[v] = t++;
  for (int i = 1; i < logn; i++) {
    p[v][i] = p[p[v][i - 1]][i - 1];
  }
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    p[u][0] = v;
    dfs(u);
  }
  tout[v] = t;
}

int getV(int pref, int l) {
  int v = ps[pref];
  for (int i = logn - 1; i >= 0; i--) {
    if (len[p[v][i]] >= l) {
      v = p[v][i];
    }
  }
  return v;
}

int dp[maxn];
int st[4 * maxn];

void buildst(int v, int tl, int tr) {
  st[v] = 0;
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
  int res = 0;
  if (l < tm) {
    res = max(res, get(2 * v, tl, tm, l, min(r, tm)));
  }
  if (r > tm) {
    res = max(res, get(2 * v + 1, tm, tr, max(l, tm), r));
  }
  return res;
}

bool check(int i, int len) {
  int v = getV(i, len - 1), u = getV(i - 1, len - 1);
  return max(get(1, 0, vs, tin[v], tout[v]), get(1, 0, vs, tin[u], tout[u])) >= len - 1;
}

void solve() {
  reverse(s.begin(), s.end());
  memset(go, -1, sizeof(go));
  vs = 0;
  int cur = vs++;
  len[cur] = 0;
  link[cur] = -1;
  ps[0] = cur;
  for (int i = 0; i < n; i++) {
    cur = add(cur, s[i] - 'a');
  }
  t = 0;
  for (int i = 0; i < vs; i++) {
    g[i].clear();
  }
  for (int i = 1; i < vs; i++) {
    g[link[i]].push_back(i);
  }
  p[0][0] = 0;
  dfs(0);
  buildst(1, 0, vs);
  dp[0] = 0;
  int res = 0;
  for (int i = 0, j = 0; i < n; i++) {
    while (!check(i + 1, i + 1 - j)) {
      j++;
      update(1, 0, vs, tin[ps[j]], dp[j]);
    }
    dp[i + 1] = i + 1 - j;
    res = max(res, dp[i + 1]);
  }
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