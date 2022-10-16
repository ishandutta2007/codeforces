#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

mt19937 mrand(random_device{} ());

int rnd(int x) {
  return mrand() % x;
}

typedef long double ld;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define sz(x) ((int) (x).size())

const int inf = (int) 1.01e9;
const long long infll = (long long) 1.01e18;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

const int maxn = (int) 5e5 + 5;
int n, k, m;
vector<int> g[maxn];
vector<int> added[maxn];
int es[maxn][2];
int cs[maxn];

bool read() {
  if (scanf("%d%d%d", &n, &k, &m) < 3) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
    added[i].clear();
  }
  for (int i = 0; i < k; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    g[v].push_back(u);
    added[v].push_back(false);
    g[u].push_back(v);
    added[u].push_back(false);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &es[i][0], &es[i][1], &cs[i]);
    es[i][0]--;
    es[i][1]--;
  }
  return true;
}

int ts[maxn], p[maxn];

int get(int x) {
  return (p[x] == x ? x : p[x] = get(p[x]));
}

bool unite(int x, int y) {
  x = get(x);
  y = get(y);
  if (x == y) {
    return false;
  }
  if (ts[x] < ts[y]) {
    swap(x, y);
  }
  ts[x] += ts[y];
  p[y] = x;
  return true;
}

vector<pair<int, int>> evs[maxn];
set<pair<int, int>> *st[maxn];
long long res;

void dfs(int v, int p, int pe) {
  ts[v] = 1;
  int maxu = -1;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    dfs(u, v, added[v][i]);
    ts[v] += ts[u];
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
    if (u == p || u == maxu) {
      continue;
    }
    for (auto it = st[u]->begin(); it != st[u]->end(); it++) {
      auto it1 = st[v]->find(*it);
      if (it1 == st[v]->end()) {
        st[v]->insert(*it);
      } else {
        st[v]->erase(it1);
      }
    }
  }
  for (int i = 0; i < sz(evs[v]); i++) {
    auto it1 = st[v]->find(evs[v][i]);
    if (it1 == st[v]->end()) {
      st[v]->insert(evs[v][i]);
    } else {
      st[v]->erase(it1);
    }
  }
  if (!pe) {
    if (st[v]->empty()) {
      res = infll;
    } else {
      res += st[v]->begin()->first;
    }
  }
}

void solve() {
  for (int i = 0; i < n; i++) {
    ts[i] = 1;
    p[i] = i;
    evs[i].clear();
  }
  for (int v = 0; v < n; v++) {
    for (int i = 0; i < sz(g[v]); i++) {
      int u = g[v][i];
      unite(v, u);
    }
  }
  for (int i = 0; i < m; i++) {
    int v = es[i][0], u = es[i][1];
    if (unite(v, u)) {
      g[v].push_back(u);
      added[v].push_back(true);
      g[u].push_back(v);
      added[u].push_back(true);
    }
    evs[v].push_back(make_pair(cs[i], i));
    evs[u].push_back(make_pair(cs[i], i));
  }
  res = 0;
  dfs(0, -1, true);
  if (res >= infll) {
    res = -1;
  }
  printf("%lld\n", res);
}

int main() {
#ifdef DEBUG
	assert(freopen("text.in", "r", stdin));
	assert(freopen("text.out", "w", stdout));
#endif
	while (read()) {
		solve();
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
	}
	return 0;
}