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

const int maxn = (int) 1e5 + 50;
int n, m, s;

int read() {
  if (scanf("%d%d%d", &n, &m, &s) < 3) {
    return false;
  }
  s--;
  return true;
}

vector< pair<int, int> > g[8 * maxn];
int sh;
int ids[maxn][2];

void buildst(int v, int tl, int tr) {
  if (tl == tr - 1) {
    ids[tl][0] = v;
    ids[tl][1] = v + sh;
    g[v].push_back(make_pair(v + sh, 0));
    return;
  }
  g[v].push_back(make_pair(2 * v, 0));
  g[v].push_back(make_pair(2 * v + 1, 0));
  g[sh + 2 * v].push_back(make_pair(sh + v, 0));
  g[sh + 2 * v + 1].push_back(make_pair(sh + v, 0));
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
}

void addEdgeToSeg(int v, int tl, int tr, int l, int r, int from, int w) {
  if (tl == l && tr == r) {
    g[ids[from][1]].push_back(make_pair(v, w));
    return;
  }
  int tm = (tl + tr) / 2;
  if (l < tm) {
    addEdgeToSeg(2 * v, tl, tm, l, min(r, tm), from, w);
  }
  if (r > tm) {
    addEdgeToSeg(2 * v + 1, tm, tr, max(l, tm), r, from, w);
  }
}

void addEdgeFromSeg(int v, int tl, int tr, int l, int r, int to, int w) {
  if (tl == l && tr == r) {
    g[v + sh].push_back(make_pair(ids[to][0], w));
    return;
  }
  int tm = (tl + tr) / 2;
  if (l < tm) {
    addEdgeFromSeg(2 * v, tl, tm, l, min(r, tm), to, w);
  }
  if (r > tm) {
    addEdgeFromSeg(2 * v + 1, tm, tr, max(l, tm), r, to, w);
  }
}

long long d[8 * maxn];

void solve() {
  for (int i = 0; i < 8 * n + 10; i++) {
    g[i].clear();
  }
  sh = 4 * n + 5;
  buildst(1, 0, n);
  for (int i = 0; i < m; i++) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int v, u, w;
      scanf("%d%d%d", &v, &u, &w);
      v--;
      u--;
      g[ids[v][1]].push_back(make_pair(ids[u][0], w));
      continue;
    }
    int v, l, r, w;
    scanf("%d%d%d%d", &v, &l, &r, &w);
    v--;
    l--;
    if (t == 2) {
      addEdgeToSeg(1, 0, n, l, r, v, w);
    } else {
      addEdgeFromSeg(1, 0, n, l, r, v, w);
    }
  }
  for (int i = 0; i < 2 * sh; i++) {
    d[i] = infll;
  }
  d[ids[s][0]] = 0;
  priority_queue<pair<long long, int>, vector< pair<long long, int> >, greater< pair<long long, int> > > pq;
  pq.push(make_pair(d[ids[s][0]], ids[s][0]));
  while (!pq.empty()) {
    long long dd = pq.top().first;
    int v = pq.top().second;
    pq.pop();
    if (dd != d[v]) {
      continue;
    }
    for (int i = 0; i < sz(g[v]); i++) {
      int u = g[v][i].first, w = g[v][i].second;
      if (d[v] + w < d[u]) {
        d[u] = d[v] + w;
        pq.push(make_pair(d[u], u));
      }
    }
  }
  for (int i = 0; i < n; i++) {
    long long res = d[ids[i][0]];
    if (res >= infll) {
      res = -1;
    }
    printf("%lld ", res);
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