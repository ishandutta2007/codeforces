#ifdef DEBUG
//#define _GLIBCXX_DEBUG
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

const int maxn = (int) 1e6 + 5;
int lDiv[maxn];
vector<int> pr;

const long long maxx = (long long) maxn * maxn;
vector<vector<int>> vs;
map<vector<int>, int> ids;
vector<int> sid;
vector<int> small;
vector<int> a;

void gen(int pos, long long x, int mx) {
  sid.push_back(-1);
  if (x < maxn) {
    sid.back() = sz(small);
    small.push_back(sz(vs));
  }
  ids[a] = sz(vs);
  vs.push_back(a);
  long long tomul = pr[pos];
  for (int i = 1; x * tomul < maxx && i <= mx; i++, tomul *= pr[pos]) {
    a.push_back(i);
    gen(pos + 1, x * tomul, i);
    a.pop_back();
  }
}

map<vector<pair<int, int>>, int> fs;
vector<int> t;

vector<vector<int>> g;
vector<vector<int>> d;
vector<vector<int>> dt;
vector<vector<int>> ds;

void precalc() {
  for (int i = 2; i < maxn; i++) {
    if (!lDiv[i]) {
      lDiv[i] = i;
      pr.push_back(i);
    }
    for (int j = 0; j < sz(pr) && pr[j] <= lDiv[i]; j++) {
      int p = i * pr[j];
      if (p >= maxn) {
        break;
      }
      lDiv[p] = pr[j];
    }
  }
  vs.clear();
  ids.clear();
  a.clear();
  gen(0, 1, inf);
  eprintf("%d\n", sz(vs));
  g = vector<vector<int>>(sz(vs));
  for (int v = 0; v < sz(vs); v++) {
    for (int i = 0; i <= sz(vs[v]); i++) {
      for (int dd = -1; dd <= 1; dd += 2) {
        auto cur = vs[v];
        if (i == sz(vs[v])) {
          if (dd < 0) {
            continue;
          }
          cur.push_back(0);
        }
        cur[i] += dd;
        if (!cur[i]) {
          cur.erase(cur.begin() + i);
        }
        sort(cur.begin(), cur.end(), greater<int>());
        if (ids.count(cur)) {
          int u = ids[cur];
          g[v].push_back(u);
        }
      }
    }
  }
  d = vector<vector<int>>(sz(vs), vector<int>(sz(vs), inf));
  for (int s = 0; s < sz(vs); s++) {
    vector<int> q;
    q.push_back(s);
    d[s][s] = 0;
    for (int l = 0; l < sz(q); l++) {
      int v = q[l];
      for (int i = 0; i < sz(g[v]); i++) {
        int u = g[v][i];
        if (d[s][u] >= inf) {
          d[s][u] = d[s][v] + 1;
          q.push_back(u);
        }
      }
    }
  }
  fs.clear();
  t.resize(sz(vs));
  for (int i = 0; i < sz(vs); i++) {
    vector<pair<int, int>> f;
    for (int j = 0; j < sz(vs[i]); j++) {
      int x = vs[i][j] + 1;
      while (x > 1) {
        f.push_back(make_pair(lDiv[x], 1));
        x /= lDiv[x];
      }
    }
    sort(f.begin(), f.end());
    int k = 0;
    for (int i = 0; i < sz(f); i++) {
      if (!k || f[i].first != f[k - 1].first) {
        f[k] = f[i];
        k++;
      } else {
        f[k - 1].second += f[i].second;
      }
    }
    f.resize(k);
    if (!fs.count(f)) {
      int cnt = sz(fs);
      fs[f] = cnt;
    }
    t[i] = fs[f];
  }
  eprintf("%d\n", sz(fs));
  dt = vector<vector<int>>(sz(small), vector<int>(sz(fs), inf));
  for (int i = 0; i < sz(small); i++) {
    int v = small[i];
    for (int u = 0; u < sz(vs); u++) {
      dt[i][t[u]] = min(dt[i][t[u]], d[v][u]);
    }
  }
  ds = vector<vector<int>>(sz(small), vector<int>(sz(small), inf));
  for (int i = 0; i < sz(small); i++) {
    for (int j = 0; j < sz(small); j++) {
      for (int k = 0; k < sz(fs); k++) {
        ds[i][j] = min(ds[i][j], dt[i][k] + dt[j][k]);
      }
    }
  }
}

int x, y;

int read() {
  if (scanf("%d%d", &x, &y) < 2) {
    return false;
  }
  return true;
}

int getId(int x) {
  vector<int> f;
  while (x > 1) {
    int p = lDiv[x];
    int cur = 0;
    while (!(x % p)) {
      x /= p;
      cur++;
    }
    f.push_back(cur);
  }
  sort(f.begin(), f.end(), greater<int>());
  assert(ids.count(f));
  int v = ids[f];
  assert(sid[v] != -1);
  return sid[v];
}

void solve() {
  int v = getId(x), u = getId(y);
  printf("%d\n", ds[v][u]);
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