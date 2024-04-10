#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define FOR(i, a, b) for (int i(a), _b(b); i < _b; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define CL(a, v) memset(a, v, sizeof a)
#define eb emplace_back
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1e9;
const ll INF_LL = 4e18;
const double pi = acos(-1.0);

template<class T> T& smin(T& a, const T& b) { if (a > b) a = b; return a; }
template<class T> T& smax(T& a, const T& b) { if (a < b) a = b; return a; }
template<class T> T sqr(const T& a) { return a * a; }

template<typename Iterator>
void print(const char* fmt, Iterator begin, Iterator end,
    const char* separator = " ", const char* closing = "\n") {
  for (Iterator it = begin; it != end; printf(fmt, *it),
      printf("%s", ++it == end ? closing : separator));
}

template<class T, bool commutative = true>
class SegmentTree {
  int n;
  vector<T> t;

 public:
  SegmentTree(int n_ = 0) { init(n_); }
  void init(int n_) { n = n_; vector<T>(2*n).swap(t); }

  T& operator [] (int p) { return t[p + n]; }
  const T& operator [] (int p) const { return t[p + n]; }

  void build() {
    for (int i = n - 1; i; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
  }

  T query(int l, int r) const {  // [l, r)
    T resl, resr;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
      if (commutative) {
        if (l&1) resl.add(t[l++]);
        if (r&1) resr.add(t[--r]);
      } else {
        if (l&1) resl = combine(resl, t[l++]);
        if (r&1) resr = combine(t[--r], resr);
      }
    return combine(resl, resr);
  }
};


template<class A>
struct Amin {
  static A* a;
  int v;
  Amin(int v = -1) : v(v) {}
  operator int() const { return v; }
  void add(const Amin& y) {
    if (v == -1 || a[y] < a[v]) v = y;
  }
  friend Amin combine(const Amin& x, const Amin& y) {
    if (x == -1) return y;
    if (y == -1) return x;
    return a[y] < a[x] ? y : x;
  }
};
template<class A> A* Amin<A>::a;

template<int N>
struct LCA {
  int n;
  vi E[N];

  LCA(int n_ = 0) { init(n_); }
  void init(int n_) {
    REP(i, n) vi().swap(E[i]);
    n = n_;
  }

  void add(int a, int b) {
    if (a == b) return;
    E[a].pb(b);
    E[b].pb(a);
  }

  int k, r;
  int root[N], pos[N], lev[N];
  SegmentTree<Amin<int>, true> tree;

  void dfs(int v) {
    root[v] = r;
    pos[v] = k;
    tree[k++] = v;
    for (int u : E[v]) if (pos[u] == -1) {
      lev[u] = lev[v] + 1;
      dfs(u);
      tree[k++] = v;
    }
  }

  void build() {
    k = 0;
    fill_n(pos, n, -1);
    tree.init(2*n-1);
    REP(i, n) if (pos[i] == -1) lev[r = i] = 0, dfs(r);
    Amin<int>::a = lev;
    tree.build();
  }

  int lca(int a, int b) {
    if (root[a] != root[b]) return -1;
    if (pos[a] > pos[b]) swap(a, b);
    Amin<int>::a = lev;
    return tree.query(pos[a], pos[b] + 1);
  }
};


template<int N>
struct Comp2 {
  int n;
  vi E[N];

  Comp2(int n_ = 0) : n(0) { init(n_); }
  void init(int n_) {
    stack.reserve(n_);
    REP(i, n) vi().swap(E[i]);
    n = n_;
  }

  void add(int a, int b) {
    E[a].pb(b);
    E[b].pb(a);
  }

  int low[N], cur;
  int c2[N], k2;
  vi stack;

  void dfs(int v, int p) {
    bool root = true;
    low[v] = ++cur;
    stack.pb(v);
    bool sp = false;
    for (int u : E[v]) if (sp || u != p) {
      if (!low[u]) dfs(u, v);
      if (low[v] > low[u]) low[v] = low[u], root = false;
    } else sp = true;

    if (root) {
      int i = sz(stack), u = -1;
      while (u != v) {
        u = stack[--i];
        low[u] = n + 1;
        c2[u] = k2;
      };
      ++k2;
      stack.resize(i);
    }
  }

  void calc() {
    cur = k2 = 0;
    fill_n(low, n, 0);
    REP(i, n) if (!low[i]) dfs(i, -1);
  }
};

const int N = 2e5+5;
int n, m, q;
Comp2<N> g;
LCA<N> cg;
int f[N][2];

bool dfs(int v, int p) {
  for (int u : cg.E[v]) if (u != p) {
    if (!dfs(u, v)) return false;
    REP(i, 2) f[v][i] += f[u][i];
  }
  return f[v][0] == 0 || f[v][1] == 0;
}

bool solve() {
  g.calc();
  int k = g.k2;
  cg.init(k);
  REP(i, n) for (int j : g.E[i]) if (i < j) cg.add(g.c2[i], g.c2[j]);
  cg.build();
  REP(i, q) {
    int s, t;
    scanf("%d%d", &s, &t);
    s = g.c2[s-1];
    t = g.c2[t-1];
    int a = cg.lca(s, t);
    if (a == -1) return false;
    ++f[s][0];
    ++f[t][1];
    --f[a][0];
    --f[a][1];
  }
  REP(i, k) if (cg.root[i] == i && !dfs(i, -1)) return false;
  return true;
}

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d%d", &n, &m, &q);

  g.init(n);
  REP(i, m) {
    int u, v;
    scanf("%d%d", &u, &v);
    g.add(u-1, v-1);
  }

  printf("%s\n", solve() ? "Yes" : "No");

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}