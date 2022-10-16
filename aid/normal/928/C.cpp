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

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = 1005;
int n;
map<pair<string, int>, int> ids;
string ns[maxn];
int vr[maxn];
vector<int> g[maxn];
map<string, vector<int>> vers;
char tmp[100];

int getId(const string &name, int ver) {
  if (!ids.count(make_pair(name, ver))) {
    int id = sz(ids);
    ids[make_pair(name, ver)] = id;
    ns[id] = name;
    vr[id] = ver;
  }
  return ids[make_pair(name, ver)];
}

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  ids.clear();
  vers.clear();
  for (int i = 0; i < n; i++) {
    string name;
    int ver;
    scanf("%s%d", tmp, &ver);
    name = tmp;
    int id = getId(name, ver);
    vers[name].push_back(ver);
    int k;
    scanf("%d", &k);
    g[id].clear();
    for (int j = 0; j < k; j++) {
      string name;
      int ver;
      scanf("%s%d", tmp, &ver);
      name = tmp;
      int pid = getId(name, ver);
      g[id].push_back(pid);
    }
  }
  return true;
}

int used[maxn];
vector<pair<int, int>> vs[maxn];
set<string> taken;

void solve() {
  for (int i = 0; i < n; i++) {
    used[i] = false;
    vs[i].clear();
  }
  taken.clear();
  vs[0].push_back(make_pair(vr[0], 0));
  used[0] = true;
  vector<pair<string, int>> ans;
  for (int d = 0; d < n; d++) {
    sort(vs[d].begin(), vs[d].end(), greater<pair<int, int>>());
    for (int i = 0; i < sz(vs[d]); i++) {
      int id = vs[d][i].second;
      if (taken.count(ns[id])) {
        continue;
      }
      if (id) {
        ans.push_back(make_pair(ns[id], vr[id]));
      }
      taken.insert(ns[id]);
      for (int j = 0; j < sz(g[id]); j++) {
        int u = g[id][j];
        if (!used[u]) {
          vs[d + 1].push_back(make_pair(vr[u], u));
          used[u] = true;
        }
      }
    }
  }
  sort(ans.begin(), ans.end());
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); i++) {
    printf("%s %d\n", ans[i].first.c_str(), ans[i].second);
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