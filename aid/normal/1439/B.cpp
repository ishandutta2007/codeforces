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

const int maxn = (int) 1e5 + 5;
int n, m, k;
vector<int> g[maxn];

bool read() {
  if (scanf("%d%d%d", &n, &m, &k) < 3) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    g[i].clear();
  }
  for (int i = 0; i < m; ++i) {
    int v, u;
    scanf("%d%d", &v, &u);
    --v;
    --u;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  return true;
}

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

unordered_set<uint64_t, custom_hash> es;
int deg[maxn];
int del[maxn];
set<pair<int, int>> st;
vector<int> ans;

void printAlive() {
  ans.clear();
  for (int i = 0; i < n; ++i) {
    if (!del[i]) {
      ans.push_back(i);
    }
  }
  printf("1 %d\n", sz(ans));
  for (int i = 0; i < sz(ans); ++i) {
    printf("%d ", ans[i] + 1);
  }
  printf("\n");
}

bool checkClique(int v) {
  ans.clear();
  ans.push_back(v);
  for (int i = 0; i < sz(g[v]); ++i) {
    int u = g[v][i];
    if (!del[u]) {
      ans.push_back(u);
    }
  }
  for (int i = 1; i < sz(ans); ++i) {
    for (int j = i + 1; j < sz(ans); ++j) {
      int a = ans[i], b = ans[j];
      if (a > b) {
        swap(a, b);
      }
      if (!es.count((uint64_t) a * n + b)) {
        return false;
      }
    }
  }
  printf("2\n");
  for (int i = 0; i < sz(ans); ++i) {
    printf("%d ", ans[i] + 1);
  }
  printf("\n");
  return true;
}

void solve() {
  if ((long long) k * (k - 1) / 2 > m) {
    printf("-1\n");
    return;
  }
  es.clear();
  for (int v = 0; v < n; ++v) {
    for (int i = 0; i < sz(g[v]); ++i) {
      int u = g[v][i];
      if (v < u) {
        es.insert((uint64_t) v * n + u);
      }
    }
  }
  st.clear();
  for (int i = 0; i < n; ++i) {
    deg[i] = sz(g[i]);
    del[i] = false;
    st.insert(make_pair(deg[i], i));
  }
  while (!st.empty()) {
    int v = st.begin()->second;
    if (deg[v] >= k) {
      printAlive();
      return;
    }
    if (deg[v] == k - 1) {
      if (checkClique(v)) {
        return;
      }
    }
    st.erase(st.begin());
    del[v] = true;
    for (int i = 0; i < sz(g[v]); ++i) {
      int u = g[v][i];
      if (del[u]) {
        continue;
      }
      st.erase(make_pair(deg[u], u));
      --deg[u];
      st.insert(make_pair(deg[u], u));
    }
  }
  printf("-1\n");
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  int t;
  scanf("%d", &t);
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}