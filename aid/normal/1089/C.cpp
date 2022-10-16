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

const int maxn = 1005;
int n;
vector<int> g[maxn];
vector<int> ids[maxn];

bool read() {
  int m;
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
    ids[i].clear();
  }
  int cur = 0;
  for (int i = 0; i < m; i++) {
    int k;
    scanf("%d", &k);
    int lst = -1;
    for (int j = 0; j < k; j++) {
      int v;
      scanf("%d", &v);
      v--;
      if (lst != -1) {
        g[v].push_back(lst);
        ids[v].push_back(cur);
        g[lst].push_back(v);
        ids[lst].push_back(cur++);
      }
      lst = v;
    }
  }
  return true;
}

vector<int> gt[maxn];
int del[maxn];
int vs;
int onc[maxn];
int inside[maxn];
int used[maxn];
int curu;
vector<int> path;

void dfs(int v, int p, int pe) {
  path.push_back(v);
  inside[v] = true;
  used[v] = curu;
  onc[v] = false;
  gt[v].clear();
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    int id = ids[v][i];
    if (del[u] || id == pe) {
      continue;
    }
    if (inside[u]) {
      int cid = vs++;
      gt[cid].clear();
      for (int i = sz(path) - 1;; i--) {
        gt[cid].push_back(path[i]);
        gt[path[i]].push_back(cid);
        if (path[i] == u) {
          break;
        }
        onc[path[i]] = true;
      }
      continue;
    }
    if (used[u] == curu) {
      continue;
    }
    dfs(u, v, id);
  }
  if (p != -1 && !onc[v]) {
    gt[p].push_back(v);
    gt[v].push_back(p);
  }
  inside[v] = false;
  path.pop_back();
}

int ts[maxn];

void getTs(int v, int p) {
  ts[v] = (v < n ? 1 : 0);
  for (int i = 0; i < sz(gt[v]); i++) {
    int u = gt[v][i];
    if (u == p) {
      continue;
    }
    getTs(u, v);
    ts[v] += ts[u];
  }
}

char tmp[100];
int cnt;

int ask(int v) {
  cnt++;
  assert(cnt <= 10);
  printf("%d\n", v + 1);
  fflush(stdout);
  scanf("%s", tmp);
  if (tmp[0] == 'F') {
    return -1;
  }
  int res;
  scanf("%d", &res);
  res--;
  return res;
}

int s[maxn];

void rec(int v) {
  vs = n;
  path.clear();
  curu++;
  dfs(v, -1, -1);
  getTs(v, -1);
  int k = ts[v];
  int pv = -1;
  while (true) {
    int nv = -1;
    for (int i = 0; i < sz(gt[v]); i++) {
      int u = gt[v][i];
      if (u == pv) {
        continue;
      }
      if (2 * ts[u] > k) {
        nv = u;
      }
    }
    if (nv == -1) {
      break;
    }
    pv = v;
    v = nv;
  }
  if (v < n) {
    int x = ask(v);
    if (x == -1) {
      return;
    }
    del[v] = true;
    rec(x);
    return;
  }
  getTs(v, -1);
  int l = sz(gt[v]);
  s[0] = 0;
  for (int i = 0; i < l; i++) {
    s[i + 1] = s[i] + ts[gt[v][i]];
  }
  for (int i = 0; i < l; i++) {
    {
      int sl = i + 1, sr = i + l / 2 + 1;
      int sum = (sr > l ? s[sr - l] + s[l] - s[sl] : s[sr] - s[sl]);
      if (2 * sum > k) {
        continue;
      }
    }
    {
      int sr = i, sl = i - (l / 2);
      int sum = (sl < 0 ? s[sr] + s[l] - s[sl + l] : s[sr] - s[sl]);
      if (2 * sum > k) {
        continue;
      }
    }
    int x = ask(gt[v][i]);
    if (x == -1) {
      return;
    }
    int sl, sr;
    if (x == gt[v][(i + 1) % l]) {
      sl = i + 1;
      sr = i + l / 2 + 1;
    } else if (x == gt[v][(i + l - 1) % l]) {
      sl = i - (l / 2);
      sr = i;
    } else {
      del[gt[v][i]] = true;
      rec(x);
      return;
    }
    for (int i = 0; i < l; i++) {
      del[gt[v][i]] = true;
    }
    for (int i = sl; i < sr; i++) {
      del[gt[v][(i + l) % l]] = false;
    }
    rec(gt[v][(sl + l) % l]);
    return;
  }
  assert(false);
}

void solve() {
  for (int it = 0; it < n; it++) {
    for (int i = 0; i < vs; i++) {
      del[i] = false;
    }
    cnt = 0;
    rec(0);
  }
}

int main() {
  precalc();
  read();
  solve();
#ifdef DEBUG
  eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}