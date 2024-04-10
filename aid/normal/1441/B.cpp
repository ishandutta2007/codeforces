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

const int mod = 998244353;

int mul(int a, int b) {
  return (long long) a * b % mod;
}

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

const int maxn = (int) 2e5 + 5;
int n, m;
vector<int> g[2][maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    g[0][i].clear();
    g[1][i].clear();
  }
  for (int i = 0; i < m; ++i) {
    int v, u;
    scanf("%d%d", &v, &u);
    --v;
    --u;
    g[0][v].push_back(u);
    g[1][u].push_back(v);
  }
  return true;
}

const int maxk = 21;
int d[maxk][maxn];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
vector<vector<int>> q;
pair<int, int> dd[2][maxn];

void solve() {
  while (!pq.empty()) {
    pq.pop();
  }
  for (int i = 0; i < maxk; ++i) {
    for (int v = 0; v < n; ++v) {
      d[i][v] = inf;
    }
  }
  d[0][0] = 0;
  pq.push(make_pair(0, make_pair(0, 0)));
  while (!pq.empty()) {
    int dd = pq.top().first;
    int k = pq.top().second.first, v = pq.top().second.second;
    pq.pop();
    if (dd != d[k][v]) {
      continue;
    }
    const auto &gg = g[k & 1][v];
    for (int i = 0; i < sz(gg); ++i) {
      int u = gg[i];
      if (dd + 1 < d[k][u]) {
        d[k][u] = dd + 1;
        pq.push(make_pair(d[k][u], make_pair(k, u)));
      }
    }
    if (k + 1 < maxk && dd + (1 << k) < d[k + 1][v]) {
      d[k + 1][v] = dd + (1 << k);
      pq.push(make_pair(d[k + 1][v], make_pair(k + 1, v)));
    }
  }
  q.clear();
  q.push_back({});
  for (int t = 0; t < 2; ++t) {
    for (int i = 0; i < n; ++i) {
      dd[t][i] = make_pair(inf, inf);
    }
  }
  dd[0][0] = make_pair(0, 0);
  pq.push(make_pair(0, make_pair(0, 0)));
  while (!pq.empty()) {
    int k = pq.top().first;
    int t = (k & 1);
    int d = pq.top().second.first, v = pq.top().second.second;
    pq.pop();
    if (make_pair(k, d) != dd[t][v]) {
      continue;
    }
    const auto &gg = g[k & 1][v];
    for (int i = 0; i < sz(gg); ++i) {
      int u = gg[i];
      if (make_pair(k, d + 1) < dd[t][u]) {
        dd[t][u] = make_pair(k, d + 1);
        pq.push(make_pair(k, make_pair(d + 1, u)));
      }
    }
    if (make_pair(k + 1, d) < dd[t ^ 1][v]) {
      dd[t ^ 1][v] = make_pair(k + 1, d);
      pq.push(make_pair(k + 1, make_pair(d, v)));
    }
  }
  int res = inf;
  for (int k = 0; k < maxk; ++k) {
    res = min(res, d[k][n - 1]);
  }
  if (res >= inf) {
    int t = (dd[0][n - 1] < dd[1][n - 1] ? 0 : 1);
    res = dd[t][n - 1].second % mod;
    int p2 = 1;
    for (int i = 0; i < dd[t][n - 1].first; ++i) {
      add(res, p2);
      p2 = mul(p2, 2);
    }
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