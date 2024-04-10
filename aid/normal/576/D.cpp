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

const int maxn = 155;
int n, m;
pair<int, pair<int, int>> es[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < m; i++) {
    int v, u, w;
    scanf("%d%d%d", &v, &u, &w);
    v--;
    u--;
    es[i] = make_pair(w, make_pair(v, u));
  }
  return true;
}

bitset<maxn> mulVec(const bitset<maxn> &v, const vector<bitset<maxn>> &a) {
  bitset<maxn> res;
  for (int i = 0; i < n; i++) {
    if (v[i]) {
      res |= a[i];
    }
  }
  return res;
}

vector<bitset<maxn>> mulMat(const vector<bitset<maxn>> &a, const vector<bitset<maxn>> &b) {
  vector<bitset<maxn>> c(maxn);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j]) {
        c[i] |= b[j];
      }
    }
  }
  return c;
}

bitset<maxn> go(const bitset<maxn> &s, int d, int m) {
  vector<bitset<maxn>> a(maxn);
  for (int i = 0; i < m; i++) {
    int v = es[i].second.first, u = es[i].second.second;
    a[v][u] = true;
  }
  bitset<maxn> t = s;
  while (d) {
    if (d & 1) {
      t = mulVec(t, a);
    }
    d >>= 1;
    a = mulMat(a, a);
  }
  return t;
}

int d[maxn];
vector<int> gr[maxn];

int getDist(const bitset<maxn> &s, int m) {
  for (int i = 0; i < n; i++) {
    d[i] = inf;
    gr[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int v = es[i].second.first, u = es[i].second.second;
    gr[u].push_back(v);
  }
  vector<int> q;
  d[n - 1] = 0;
  q.push_back(n - 1);
  for (int l = 0; l < sz(q); l++) {
    int v = q[l];
    if (s[v]) {
      return d[v];
    }
    for (int i = 0; i < sz(gr[v]); i++) {
      int u = gr[v][i];
      if (d[u] >= inf) {
        d[u] = d[v] + 1;
        q.push_back(u);
      }
    }
  }
  return inf;
}

void solve() {
  sort(es, es + m);
  bitset<maxn> dp;
  dp[0] = true;
  int res = inf;
  int t = 0;
  for (int i = 0; i < m; i++) {
    dp = go(dp, es[i].first - t, i);
    t = es[i].first;
    int cur = getDist(dp, i + 1);
    if (cur < inf) {
      cur += t;
      res = min(res, cur);
    }
  }
  if (res >= inf) {
    printf("Impossible\n");
    return;
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