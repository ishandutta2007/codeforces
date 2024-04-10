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

struct Point {
  double x, y;

  Point() {}

  Point(double _x, double _y): x(_x), y(_y) {}

  Point operator+(const Point &p) const {
    return Point(x + p.x, y + p.y);
  }

  Point operator-(const Point &p) const {
    return Point(x - p.x, y - p.y);
  }

  Point operator*(double k) const {
    return Point(x * k, y * k);
  }
};

double cp(const Point &a, const Point &b) {
  return a.x * b.y - a.y * b.x;
}

double sp(const Point &a, const Point &b) {
  return a.x * b.x + a.y * b.y;
}

double len(const Point &p) {
  return sqrt(sp(p, p));
}

struct Seg {
  Point a, b;

  Seg() {}

  Seg(const Point &_a, const Point &_b): a(_a), b(_b) {
    if (a.x > b.x) {
      swap(a, b);
    }
  }

  double get(double x) const {
    if (fabs(b.x - a.x) < eps) {
      return a.y;
    }
    return a.y + (b.y - a.y) / (b.x - a.x) * (x - a.x);
  }
};

bool operator<(const Seg &s0, const Seg &s1) {
  double x = max(s0.a.x, s1.a.x);
  return s0.get(x) < s1.get(x) - eps;
}

bool onSeg(const Point &p, const Seg &s) {
  return fabs(len(p - s.a) + len(p - s.b) - len(s.b - s.a)) < eps;
}

double intersect(const Seg &s0, const Seg &s1) {
  if (fabs(cp(s0.b - s0.a, s1.b - s1.a)) < eps) {
    double x = max(s0.a.x, s1.a.x);
    if (fabs(s1.get(x) - s0.get(x)) < eps) {
      return x;
    }
    return inf;
  }
  double t = cp(s1.a - s0.a, s1.b - s1.a) / cp(s0.b - s0.a, s1.b - s1.a);
  if (t > -eps && t < 1 + eps && onSeg(s0.a + (s0.b - s0.a) * t, s1)) {
    return s0.a.x + (s0.b.x - s0.a.x) * t;
  }
  return inf;
}

const int maxn = (int)1e5 + 5;
int n, m;
int p[maxn], heavy[maxn], dep[maxn], root[maxn], pos[maxn];
int t[maxn], c[maxn], v0[maxn], v1[maxn];
set<Seg>::iterator its[maxn];
vector<int> g[maxn];
vector<Seg> allsegs[maxn];

double solve(const vector<Seg> &segs) {
  vector< pair<pair<double, int>, pair<Seg, int> > > ev;
  for (int i = 0; i < sz(segs); i++) {
    ev.push_back(make_pair(make_pair(segs[i].a.x, 0), make_pair(segs[i], i)));
    ev.push_back(make_pair(make_pair(segs[i].b.x, 1), make_pair(segs[i], i)));
  }
  sort(ev.begin(), ev.end());
  set<Seg> st;
  double ans = inf;
  for (int i = 0; i < sz(ev) && ev[i].first.first < ans - eps; i++) {
    int tt = ev[i].first.second;
    Seg seg = ev[i].second.first;
    int id = ev[i].second.second;
    if (!tt) {
      auto nxt = st.lower_bound(seg),
        prv = (nxt == st.begin()? st.end() : prev(nxt));
      if (nxt != st.end()) {
        ans = min(ans, intersect(seg, *nxt));
      }
      if (prv != st.end()) {
        ans = min(ans, intersect(seg, *prv));
      }
      its[id] = st.insert(seg).first;
    }
    else {
      auto it = its[id], nxt = next(it),
        prv = (it == st.begin()? st.end() : prev(it));
      st.erase(it);
      if (nxt != st.end() && prv != st.end()) {
        ans = min(ans, intersect(*prv, *nxt));
      }
    }
  }
  return ans;
}

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d%d", &t[i], &c[i], &v0[i], &v1[i]);
    v0[i]--;
    v1[i]--;
  }
  return true;
}

int buildhl(int v) {
  int ts = 1, maxts = 0;
  heavy[v] = -1;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p[v]) {
      continue;
    }
    p[u] = v;
    dep[u] = dep[v] + 1;
    int uts = buildhl(u);
    if (uts > maxts) {
      maxts = uts;
      heavy[v] = u;
    }
    ts += uts;
  }
  return ts;
}

int getDist(int v, int u) {
  int res = 0;
  while (root[v] != root[u]) {
    if (dep[root[v]] < dep[root[u]]) {
      swap(v, u);
    }
    res += pos[v];
    v = p[root[v]];
  }
  if (dep[v] < dep[u]) {
    swap(v, u);
  }
  res += pos[v] - pos[u];
  return res;
}

void solve() {
  p[0] = -1;
  dep[0] = 0;
  buildhl(0);
  for (int i = 0; i < n; i++) {
    if (p[i] == -1 || heavy[p[i]] != i) {
      for (int j = i, k = 1; j != -1; j = heavy[j], k++) {
        root[j] = i;
        pos[j] = k;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    allsegs[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int v = v0[i], u = v1[i], d = getDist(v, u);
    double vt = t[i], ut = t[i] + (double)d / c[i];
    while (root[v] != root[u]) {
      if (dep[root[v]] < dep[root[u]]) {
        swap(v, u);
        swap(vt, ut);
      }
      int w = p[root[v]], vw = pos[v];
      double wt = vt + (ut - vt) / d * vw;
      allsegs[root[v]].push_back(Seg(Point(wt, 0), Point(vt, pos[v])));
      v = w;
      d -= vw;
      vt = wt;
    }
    if (dep[v] < dep[u]) {
      swap(v, u);
      swap(vt, ut);
    }
    allsegs[root[v]].push_back(Seg(Point(ut, pos[u]), Point(vt, pos[v])));
  }
  double ans = inf;
  for (int i = 0; i < n; i++) {
    if (root[i] == i) {
      ans = min(ans, solve(allsegs[i]));
    }
  }
  if (ans > inf - 5) {
    printf("-1\n");
  }
  else {
    printf("%.12lf\n", ans);
  }
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