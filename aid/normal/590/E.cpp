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

const int maxn = 755, maxl = (int) 1e7 + 5;
int n;
char tmp[maxl];
string ss[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%s", tmp);
    ss[i] = tmp;
  }
  return true;
}

int go[maxl][2];
int t[maxl];
int link[maxl];
int tlink[maxl];
int vs;

int newNode() {
  assert(vs < maxl);
  for (int i = 0; i < 2; i++) {
    go[vs][i] = -1;
  }
  t[vs] = -1;
  link[vs] = -1;
  tlink[vs] = -1;
  return vs++;
}

void addString(const string &s, int id) {
  int v = 0;
  for (int i = 0; i < sz(s); i++) {
    int c = s[i] - 'a';
    if (go[v][c] == -1) {
      go[v][c] = newNode();
    }
    v = go[v][c];
  }
  t[v] = id;
}

int gg[maxn][maxn];
vector<int> gs[maxn];
int p[maxn], q[maxn];
int used[maxn];

bool dfs0(int v) {
  used[v] = true;
  for (int i = 0; i < sz(gs[v]); i++) {
    int u = gs[v][i];
    if (q[u] == -1) {
      q[u] = v;
      p[v] = u;
      return true;
    }
  }
  for (int i = 0; i < sz(gs[v]); i++) {
    int u = gs[v][i];
    if (!used[q[u]] && dfs0(q[u])) {
      q[u] = v;
      p[v] = u;
      return true;
    }
  }
  return false;
}

int used1[maxn];

void dfs1(int v) {
  used[v] = true;
  for (int i = 0; i < sz(gs[v]); i++) {
    int u = gs[v][i];
    used1[u] = true;
    int w = q[u];
    if (!used[w]) {
      dfs1(w);
    }
  }
}

vector<int> qq;

void solve() {
  {
    vs = 0;
    newNode();
    for (int i = 0; i < n; i++) {
      addString(ss[i], i);
    }
    qq.clear();
    link[0] = 0;
    tlink[0] = 0;
    for (int c = 0; c < 2; c++) {
      if (go[0][c] == -1) {
        go[0][c] = 0;
      } else {
        int u = go[0][c];
        link[u] = 0;
        tlink[u] = (t[u] != -1 ? u : 0);
        qq.push_back(u);
      }
    }
    for (int l = 0; l < sz(qq); l++) {
      int v = qq[l];
      for (int c = 0; c < 2; c++) {
        if (go[v][c] == -1) {
          go[v][c] = go[link[v]][c];
        } else {
          int u = go[v][c];
          link[u] = go[link[v]][c];
          tlink[u] = (t[u] != -1 ? u : tlink[link[u]]);
          qq.push_back(u);
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      gg[i][j] = false;
    }
  }
  for (int i = 0; i < n; i++) {
    int v = 0;
    for (int j = 0; j < sz(ss[i]); j++) {
      v = go[v][ss[i][j] - 'a'];
      int id = t[tlink[v]];
      if (id != -1) {
        gg[i][id] = true;
      }
    }
    {
      int id = t[tlink[link[v]]];
      if (id != -1) {
        gg[i][id] = true;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (gg[j][i] && gg[i][k]) {
          gg[j][k] = true;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    p[i] = -1;
    q[i] = -1;
    gs[i].clear();
    for (int j = 0; j < n; j++) {
      if (j != i && gg[i][j]) {
        gs[i].push_back(j);
      }
    }
  }
  int res = 0;
  while (true) {
    for (int i = 0; i < n; i++) {
      used[i] = false;
    }
    bool found = false;
    for (int v = 0; v < n; v++) {
      if (!used[v] && p[v] == -1 && dfs0(v)) {
        found = true;
        res++;
      }
    }
    if (!found) {
      break;
    }
  }
  res = n - res;
  for (int i = 0; i < n; i++) {
    used[i] = false;
    used1[i] = false;
  }
  for (int v = 0; v < n; v++) {
    if (!used[v] && p[v] == -1) {
      dfs1(v);
    }
  }
  vector<int> ans;
  for (int v = 0; v < n; v++) {
    if (used[v] && !used1[v]) {
      ans.push_back(v);
    }
  }
  assert(sz(ans) == res);
  printf("%d\n", res);
  for (int i = 0; i < res; i++) {
    printf("%d ", ans[i] + 1);
  }
  printf("\n");
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