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
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

const int mod[2] = {(int) 1e9 + 7, (int) 1e9 + 9};

struct Hash {
  static const int n = 2;
  int a[n];

  Hash(int x = 0) {
    for (int i = 0; i < n; i++) {
      a[i] = x % mod[i];
    }
  }

  Hash operator + (const Hash &h) const {
    Hash res;
    for (int i = 0; i < n; i++) {
      res.a[i] = a[i] + h.a[i];
      if (res.a[i] >= mod[i]) {
        res.a[i] -= mod[i];
      }
    }
    return res;
  }

  Hash operator - (const Hash &h) const {
    Hash res;
    for (int i = 0; i < n; i++) {
      res.a[i] = a[i] - h.a[i];
      if (res.a[i] < 0) {
        res.a[i] += mod[i];
      }
    }
    return res;
  }

  Hash operator * (const Hash &h) const {
    Hash res;
    for (int i = 0; i < n; i++) {
      res.a[i] = (long long) a[i] * h.a[i] % mod[i];
    }
    return res;
  }

  bool operator < (const Hash &h) const {
    for (int i = 0; i < n; i++) {
      if (a[i] != h.a[i]) {
        return a[i] < h.a[i];
      }
    }
    return false;
  }
};

const int maxn = (int) 3e5 + 5;
Hash ps[maxn];

void precalc() {
  ps[0] = Hash(1);
  for (int i = 0; i < 2; i++) {
    ps[1].a[i] = 12345 + rnd(1000);
  }
  for (int i = 0; i + 1 < maxn; i++) {
    ps[i + 1] = ps[i] * ps[1];
  }
}

int n;
vector< pair<int, char> > g[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
    int v, u;
    char x;
    scanf("%d%d %c", &v, &u, &x);
    v--;
    u--;
    g[v].push_back(make_pair(u, x));
    g[u].push_back(make_pair(v, x));
  }
  return true;
}

Hash h[maxn];
int dep[maxn];
int ts[maxn];
map<Hash, int> *mps[maxn];
int cnt[maxn];

void dfs(int v, int p) {
  ts[v] = 1;
  int maxu = -1;
  int maxw = -1;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i].first, w = g[v][i].second;
    if (u == p) {
      continue;
    }
    dep[u] = dep[v] + 1;
    h[u] = h[v] + Hash(w) * ps[dep[v]];
    dfs(u, v);
    if (maxu == -1 || ts[u] > ts[maxu]) {
      maxu = u;
      maxw = w;
    }
    ts[v] += ts[u];
  }
  if (maxu == -1) {
    mps[v] = new map<Hash, int>();
    (*mps[v])[h[v]]++;
    cnt[v] = 1;
    return;
  }
  mps[v] = mps[maxu];
  auto &mp = *mps[v];
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i].first, w = g[v][i].second;
    if (u == p || u == maxu) {
      continue;
    }
    auto &cur = *mps[u];
    for (auto it = cur.begin(); it != cur.end(); it++) {
      Hash h0 = it->first;
      int val = it->second;
      Hash h1 = h0 + (Hash(maxw) - Hash(w)) * ps[dep[v]];
      mp[h1] += val;
    }
  }
  cnt[v] = sz(mp);
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i].first, w = g[v][i].second;
    if (u == p || u == maxu) {
      continue;
    }
    auto &cur = *mps[u];
    for (auto it = cur.begin(); it != cur.end(); it++) {
      Hash h0 = it->first;
      int val = it->second;
      Hash h1 = h0 + (Hash(maxw) - Hash(w)) * ps[dep[v]];
      mp[h1] -= val;
      if (!mp[h1]) {
        mp.erase(h1);
      }
      mp[h0] += val;
    }
  }
  mp[h[v]]++;
}

vector<int> a[maxn];

void solve() {
  h[0] = Hash(0);
  dep[0] = 0;
  dfs(0, -1);
  for (int i = 0; i < n; i++) {
    a[i].clear();
  }
  for (int v = 0; v < n; v++) {
    a[dep[v]].push_back(cnt[v]);
  }
  int res = inf, resdep = inf;
  int up = 0;
  for (int i = 0; i < n; i++) {
    int cur = up;
    for (int j = 0; j < sz(a[i]); j++) {
      cur += a[i][j];
    }
    if (cur < res) {
      res = cur;
      resdep = i + 1;
    }
    up += sz(a[i]);
  }
  printf("%d %d\n", res, resdep);
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