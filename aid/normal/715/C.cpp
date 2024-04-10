#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define sz(s) ((int) ((s).size()))
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

typedef long long ll;
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

const int maxn = (int)1e5 + 5;
int n, mod;
long long ans;
int ts[maxn], del[maxn];
int p10[maxn], p10inv[maxn];
vector< pair<int, int> > g[maxn];

pair<int, int> gcd(int a, int b) {
  if (!b) {
    return make_pair(1, 0);
  }
  pair<int, int> p = gcd(b, a % b);
  return make_pair(p.second, p.first - (a / b) * p.second);
}

int inv(int x) {
  return (gcd(x, mod).first % mod + mod) % mod;
}

int mul(int a, int b) {
  return (long long)a * b % mod;
}

bool read() {
  if (scanf("%d%d", &n, &mod) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
    int v, u, w;
    scanf("%d%d%d", &v, &u, &w);
    g[v].push_back(make_pair(u, w));
    g[u].push_back(make_pair(v, w));
  }
  return true;
}

void getTs(int v, int p) {
  ts[v] = 1;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i].first;
    if (u == p || del[u]) {
      continue;
    }
    getTs(u, v);
    ts[v] += ts[u];
  }
}

void dfs(int v, int p, int dep, int up, int down,
         map<int, int> &upmp, map<pair<int, int>, int> &downmp) {
  upmp[up]++;
  downmp[make_pair(down, dep)]++;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i].first, w = g[v][i].second;
    if (u == p || del[u]) {
      continue;
    }
    dfs(u, v, dep + 1, (up + mul(w, p10[dep])) % mod,
        (mul(down, 10) + w) % mod, upmp, downmp);
  }
}

void centroid(int v) {
  getTs(v, -1);
  int sz = ts[v], pr = -1;
  bool found = true;
  while (found) {
    found = false;
    for (int i = 0; i < sz(g[v]); i++) {
      int u = g[v][i].first;
      if (u == pr || del[u]) {
        continue;
      }
      if (2 * ts[u] > sz) {
        pr = v;
        v = u;
        found = true;
        break;
      }
    }
  }
  del[v] = true;
  vector< pair<map<int, int>, map<pair<int, int>, int> > > mps;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i].first, w = g[v][i].second;
    if (del[u]) {
      continue;
    }
    mps.push_back(pair<map<int, int>, map<pair<int, int>, int> >());
    dfs(u, -1, 1, w % mod, w % mod, mps.back().first, mps.back().second);
  }
  for (int ii = 0; ii < 2; ii++) {
    map<int, int> up;
    for (int i = 0; i < sz(mps); i++) {
      map<int, int> &up0 = mps[i].first;
      map<pair<int, int>, int> &down0 = mps[i].second;
      for (auto it = down0.begin(); it != down0.end(); it++) {
        int d = it->first.first, len = it->first.second;
        int u = mul((mod - d) % mod, p10inv[len]);
        ans += (long long)up[u] * it->second;
        if (!ii && d == 0) {
          ans += it->second;
        }
      }
      if (!ii) {
        ans += up0[0];
      }
      for (auto it = up0.begin(); it != up0.end(); it++) {
        up[it->first] += it->second;
      }
    }
    reverse(mps.begin(), mps.end());
  }
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i].first;
    if (!del[u]) {
      centroid(u);
    }
  }
}

void solve() {
  p10[0] = 1;
  for (int i = 1; i < maxn; i++) {
    p10[i] = mul(10, p10[i - 1]);
  }
  p10inv[0] = 1;
  p10inv[1] = inv(10);
  for (int i = 2; i < maxn; i++) {
    p10inv[i] = mul(p10inv[1], p10inv[i - 1]);
  }
  ans = 0;
  for (int i = 0; i < n; i++) {
    del[i] = false;
  }
  centroid(0);
  printf("%lld\n", ans);
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