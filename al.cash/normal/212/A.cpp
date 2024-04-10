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
#define REP(i, n) FOR (i, 0, n)
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

template<class T> void outp(const vector<T>& v) {
  REP(i, sz(v)) cout << v[i] << (i + 1 == sz(v) ? '\n' : ' ');
}
template<class T> void outp(T* v, int n) {
  REP(i, n) cout << *v++ << (i + 1 == n ? '\n' : ' ');
}

const int h = 200;

int n, m, k, t;
int deg[2*h];

template<int N, int M, class T>
struct Flow {
  struct Edge {
    int b, next;
    T cap, f;
    int phase;
    Edge(int b = -1, T cap = 0, int next = -1)
        : b(b), next(next), cap(cap), f(0), phase(0) {}
    T rem() { return phase == 0 ? cap - f : 0; }
  } E[2*M];

  int n, m;
  int head[N], d[N], q[N];

  T inf, eps;
  bool zero(T x) { return x <= eps && -x <= eps; }

  void init(int nn, T tinf, T teps = 0) {
    n = nn; m = 0;
    CL(head, -1);
    inf = tinf; eps = teps;
  }

  void add(int a, int b, T cap) {
    if (m < 2*k) ++deg[a], ++deg[b];
    E[m] = Edge(b, cap, head[a]); head[a] = m++;
    E[m] = Edge(a, 0, head[b]); head[b] = m++;
  }

  bool bfs(int s, int t) {
    CL(d, -1);
    q[0] = s; d[s] = 1;
    for (int qa = 0, qb = 1; qa < qb; ++qa) {
      int u = q[qa], v;
      FORE(e, u) if (!zero(E[e^1].rem()) && d[v = E[e].b] == -1) {
        d[q[qb++] = v] = d[u] + 1;
        if (v == t) return true;
      }
    }
    return false;
  }

  void inc(int e, int w) {
    E[e].f += w;
    E[e^1].f -= w;
  }

  T dfs(int s, int t, T flow) {
    if (s == t) return flow;
    T res = 0, w;
    for (int& e = q[s]; e >= 0; e = E[e].next)
      if (!zero(E[e].rem()) && d[E[e].b] == d[s] - 1)
        if (!zero(w = dfs(E[e].b, t, min(E[e].rem(), flow)))) {
          res += w;
          flow -= w;
          inc(e, w);
          if (zero(flow)) break;
        }
    return res;
  }

  bool fix_flow(int u) {
    if (d[u] == 0) return false;
    d[u] = 0;
    int eu = 2 * (k + u);
    if (E[eu].f > deg[u] / t) {
      inc(eu, -1);
      return true;
    }
    int v, w;
    FORE(e, u) {
      v = E[e].b;
      if (E[e].phase == 0 && !E[e].f && d[v] == -1) {
        d[v] = 0;
        FORE(r, v) if (E[r].phase == 0 && E[r].f && fix_flow(E[r].b)) {
          w = E[r].f > 0 ? -1 : 1;
          inc(r, w);
          inc(e, w);
          return true;
        }
      }
    }
    return false;
  }

  T max_flow(int s, int t) {
    REP(i, m) E[i].f = 0;
    T res = 0;
    while (bfs(t, s)) {
      REP(i, n) q[i] = head[i];
      res += dfs(s, t, inf);
    }
    REP(i, n-2) while (E[2*(k+i)].f < deg[i]/::t) {
      CL(d, -1);
      d[n-2] = d[n-1] = 0;
      fix_flow(i);
      inc(2*(k+i), 1);
    }
    return res;
  }
};

Flow<2*h+2, 5000+2*h, int> g;

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d%d%d", &n, &m, &k, &t);
  int o = n + m;
  g.init(o + 2, INF);
  int a, b;
  REP(j, k) {
    scanf("%d%d", &a, &b);
    --a;
    --b;
    g.add(a, n + b, 1);
  }
  int f = 0;
  REP(i, o) f += deg[i] % t != 0;
  printf("%d\n", f);
  REP(i, n) g.add(o, i, 0);
  FOR(i, n, o) g.add(i, o + 1, 0);
  for (; t; --t) {
    REP(i, o) g.E[2*(k+i)].cap = (deg[i] + t - 1) / t;
    g.max_flow(o, o + 1);
    REP(j, 2 * k) if (g.E[j].f) {
      g.E[j].phase = t;
      --deg[g.E[j].b];
    }
  }
  REP(j, k) printf("%d ", g.E[2*j].phase);
  printf("\n");

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
}