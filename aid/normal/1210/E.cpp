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

const int maxn = (int) 2e5 + 5;
int n, k;
vector<int> ps[maxn];

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    ps[i].resize(k);
    for (int j = 0; j < k; j++) {
      scanf("%d", &ps[i][j]);
      ps[i][j]--;
    }
  }
  return true;
}

map<vector<int>, int> ids;
const int maxp = 125;
int pmul[maxp][maxp];

struct Cmp {
  bool operator () (const bitset<maxp> &a, const bitset<maxp> &b) const {
    for (int i = 0; i < maxp; i++) {
      if (a[i] != b[i]) {
        return a[i] < b[i];
      }
    }
    return false;
  }
};

map<bitset<maxp>, int, Cmp> gids;
const int maxg = 205;
int cnt[maxg];
vector<int> g[maxg];

vector<int> getProd(const vector<int> &a, const vector<int> &b) {
  vector<int> p(k);
  for (int i = 0; i < k; i++) {
    p[i] = b[a[i]];
  }
  return p;
}

void getClosure(bitset<maxp> &bs) {
  while (true) {
    bool found = false;
    for (int i = 0; i < sz(ids); i++) {
      if (!bs[i]) {
        continue;
      }
      for (int j = 0; j < sz(ids); j++) {
        if (!bs[j]) {
          continue;
        }
        int x = pmul[i][j];
        if (!bs[x]) {
          bs[x] = true;
          found = true;
        }
      }
    }
    if (!found) {
      break;
    }
  }
}

int a[maxn];
int lst[maxp];
pair<int, int> tosort[maxp];

void solve() {
  {
    ids.clear();
    gids.clear();
    vector<int> p(k);
    for (int i = 0; i < k; i++) {
      p[i] = i;
    }
    while (true) {
      int id = sz(ids);
      ids[p] = id;
      if (!next_permutation(p.begin(), p.end())) {
        break;
      }
    }
    eprintf("%d\n", sz(ids));
    for (auto it0 = ids.begin(); it0 != ids.end(); it0++) {
      for (auto it1 = ids.begin(); it1 != ids.end(); it1++) {
        auto p = getProd(it0->first, it1->first);
        pmul[it0->second][it1->second] = ids[p];
      }
    }
    bitset<maxp> bs0;
    bs0[0] = true;
    gids[bs0] = 0;
    vector<bitset<maxp>> q;
    q.push_back(bs0);
    for (int l = 0; l < sz(q); l++) {
      auto bs = q[l];
      for (auto it = ids.begin(); it != ids.end(); it++) {
        int x = it->second;
        if (bs[x]) {
          continue;
        }
        auto nbs = bs;
        nbs[x] = true;
        getClosure(nbs);
        if (gids.count(nbs)) {
          continue;
        }
        int id = sz(gids);
        gids[nbs] = id;
        q.push_back(nbs);
      }
    }
    eprintf("%d\n", sz(gids));
    for (int i = 0; i < sz(gids); i++) {
      g[i].clear();
      g[i].resize(sz(ids), -1);
    }
    for (auto iter = gids.begin(); iter != gids.end(); iter++) {
      auto bs = iter->first;
      int v = iter->second;
      cnt[v] = bs.count();
      for (auto it = ids.begin(); it != ids.end(); it++) {
        int x = it->second;
        if (bs[x]) {
          g[v][x] = v;
          continue;
        }
        auto nbs = bs;
        nbs[x] = true;
        getClosure(nbs);
        int u = gids[nbs];
        g[v][x] = u;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    a[i] = ids[ps[i]];
  }
  for (int i = 0; i < sz(ids); i++) {
    lst[i] = n;
    tosort[i] = make_pair(lst[i], i);
  }
  long long res = 0;
  for (int i = n - 1; i >= 0; i--) {
    lst[a[i]] = i;
    int pos = 0;
    while (tosort[pos].second != a[i]) {
      pos++;
    }
    tosort[pos].first = lst[a[i]];
    while (pos && tosort[pos - 1] > tosort[pos]) {
      swap(tosort[pos - 1], tosort[pos]);
      pos--;
    }
    while (pos + 1 < sz(ids) && tosort[pos + 1] < tosort[pos]) {
      swap(tosort[pos + 1], tosort[pos]);
      pos++;
    }
    int v = 0;
    for (int j = 0; j < sz(ids); j++) {
      int pid = tosort[j].second;
      v = g[v][pid];
      int len = (j + 1 < sz(ids) ? tosort[j + 1].first : n) - tosort[j].first;
      res += len * cnt[v];
    }
  }
  printf("%lld\n", res);
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