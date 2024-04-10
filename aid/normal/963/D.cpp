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

const int maxn = (int) 2e5 + 5;
char tmp[maxn];
string s;
int n;
int ks[maxn];
string ts[maxn];

int read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  s = tmp;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%s", &ks[i], tmp);
    ts[i] = tmp;
  }
  return true;
}

const int sigma = 26;
int vs;
int go[maxn][sigma];
int ids[maxn];
int link[maxn];
int tlink[maxn];

int newNode() {
  for (int i = 0; i < sigma; i++) {
    go[vs][i] = -1;
  }
  ids[vs] = -1;
  link[vs] = -1;
  tlink[vs] = -1;
  return vs++;
}

int root;

void add(const string &t, int id) {
  int v = root;
  for (int i = 0; i < sz(t); i++) {
    if (go[v][t[i] - 'a'] == -1) {
      go[v][t[i] - 'a'] = newNode();
    }
    v = go[v][t[i] - 'a'];
  }
  ids[v] = id;
}

void buildAho() {
  vector<int> q;
  for (int i = 0; i < sigma; i++) {
    if (go[root][i] == -1) {
      go[root][i] = root;
    } else {
      int v = go[root][i];
      link[v] = root;
      q.push_back(v);
    }
  }
  for (int l = 0; l < sz(q); l++) {
    int v = q[l];
    for (int i = 0; i < sigma; i++) {
      if (go[v][i] == -1) {
        go[v][i] = go[link[v]][i];
      } else {
        int u = go[v][i];
        link[u] = go[link[v]][i];
        tlink[u] = (ids[link[u]] == -1 ? tlink[link[u]] : link[u]);
        q.push_back(u);
      }
    }
  }
}

vector<int> ps[maxn];

void solve() {
  vs = 0;
  root = newNode();
  for (int i = 0; i < n; i++) {
    add(ts[i], i);
    ps[i].clear();
  }
  buildAho();
  int v = root;
  for (int i = 0; i < sz(s); i++) {
    v = go[v][s[i] - 'a'];
    int cur = v;
    while (cur >= 0) {
      if (ids[cur] != -1) {
        ps[ids[cur]].push_back(i);
      }
      cur = tlink[cur];
    }
  }
  for (int id = 0; id < n; id++) {
    int res = inf;
    int k = ks[id];
    for (int i = 0; i + k - 1 < sz(ps[id]); i++) {
      res = min(res, ps[id][i + k - 1] - ps[id][i] + sz(ts[id]));
    }
    if (res >= inf) {
      res = -1;
    }
    printf("%d\n", res);
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