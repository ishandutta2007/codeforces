#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define sz(s) ((int) ((s).size()))
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

typedef long double ld;

const int inf = (int) 1e9 + 100;
const ld eps = 1e-11;
const ld pi = acos(-1.0L);

mt19937 mrand(random_device{} ());
int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

struct Edge {
  int to, w;

  Edge() {}

  Edge(int _to, int _w): to(_to), w(_w) {}
};

const int maxn = 1005, maxm = (int)1e4 + 5;
int n, m, l, s, t;
long long d[maxn];
int pr[maxn];
Edge e[2 * maxm];
int ch[2 * maxm];
vector<int> g[maxn];

bool read() {
  if (scanf("%d%d%d%d%d", &n, &m, &l, &s, &t) < 5) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int v, u, w;
    scanf("%d%d%d", &v, &u, &w);
    g[v].push_back(2 * i);
    e[2 * i] = Edge(u, w);
    ch[2 * i] = (w == 0);
    g[u].push_back(2 * i + 1);
    e[2 * i + 1] = Edge(v, w);
    ch[2 * i + 1] = (w == 0);
  }
  return true;
}

long long dijkstra() {
  for (int i = 0; i < n; i++) {
    d[i] = (long long)n * inf;
    pr[i] = -1;
  }
  d[s] = 0;
  priority_queue<pair<long long, int>, vector< pair<long long, int> >,
                 greater< pair<long long, int> > > pq;
  pq.push(make_pair(d[s], s));
  while(!pq.empty()) {
    int v = pq.top().second;
    long long dd = pq.top().first;
    pq.pop();
    if (dd != d[v]) {
      continue;
    }
    for (int i = 0; i < sz(g[v]); i++) {
      int id = g[v][i], u = e[id].to, w = e[id].w;
      if (d[u] > d[v] + w) {
        d[u] = d[v] + w;
        pr[u] = id;
        pq.push(make_pair(d[u], u));
      }
    }
  }
  return d[t];
}

void solve() {
  for (int i = 0; i < 2 * m; i++) {
    if (ch[i]) {
      e[i].w = inf;
    }
  }
  if (dijkstra() < l) {
    printf("NO\n");
    return;
  }
  for (int i = 0; i < 2 * m; i++) {
    if (ch[i]) {
      e[i].w = 1;
    }
  }
  if (dijkstra() > l) {
    printf("NO\n");
    return;
  }
  for (int i = 0; i < 2 * m; i++) {
    if (ch[i]) {
      e[i].w = inf;
    }
  }
  vector<int> p;
  for (int v = t; v != s; v = e[pr[v] ^ 1].to) {
    if (ch[pr[v]]) {
      p.push_back(pr[v]);
    }
  }
  int ll = 0, rr = sz(p) + 1;
  while (ll < rr - 1) {
    int mid = (ll + rr) / 2;
    for (int i = 0; i < mid; i++) {
      e[p[i]].w = inf;
      e[p[i] ^ 1].w = inf;
    }
    for (int i = mid; i < sz(p); i++) {
      e[p[i]].w = 1;
      e[p[i] ^ 1].w = 1;
    }
    if (dijkstra() <= l) {
      ll = mid;
    }
    else {
      rr = mid;
    }
  }
  for (int i = 0; i < ll; i++) {
    e[p[i]].w = inf;
    e[p[i] ^ 1].w = inf;
  }
  for (int i = ll; i < sz(p); i++) {
    e[p[i]].w = 1;
    e[p[i] ^ 1].w = 1;
  }
  if (ll < sz(p)) {
    int lll = 1, rrr = inf;
    while (lll < rrr - 1) {
      int mid = (lll + rrr) / 2;
      e[p[ll]].w = mid;
      e[p[ll] ^ 1].w = mid;
      if (dijkstra() <= l) {
        lll = mid;
      }
      else {
        rrr = mid;
      }
    }
    e[p[ll]].w = lll;
    e[p[ll] ^ 1].w = lll;
  }
  printf("YES\n");
  for (int i = 0; i < m; i++) {
    printf("%d %d %d\n", e[2 * i + 1].to, e[2 * i].to, e[2 * i].w);
  }
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen("text.in", "r", stdin));
  assert(freopen("text.out", "w", stdout));
#endif

  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}