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

const int maxn = (int) 3e5 + 5;
int n, m;
long long x;
long long a[maxn];
int es[maxn][2];

bool read() {
  if (scanf("%d%d%lld", &n, &m, &x) < 3) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < 2; ++j) {
      scanf("%d", &es[i][j]);
      --es[i][j];
    }
  }
  return true;
}

int p[maxn], ts[maxn];
vector<int> g[maxn];
int del[maxn];
long long val[maxn];
set<pair<long long, int>, greater<pair<long long, int>>> st;

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

void unite1(int x, int y) {
  x = get(x);
  y = get(y);
  if (ts[x] < ts[y]) {
    swap(x, y);
  }
  ts[x] += ts[y];
  p[y] = x;
  for (int i = 0; i < sz(g[y]); ++i) {
    g[x].push_back(g[y][i]);
  }
  g[y].clear();
}

void push(int v, long long x) {
  v = get(v);
  while (!g[v].empty() && del[g[v].back()]) {
    g[v].pop_back();
  }
  if (!g[v].empty()) {
    int e = g[v].back();
    st.erase(make_pair(val[e], e));
    val[e] += x;
    st.insert(make_pair(val[e], e));
  }
}

void solve() {
  {
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += a[i];
    }
    if (sum < (n - 1) * x) {
      printf("NO\n");
      return;
    }
  }
  for (int i = 0; i < n; ++i) {
    p[i] = i;
    ts[i] = 1;
    g[i].clear();
  }
  st.clear();
  for (int i = 0; i < m; ++i) {
    int v = es[i][0], u = es[i][1];
    del[i] = !unite(v, u);
    if (!del[i]) {
      g[v].push_back(i);
      g[u].push_back(i);
      val[i] = 0;
      st.insert(make_pair(val[i], i));
    }
  }
  for (int i = 0; i < n; ++i) {
    p[i] = i;
    ts[i] = 1;
  }
  for (int i = 0; i < n; ++i) {
    push(i, a[i]);
  }
  printf("YES\n");
  while (!st.empty()) {
    int e = st.begin()->second;
    st.erase(st.begin());
    printf("%d\n", e + 1);
    del[e] = true;
    int v = es[e][0], u = es[e][1];
    unite1(v, u);
    push(v, val[e] - x);
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