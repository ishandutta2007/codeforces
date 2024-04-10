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
int n;
string s;

bool read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  s = tmp;
  n = sz(s);
  return true;
}

map<char, int> go[maxn];
int len[maxn], link[maxn];
int pid[maxn];
int vs;
int ps[maxn];

int newNode(int l) {
  go[vs].clear();
  len[vs] = l;
  link[vs] = -1;
  pid[vs] = -1;
  return vs++;
}

int addChar(int v, char c) {
  int u = newNode(len[v] + 1);
  for (; v != -1 && !go[v].count(c); v = link[v]) {
    go[v][c] = u;
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
  go[nw] = go[w];
  link[nw] = link[w];
  link[w] = nw;
  link[u] = nw;
  for (; v != -1 && go[v][c] == w; v = link[v]) {
    go[v][c] = nw;
  }
  return u;
}

vector<pair<char, int>> g[maxn];
int used[maxn];

void buildTree(int v, int pos) {
  used[v] = true;
  if (!v) {
    return;
  }
  int p = link[v];
  pos += len[v] - len[p];
  g[p].push_back(make_pair(s[pos - 1], v));
  if (!used[p]) {
    buildTree(p, pos);
  }
}

int t;
int pos[maxn];
int dep[maxn];

const int logn = 18;
int tin[maxn], tout[maxn], tt;
int p[maxn][logn];

void dfs0(int v) {
  if (pid[v] != -1) {
    pos[pid[v]] = t++;
  }
  tin[v] = tt++;
  for (int i = 1; i < logn; i++) {
    p[v][i] = p[p[v][i - 1]][i - 1];
  }
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i].second;
    dep[u] = dep[v] + len[u] - len[v];
    p[u][0] = v;
    dfs0(u);
  }
  tout[v] = tt;
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

long long res;

struct Cmp {
  bool operator () (const pair<int, int> &a, const pair<int, int> &b) {
    int sh = (a.second != -1 ? a.second : b.second);
    int x = a.first, y = b.first;
    if (sh != -1) {
      x -= sh;
      y -= sh;
    }
    return pos[x] < pos[y];
  }
};

long long dp[maxn];

set<pair<int, int>, Cmp> dfs(int v) {
  vector<int> toadd;
  set<pair<int, int>, Cmp> stv;
  dp[v] = 0;
  long long x = 0;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i].second;
    auto stu = dfs(u);
    if (sz(stu) > sz(stv)) {
      swap(stu, stv);
      toadd.clear();
      x = dp[u] + (dep[u] - dep[v]);
    }
    for (auto it = stu.begin(); it != stu.end(); it++) {
      int id = it->first;
      auto iter = stv.upper_bound(make_pair(id, dep[v] + 1));
      auto toins = iter;
      int r = (iter == stv.end() ? -1 : iter->first);
      int l = -1;
      if (iter != stv.begin()) {
        iter--;
        l = iter->first;
      }
      int d = max((l == -1 ? 0 : dep[getLca(ps[id - (dep[v] + 1)], ps[l - (dep[v] + 1)])]),
                  (r == -1 ? 0 : dep[getLca(ps[id - (dep[v] + 1)], ps[r - (dep[v] + 1)])]));
      x += id - (dep[v] + 1) - d;
      stv.insert(toins, make_pair(id, dep[v] + 1));
      toadd.push_back(id);
    }
    dp[v] += len[u] - len[v] + dp[u];
  }
  res += x;
  if (v) {
    res += (2 * dp[v] + (len[v] - len[link[v]])) * (len[v] - len[link[v]] - 1) / 2;
  }
  for (int i = 0; i < sz(toadd); i++) {
    int id = toadd[i];
    stv.erase(make_pair(id, dep[v] + 1));
  }
  for (int i = 0; i < sz(toadd); i++) {
    int id = toadd[i];
    stv.insert(make_pair(id, -1));
  }
  if (pid[v] != -1) {
    stv.insert(make_pair(pid[v], -1));
  }
  return stv;
}

void solve() {
  {
    vs = 0;
    int v = newNode(0);
    pid[v] = 0;
    ps[0] = v;
    for (int i = 0; i < n; i++) {
      v = addChar(v, s[i]);
      pid[v] = i + 1;
      ps[i + 1] = v;
    }
  }
  for (int i = 0; i < vs; i++) {
    g[i].clear();
    used[i] = false;
  }
  for (int i = 0; i <= n; i++) {
    if (!used[ps[i]]) {
      buildTree(ps[i], 0);
    }
  }
  for (int i = 0; i < vs; i++) {
    sort(g[i].begin(), g[i].end());
  }
  t = 0;
  tt = 0;
  dep[0] = 0;
  p[0][0] = 0;
  dfs0(0);
  res = 1;
  for (int v = 1; v < vs; v++) {
    res += len[v] - len[link[v]];
  }
  dfs(0);
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