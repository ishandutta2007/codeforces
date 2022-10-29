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
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define FOR(i, a, b) for (int i(a), _b(b); i < _b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define FORE(e, v) for (int e = head[v]; e >= 0; e = E[e].next)
#define UN(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define CL(a, v) memset(a, v, sizeof a)
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1000000000;
const ll INF_LL = 1000000000000000000LL;
const double pi = 2 * acos(0.0);

template<class T> void smin(T& a, T b) { if (a > b) a = b; }
template<class T> void smax(T& a, T b) { if (a < b) a = b; }
template<class T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
template<class T> T sqr(T a) { return a * a; }

template<class T1, class T2>
ostream& operator << (ostream& out, const pair<T1, T2>& p) {
  out << p.X << ',' << p.Y;
  return out;
}
template<class T> void outp(const vector<T>& v) {
  cout << sz(v) << ":";
  REP(i, sz(v)) cout << " " << v[i];
  cout << endl;
}
template<class T> void outp(T* v, int n) {
  cout << n << ":";
  REP(i, n) cout << " " << *v++;
  cout << endl;
}

typedef ll Tc;  // coordinate type
const Tc inf = INF_LL;
template<class T> int cmp(T x, T y) { return x == y ? 0 : x < y ? -1 : 1; }

struct P {
  Tc x, y;
  P() : x(0), y(0) {}
  P(Tc x, Tc y) : x(x), y(y) {}

  bool inp() { return scanf("%I64d%I64d", &x, &y) == 2; }
  void outp() const { printf("%I64d %I64d\n", x, y); }
};

int cmp(P a, P b) { int cx = cmp(a.x, b.x); return cx ? cx : cmp(a.y, b.y); }
#define COMP(v) bool operator v (P a, P b) { return cmp(a, b) v 0; }
COMP(==) COMP(!=) COMP(<) COMP(>) COMP(<=) COMP(>=)
#undef COMP

P operator - (P a) { return P(-a.x, -a.y); }
P operator + (P a, P b) { return P(a.x + b.x, a.y + b.y); }
P operator - (P a, P b) { return P(a.x - b.x, a.y - b.y); }
P operator * (Tc c, P a) { return P(c * a.x, c * a.y); }
P operator * (P a, Tc c) { return P(a.x * c, a.y * c); }
P operator / (P a, Tc c) { return P(a.x / c, a.y / c); }

Tc operator * (P a, P b) { return a.x * b.x + a.y * b.y; }
Tc operator ^ (P a, P b) { return a.x * b.y - a.y * b.x; }
Tc abs(P a) { return a * a; }
int ccw(P a, P b) { return cmp(b ^ a, (Tc)0); }  // -1 if b<-a counter-clockwise
int ccw(P o, P a, P b) { return ccw(a - o, b - o); }

const int h = 100011;
int n, m, k;
P t[h];
int o[h], v[h];

template<int N, int B, class T>  // 2^B > N
struct LCA {
  int n;
  typedef pair<int, T> Edge;
  vector<Edge> E[N];
  T inf;

  void init(int nn, T tinf) {
    REP(i, n) vector<Edge>().swap(E[i]);
    n = nn;
    inf = tinf;
  }

  void add(int a, int b, T w) {
    E[a].pb(Edge(b, w));
    E[b].pb(Edge(a, w));
  }

  int lev[N];
  int p[N][B];
  T f[N][B];

  void dfs(int v) {
    REP(i, sz(E[v])) {
      int u = E[v][i].X;
      if (lev[u] != -1) continue;
      lev[u] = lev[v] + 1;
      f[u][0] = E[v][i].Y;
      int w = p[u][0] = v;
      REP(j, B-1) {
        f[u][j+1] = min(f[u][j], f[w][j]);
        p[u][j+1] = w = p[w][j];
        if (w == -1) break;
      }
      dfs(u);
    }
  }

  void build(int root = 0) {
    REP(i, n) CL(p[i], -1);
    fill_n(lev, n, -1);
    lev[root] = 0;
    dfs(root);
  }

  pair<int, T> lca(int a, int b) {
    T res = inf;
    if (lev[a] < lev[b]) swap(a, b);
    FORD(j, B-1, 0) {
      int v = p[a][j];
      if (v != -1 && lev[v] >= lev[b]) smin(res, f[a][j]), a = v;
    }
    if (a == b) return make_pair(a, res);
    FORD(j, B-1, 0) if (p[a][j] != p[b][j]) {
      smin(res, f[a][j]); a = p[a][j];
      smin(res, f[b][j]); b = p[b][j];
    }
    return make_pair(p[a][0], min(min(f[a][0], f[b][0]), res));
  }
};

LCA<h, 17, int> lca;

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  lca.init(n, INF);
  REP(i, n) t[i].inp();
  if (n > 1) {
    k = 1;
    o[0] = n-1;
    v[0] = n-2;
    lca.add(n-2, n-1, 0);
    FORD(i, n-3, 0) {
      int l = -1, r = k;
      while (l + 1 < r) {
        int m = (l + r) / 2;
        if (ccw(t[o[m]], t[v[m]], t[i]) <= 0) l = m;
        else r = m;
      }
//      printf("%d:\n", i);
//      REP(j, k) printf("%d %d; ", v[j], o[j]); printf("\n");
//      printf("%d\n", l);
      int p = l == -1 ? n-1 : v[l];
      lca.add(i, p, 0);
      ++l;
      o[l] = p;
      v[l] = i;
      k = l + 1;
    }
  }
  lca.build(n-1);

  scanf("%d", &m);
  REP(i, m) {
    int a, b;
    scanf("%d %d\n", &a, &b);
    printf("%d ", lca.lca(a-1, b-1).X+1);
  }
  printf("\n");

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}