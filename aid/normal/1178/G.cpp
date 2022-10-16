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

const int maxn = (int) 2e5 + 5;
int n, q;
vector<int> g[maxn];
int as[maxn], bs[maxn];

bool read() {
  if (scanf("%d%d", &n, &q) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 1; i < n; i++) {
    int p;
    scanf("%d", &p);
    p--;
    g[p].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &as[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &bs[i]);
  }
  return true;
}

int tl[maxn], tr[maxn];
vector<int> path;

void dfs(int v) {
  tl[v] = sz(path);
  path.push_back(v);
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    as[u] += as[v];
    bs[u] += bs[v];
    dfs(u);
  }
  tr[v] = sz(path);
}

struct line {
  long long a, b;

  line(): a(0), b(0) {}

  line(long long _a, long long _b): a(_a), b(_b) {}

  bool operator < (const line &l) const {
    if (b != l.b) {
      return b < l.b;
    }
    return a < l.a;
  }

  long long eval(long long x) {
    return a + b * x;
  }
};

bool bad(const line &l0, const line &l1, const line &l2) {
  return (ld) (l0.a - l1.a) / (l1.b - l0.b) >= (ld) (l1.a - l2.a) / (l2.b - l1.b);
}

const int K = 200, maxb = (maxn + K - 1) / K;
vector<pair<line, int>> allls[maxb];
vector<line> ls[maxb];
long long x[maxb];
int pos[maxb];

void buildBlock(int b) {
  ls[b].clear();
  x[b] = 0;
  pos[b] = 0;
  int k = 0;
  for (int i = 0; i < sz(allls[b]); i++) {
    auto cur = allls[b][i].first;
    {
      bool bad = false;
      while (k && cur.b == ls[b][k - 1].b) {
        if (cur.a <= ls[b][k - 1].a) {
          bad = true;
          break;
        }
        ls[b].pop_back();
        k--;
      }
      if (bad) {
        continue;
      }
    }
    while (k >= 2 && bad(ls[b][k - 2], ls[b][k - 1], cur)) {
      ls[b].pop_back();
      k--;
    }
    ls[b].push_back(cur);
    k++;
  }
}

void updateBlock(int b, int l, int r, int y) {
  for (int i = 0; i < sz(allls[b]); i++) {
    auto &cur = allls[b][i].first;
    int id = allls[b][i].second;
    cur.a += x[b] * cur.b;
    if (l <= id && id < r) {
      cur.a += y * cur.b;
    }
  }
  buildBlock(b);
}

void update(int l, int r, int y) {
  for (int b = 0; b * K < n; b++) {
    int bl = b * K, br = min(bl + K, n);
    if (l <= bl && br <= r) {
      x[b] += y;
      continue;
    }
    int ll = max(l, bl), rr = min(r, br);
    if (ll < rr) {
      updateBlock(b, ll, rr, y);
    }
  }
}

long long get1(int b) {
  while (pos[b] + 1 < sz(ls[b]) && ls[b][pos[b] + 1].eval(x[b]) > ls[b][pos[b]].eval(x[b])) {
    pos[b]++;
  }
  return ls[b][pos[b]].eval(x[b]);
}

long long getBlock(int b, int l, int r) {
  long long res = 0;
  bool bb = true;
  for (int i = 0; i < sz(allls[b]); i++) {
    auto curl = allls[b][i].first;
    int id = allls[b][i].second;
    if (l <= id && id < r) {
      long long cur = curl.eval(x[b]);
      if (bb) {
        res = cur;
        bb = false;
      } else {
        res = max(res, cur);
      }
    }
  }
  return res;
}

long long get(int l, int r) {
  long long res = 0;
  bool bb = true;
  for (int b = 0; b * K < n; b++) {
    int bl = b * K, br = min(bl + K, n);
    if (l <= bl && br <= r) {
      long long cur = get1(b);
      if (bb) {
        res = cur;
        bb = false;
      } else {
        res = max(res, cur);
      }
      continue;
    }
    int ll = max(l, bl), rr = min(r, br);
    if (ll < rr) {
      long long cur = getBlock(b, ll, rr);
      if (bb) {
        res = cur;
        bb = false;
      } else {
        res = max(res, cur);
      }
    }
  }
  return res;
}

void solve() {
  path.clear();
  dfs(0);
  for (int i = 0; i < n; i++) {
    bs[i] = abs(bs[i]);
  }
  for (int b = 0; b * K < n; b++) {
    int bl = b * K, br = min(bl + K, n);
    allls[b].clear();
    for (int i = bl; i < br; i++) {
      int id = path[i];
      allls[b].push_back(make_pair(line((long long) as[id] * bs[id], (long long) bs[id]), i));
      allls[b].push_back(make_pair(line((long long) -as[id] * bs[id], (long long) -bs[id]), i));
    }
    sort(allls[b].begin(), allls[b].end());
    buildBlock(b);
  }
  for (int qq = 0; qq < q; qq++) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int v, y;
      scanf("%d%d", &v, &y);
      v--;
      update(tl[v], tr[v], y);
    } else {
      int v;
      scanf("%d", &v);
      v--;
      printf("%lld\n", get(tl[v], tr[v]));
    }
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