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
int n;
vector<pair<int, int>> g[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
    int v, u, w;
    scanf("%d%d%d", &v, &u, &w);
    v--;
    u--;
    g[v].push_back(make_pair(u, w));
    g[u].push_back(make_pair(v, w));
  }
  return true;
}

long long res;
int ts[maxn];

void dfs(int v, int p, int pw) {
  ts[v] = 1;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i].first, w = g[v][i].second;
    if (u == p) {
      continue;
    }
    dfs(u, v, w);
    ts[v] += ts[u];
  }
  if (p != -1) {
    res += (long long) pw * min(ts[v], n - ts[v]);
  }
}

void dfs1(int v, int p, vector<int> &vs) {
  vs.push_back(v);
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i].first;
    if (u == p) {
      continue;
    }
    dfs1(u, v, vs);
  }
}

int cnt[maxn];
int c[maxn];
vector<vector<int>> vs;
set<pair<int, int>> mns;
set<pair<int, int>, greater<pair<int, int>>> st;
int ans[maxn];

void solve() {
  res = 0;
  dfs(0, -1, -1);
  res *= 2;
  printf("%lld\n", res);
  if (n == 1) {
    printf("%d\n", 1);
    return;
  }
  if (n == 2) {
    printf("%d %d\n", 2, 1);
    return;
  }
  int v = 0;
  int p = -1;
  while (true) {
    int nv = -1;
    for (int i = 0; i < sz(g[v]); i++) {
      int u = g[v][i].first;
      if (u == p) {
        continue;
      }
      if (2 * ts[u] > n) {
        nv = u;
        break;
      }
    }
    if (nv == -1) {
      break;
    }
    p = v;
    v = nv;
  }
  vs.clear();
  mns.clear();
  st.clear();
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i].first;
    vs.push_back({});
    dfs1(u, v, vs.back());
    sort(vs.back().begin(), vs.back().end(), greater<int>());
    for (int j = 0; j < sz(vs.back()); j++) {
      int w = vs.back()[j];
      c[w] = i;
    }
    cnt[i] = sz(vs.back()) * 2;
    mns.insert(make_pair(vs.back().back(), i));
    st.insert(make_pair(cnt[i], i));
  }
  vs.push_back({v});
  c[v] = sz(vs) - 1;
  cnt[sz(vs) - 1] = 2;
  mns.insert(make_pair(vs.back().back(), sz(vs) - 1));
  st.insert(make_pair(cnt[sz(vs) - 1], sz(vs) - 1));
  vector<int> big;
  for (int i = 0; i < n; i++) {
    int a = c[i], b = -1;
    if (cnt[a] == n - i) {
      auto it = mns.begin();
      if (i != v && it->second == a) {
        it++;
      }
      b = it->second;
    } else {
      big.clear();
      for (auto it = st.begin(); it != st.end(); it++) {
        if (it->first < n - i) {
          break;
        }
        if (it->second != sz(vs) - 1) {
          big.push_back(it->second);
        }
      }
      if (big.empty()) {
        auto it = mns.begin();
        if (i != v && it->second == a) {
          it++;
        }
        b = it->second;
      } else {
        b = big[0];
      }
    }
    mns.erase(make_pair(vs[b].back(), b));
    st.erase(make_pair(cnt[a], a));
    st.erase(make_pair(cnt[b], b));
    ans[i] = vs[b].back();
    vs[b].pop_back();
    cnt[a]--;
    cnt[b]--;
    if (!vs[b].empty()) {
      mns.insert(make_pair(vs[b].back(), b));
    }
    st.insert(make_pair(cnt[a], a));
    st.insert(make_pair(cnt[b], b));
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", ans[i] + 1);
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