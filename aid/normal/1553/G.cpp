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

const int maxx = (int) 1e6 + 5;
int lDiv[maxx], pid[maxx];
vector<int> pr;

void precalc() {
  for (int i = 0; i < maxx; ++i) {
    pid[i] = -1;
  }
  for (int i = 2; i < maxx; ++i) {
    if (!lDiv[i]) {
      lDiv[i] = i;
      pid[i] = sz(pr);
      pr.push_back(i);
    }
    for (int j = 0; j < sz(pr) && pr[j] <= lDiv[i]; ++j) {
      int p = pr[j] * i;
      if (p >= maxx) {
        break;
      }
      lDiv[p] = pr[j];
    }
  }
  eprintf("%d\n", sz(pr));
}

const int maxn = (int) 2e5 + 5;
int n, q;
int a[maxn];

bool read() {
  if (scanf("%d%d", &n, &q) < 2) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  return true;
}

vector<int> par, ts;
vector<vector<int>> g;
vector<int> cs;

int get(int x) {
  return (x == par[x] ? x : par[x] = get(par[x]));
}

void unite(int x, int y) {
  x = get(x);
  y = get(y);
  if (x == y) {
    return;
  }
  if (ts[x] < ts[y]) {
    swap(x, y);
  }
  ts[x] += ts[y];
  par[y] = x;
}

void solve() {
  par.resize(sz(pr));
  ts.resize(sz(pr));
  for (int i = 0; i < sz(pr); ++i) {
    par[i] = i;
    ts[i] = 1;
  }
  for (int i = 0; i < n; ++i) {
    int x = a[i];
    int prv = -1;
    while (x > 1) {
      int p = lDiv[x];
      while (!(x % p)) {
        x /= p;
      }
      if (prv != -1) {
        unite(pid[prv], pid[p]);
      }
      prv = p;
    }
  }
  g.clear();
  g.resize(sz(pr));
  for (int i = 0; i < n; ++i) {
    cs.clear();
    cs.push_back(get(pid[lDiv[a[i]]]));
    int x = a[i] + 1;
    while (x > 1) {
      int p = lDiv[x];
      while (!(x % p)) {
        x /= p;
      }
      cs.push_back(get(pid[p]));
    }
    sort(cs.begin(), cs.end());
    cs.erase(unique(cs.begin(), cs.end()), cs.end());
    for (int j = 0; j < sz(cs); ++j) {
      for (int k = j + 1; k < sz(cs); ++k) {
        int v = cs[j], u = cs[k];
        if (v > u) {
          swap(v, u);
        }
        g[v].push_back(u);
      }
    }
  }
  for (int v = 0; v < sz(pr); ++v) {
    sort(g[v].begin(), g[v].end());
    g[v].erase(unique(g[v].begin(), g[v].end()), g[v].end());
  }
  for (int qq = 0; qq < q; ++qq) {
    int i, j;
    scanf("%d%d", &i, &j);
    --i;
    --j;
    int v = get(pid[lDiv[a[i]]]);
    int u = get(pid[lDiv[a[j]]]);
    if (v == u) {
      printf("0\n");
      continue;
    }
    if (v > u) {
      swap(v, u);
    }
    if (binary_search(g[v].begin(), g[v].end(), u)) {
      printf("1\n");
      continue;
    }
    printf("2\n");
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