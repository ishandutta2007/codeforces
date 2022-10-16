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

void precalc() {
}

const int maxn = (int) 1e5 + 5;
int n;
int root;
vector<int> g[maxn];
int ts[maxn];
map<int, int> *mp[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < n; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    if (v == -1) {
      root = u;
      continue;
    }
    g[v].push_back(u);
  }
  return true;
}

void dfs0(int v) {
  ts[v] = 1;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    dfs0(u);
    ts[v] += ts[u];
  }
  int maxu = -1;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (2 * ts[u] > ts[v]) {
      maxu = u;
    }
  }
  if (maxu != -1) {
    mp[v] = mp[maxu];
  } else {
    mp[v] = new map<int, int>();
  }
  (*mp[v])[ts[v]]++;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == maxu) {
      continue;
    }
    for (auto it = mp[u]->begin(); it != mp[u]->end(); it++) {
      (*mp[v])[it->first] += it->second;
    }
  }
}

int res[maxn];
map<int, int> mpup;
map<int, int> mppath;
vector<map<int, int> *> bigmp;

void del(map<int, int> *mp, int x, int todel) {
  int &val = (*mp)[x];
  assert(val >= todel);
  val -= todel;
  if (!val) {
    mp->erase(x);
  }
}

void dfs(int v) {
  int maxu = -1;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (2 * ts[u] > ts[v]) {
      maxu = u;
    }
  }
  if (maxu != -1) {
    del(mp[v], ts[v], 1);
    for (int i = 0; i < sz(g[v]); i++) {
      int u = g[v][i];
      if (u == maxu) {
        continue;
      }
      for (auto it = mp[u]->begin(); it != mp[u]->end(); it++) {
        del(mp[v], it->first, it->second);
      }
    }
  }
  {
    int tsup = n - ts[v];
    if (g[v].empty()) {
      res[v] = tsup;
    } else if (!tsup && sz(g[v]) == 1) {
      res[v] = ts[g[v][0]];
    } else {
      res[v] = inf;
      pair<int, int> maxval = make_pair(tsup, -1), minval = make_pair(tsup, -1);
      if (!tsup) {
        minval = make_pair(inf, -1);
      }
      for (int i = 0; i < sz(g[v]); i++) {
        int u = g[v][i];
        pair<int, int> cur = make_pair(ts[u], u);
        maxval = max(maxval, cur);
        minval = min(minval, cur);
      }
      assert(minval != maxval);
      int x = maxval.first - (maxval.first + minval.first + 1) / 2;
      int a, b;
      int y = inf;
      if (maxval.second != -1) {
        int u = maxval.second;
        auto it = mp[u]->upper_bound(x);
        assert(it != mp[u]->end());
        y = it->first;
      } else {
        auto it = mpup.upper_bound(x);
        if (it != mpup.end()) {
          y = min(y, it->first);
        }
        it = mppath.upper_bound(x + ts[v]);
        if (it != mppath.end()) {
          y = min(y, it->first - ts[v]);
        }
        for (int i = 0; i < sz(bigmp); i++) {
          it = bigmp[i]->upper_bound(x);
          if (it != bigmp[i]->end()) {
            y = min(y, it->first);
          }
        }
      }
      assert(y != inf);
      a = minval.first + y;
      b = maxval.first - y;
      int val = max(a, b);
      if (minval.second != -1 && maxval.second != -1) {
        val = max(val, tsup);
      }
      for (int i = 0; i < sz(g[v]); i++) {
        int u = g[v][i];
        if (minval.second != u && maxval.second != u) {
          val = max(val, ts[u]);
        }
      }
      res[v] = min(res[v], val);
      y = 0;
      if (maxval.second != -1) {
        int u = maxval.second;
        auto it = mp[u]->upper_bound(x);
        if (it != mp[u]->begin()) {
          it--;
          y = it->first;
        }
      } else {
        auto it = mpup.upper_bound(x);
        if (it != mpup.begin()) {
          it--;
          y = max(y, it->first);
        }
        it = mppath.upper_bound(x + ts[v]);
        if (it != mppath.begin()) {
          it--;
          y = max(y, it->first - ts[v]);
        }
        for (int i = 0; i < sz(bigmp); i++) {
          it = bigmp[i]->upper_bound(x);
          if (it != bigmp[i]->begin()) {
            it--;
            y = max(y, it->first);
          }
        }
      }
      a = minval.first + y;
      b = maxval.first - y;
      val = max(a, b);
      if (minval.second != -1 && maxval.second != -1) {
        val = max(val, tsup);
      }
      for (int i = 0; i < sz(g[v]); i++) {
        int u = g[v][i];
        if (minval.second != u && maxval.second != u) {
          val = max(val, ts[u]);
        }
      }
      res[v] = min(res[v], val);
    }
  }
  mppath[ts[v]]++;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == maxu) {
      bigmp.push_back(mp[u]);
      continue;
    }
    for (auto it = mp[u]->begin(); it != mp[u]->end(); it++) {
      mpup[it->first] += it->second;
    }
  }
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == maxu) {
      bigmp.pop_back();
    } else {
      for (auto it = mp[u]->begin(); it != mp[u]->end(); it++) {
        del(&mpup, it->first, it->second);
      }
    }
    dfs(u);
    if (u == maxu) {
      bigmp.push_back(mp[u]);
    } else {
      for (auto it = mp[u]->begin(); it != mp[u]->end(); it++) {
        mpup[it->first] += it->second;
      }
    }
  }
  del(&mppath, ts[v], 1);
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == maxu) {
      bigmp.pop_back();
      continue;
    }
    for (auto it = mp[u]->begin(); it != mp[u]->end(); it++) {
      del(&mpup, it->first, it->second);
    }
  }
  if (maxu != -1) {
    (*mp[v])[ts[v]]++;
    for (int i = 0; i < sz(g[v]); i++) {
      int u = g[v][i];
      if (u == maxu) {
        continue;
      }
      for (auto it = mp[u]->begin(); it != mp[u]->end(); it++) {
        (*mp[v])[it->first] += it->second;
      }
    }
  }
}

void solve() {
  dfs0(root);
  mpup.clear();
  mppath.clear();
  bigmp.clear();
  dfs(root);
  for (int i = 0; i < n; i++) {
    printf("%d\n", res[i]);
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