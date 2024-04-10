#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <complex>
#include <numeric>
#include <bitset>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define FOR(i, a, b) for (int i(a), _b(b); i < _b; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define FORE(e, v) for (int e = head[v]; e >= 0; e = E[e].next)
#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define CL(a, v) memset(a, v, sizeof a)
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1000000000;
const ll INF_LL = 1000000000000000000LL;
const double pi = acos(-1.0);

template<class T> T& smin(T& a, const T& b) { if (a > b) a = b; return a; }
template<class T> T& smax(T& a, const T& b) { if (a < b) a = b; return a; }
template<class T> T gcd(T a, T b) {
  if (a < 0) a = -a; if (b < 0) b = -b;
  while (a && b) { if (a >= b) a %= b; else b %= a; } return a + b; }
template<class T> T sqr(const T& a) { return a * a; }

template<typename Iterator> void print(const char* fmt,
    Iterator begin, Iterator end, const char* separator = " ") {
  for (Iterator it = begin; it != end; ++it) {
    if (it != begin) printf("%s", separator);
    printf(fmt, *it);
  }
  printf("\n");
}

template<class T>
class SegmentTree {
 public:
  void init(int n_, const T& v = T()) { n = n_; t = vector<T>(2*n, v); }

  T& operator [] (int p) { return t[p + n]; }
  const T& operator [] (int p) const { return t[p + n]; }

  void push() {
    FOR(i, 1, n) {
      t[i<<1].inc(t[i]);
      t[i<<1|1].inc(t[i]);
      t[i] = T();
    }
  }

  void inc(int l, int r, const T& delta) {  // [l, r)
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) t[l++].inc(delta);
      if (r&1) t[--r].inc(delta);
    }
  }

  T query(int p) const {
    T res;
    for (p += n; p > 0; p >>= 1) res.inc(t[p]);
    return res;
  }

 private:
  int n;
  vector<T> t;
};

struct Vmin {
  int v;
  Vmin(int v = INF) : v(v) {}
  void inc(const Vmin& b) { smin(v, b.v); }
  friend Vmin sum(const Vmin& a, const Vmin& b) { return min(a.v, b.v); }
};

struct Vmax {
  int v;
  Vmax(int v = -INF) : v(v) {}
  void inc(const Vmax& b) { smax(v, b.v); }
  friend Vmax sum(const Vmax& a, const Vmax& b) { return max(a.v, b.v); }
};


const int N = 200011;
int t, T;
int n, m, k;
pii b[N];
vi e[N];

map<int, int> mg;
int g[N];

pii o[N];

void upd(pii& a, const pii& b) {
  smax(a.X, b.X);
  smin(a.Y, b.Y);
}

vector<pii> q;

int p[N], r[N];
pii f[N];

SegmentTree<Vmin> tmin;
SegmentTree<Vmax> tmax;

void updt(int l, int r, pii v) {
  tmin.inc(l, r, v.Y);
  tmax.inc(l, r, v.X);
}

void impsy() {
  printf("IMPOSSIBLE\n");
  exit(0);
}

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &t, &T);
  scanf("%d%d", &n, &m);
  REP(i, n) {
    scanf("%d%d", &b[i].X, &b[i].Y);
    if (b[i].X > T) impsy();
    smin(b[i].Y, T);
  }
  REP(i, n) g[i] = b[i].X;
  REP(i, n) g[n+i] = b[i].Y;
  g[2*n] = 0;
  sort(g, g+2*n+1);
  k = unique(g, g+2*n+1) - g;
  REP(i, k) mg[g[i]] = i;
  REP(i, k) o[i] = pii(0, T);

  REP(i, m) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a;
    --b;
    e[a].pb(b);
    e[b].pb(a);
  }

  q.clear();
  REP(i, n) if (e[i].empty()) q.pb(pii(b[i].Y, i));
  sort(all(q));
  int u = 0;
  pii s(0, T);
  REP(i, k) {
    upd(o[i], s);
    while (u < sz(q) && q[u].X == g[i]) upd(s, b[q[u].Y]), ++u;
  }

  q.clear();
  REP(i, n) if (e[i].empty()) q.pb(pii(b[i].X, i));
  sort(all(q));
  u = sz(q) - 1;
  s = pii(0, T);
  FORD(i, k-1, 0) {
    upd(o[i], s);
    while (u >= 0 && q[u].X == g[i]) upd(s, b[q[u].Y]), --u;
  }

  tmin.init(k, T);
  tmax.init(k, 0);
  fill(p, p+n, -1);
  int kp = 0;
  REP(i, n) if (!e[i].empty() && p[i] == -1) {
    p[i] = kp;
    f[kp] = f[kp^1] = pii(0, T);
    vi q(1, i);
    for (int qa = 0; qa < sz(q); ++qa) {
      int i = q[qa];
      upd(f[p[i]], b[i]);
      REP(u, sz(e[i])) {
        int j = e[i][u];
        if (p[j] == -1) {
          p[j] = p[i] ^ 1;
          q.pb(j);
        } else if (p[j] == p[i]) impsy();
      }
    }
    pii gf[2];
    FOR(a, kp, kp+2) if (f[a].X > f[a].Y) impsy();
    REP(a, 2) gf[a] = pii(mg[f[kp^a].X], mg[f[kp^a].Y]);

    tmin.inc(0, min(gf[0].X, gf[1].X), -1);
    tmin.inc(max(gf[0].Y, gf[1].Y)+1, k, -1);
    if (f[kp].X <= f[kp^1].Y && f[kp^1].X <= f[kp].Y) {
      if (f[kp].X <= f[kp^1].X) updt(gf[0].X, gf[1].X, f[kp^1]);
      else updt(gf[1].X, gf[0].X, f[kp]);
      if (f[kp].Y <= f[kp^1].Y) updt(gf[0].Y, gf[1].Y, f[kp]);
      else updt(gf[1].Y, gf[0].Y, f[kp^1]);
      updt(max(gf[0].X, gf[1].X), min(gf[0].Y, gf[1].Y)+1,
          pii(min(f[kp].X, f[kp^1].X), max(f[kp].Y, f[kp^1].Y)));
    } else {
      REP(a, 2) updt(gf[a].X, gf[a].Y+1, f[kp^a^1]);
      tmin.inc(gf[0].Y+1, gf[1].X, -1);
      tmin.inc(gf[1].Y+1, gf[0].X, -1);
    }

    kp += 2;
  }

  tmin.push();
  tmax.push();

  REP(i, k) {
    pii s = o[i];
    upd(s, pii(tmax[i].v, tmin[i].v));
//    printf("%d: (%d,%d)\n", g[i], s.X, s.Y);
    if (s.X <= s.Y && t <= g[i] + s.Y && g[i] + s.X <= T) {
      int g1 = g[i], g2 = s.X;
      if (g1 + g2 < t) g2 = t - g1;
      printf("POSSIBLE\n");
      printf("%d %d\n", g1, g2);
      for (int u = 0; u < kp; u += 2) {
        if (f[u].X <= g1 && g1 <= f[u].Y && f[u^1].X <= g2 && g2 <= f[u^1].Y)
          r[u] = 0;
        else r[u] = 1;
        r[u^1] = r[u] ^ 1;
      }

      REP(j, n) if (e[j].empty()) {
        printf("%d", b[j].X <= g1 && g1 <= b[j].Y ? 1 : 2);
      } else {
        printf("%d", r[p[j]]+1);
      }
      printf("\n");
      return 0;
    }
  }

  impsy();

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}