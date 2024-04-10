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

const int mod = (int) 1e9 + 7;

int mul(int a, int b) {
  return (long long) a * b % mod;
}

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

const int maxn = (int) 1e5 + 5;
int n, m;
vector<int> g[maxn], lens[maxn];
vector<string> ids[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
    lens[i].clear();
    ids[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    int x = i + 1;
    string s;
    while (x) {
      s += (char) ('0' + (x % 10));
      x /= 10;
    }
    reverse(s.begin(), s.end());
    g[v].push_back(u);
    lens[v].push_back(sz(s));
    ids[v].push_back(s);
    g[u].push_back(v);
    lens[u].push_back(sz(s));
    ids[u].push_back(s);
  }
  return true;
}

const int maxv = maxn * 5 + 5;
const int logv = 20;
const int maxd = 10;
int go[maxv][maxd];
int pe[maxv];
int val[maxv];
int p[maxv][logv];
int vs;

int newNode(int par, int e, int x) {
  for (int i = 0; i < maxd; i++) {
    go[vs][i] = -1;
  }
  pe[vs] = e;
  val[vs] = x;
  p[vs][0] = par;
  for (int i = 1; i < logv; i++) {
    p[vs][i] = p[p[vs][i - 1]][i - 1];
  }
  return vs++;
}

int goS(int v, const string &s) {
  for (int i = 0; i < sz(s); i++) {
    int c = s[i] - '0';
    if (go[v][c] == -1) {
      int nval = mul(val[v], 10);
      add(nval, c);
      go[v][c] = newNode(v, c, nval);
    }
    v = go[v][c];
  }
  return v;
}

bool cmp(int v, int u) {
  if (v == u) {
    return false;
  }
  for (int i = logv - 1; i >= 0; i--) {
    if (p[v][i] != p[u][i]) {
      v = p[v][i];
      u = p[u][i];
    }
  }
  return pe[v] < pe[u];
}

int dist[maxn];
int ver[maxn];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void solve() {
  vs = 0;
  while (!pq.empty()) {
    pq.pop();
  }
  for (int i = 0; i < n; i++) {
    dist[i] = inf;
  }
  dist[0] = 0;
  ver[0] = newNode(0, -1, 0);
  pq.push(make_pair(0, 0));
  while (!pq.empty()) {
    int dd = pq.top().first, v = pq.top().second;
    pq.pop();
    if (dd != dist[v]) {
      continue;
    }
    for (int i = 0; i < sz(g[v]); i++) {
      int u = g[v][i], w = lens[v][i];
      const auto &s = ids[v][i];
      if (dd + w < dist[u]) {
        dist[u] = dd + w;
        ver[u] = goS(ver[v], s);
        pq.push(make_pair(dist[u], u));
      } else if (dd + w == dist[u]) {
        int cur = goS(ver[v], s);
        if (cmp(cur, ver[u])) {
          ver[u] = cur;
        }
      }
    }
  }
  for (int i = 1; i < n; i++) {
    printf("%d\n", val[ver[i]]);
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