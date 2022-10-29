/******************************************************************************
 *          How can I feel abandoned even when the world surrounds me         *
 *       How can I bite the hand that feeds the strangers all around me       *
 *             How can I know so many never really knowing anyone             *
 *               If I seem superhuman I have been misunderstood               *
 ******************************************************************************/

#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <memory>
#include <random>
#include <cmath>
#include <ctime>
#include <functional>
#include <algorithm>
#include <complex>
#include <numeric>
#include <limits>
#include <bitset>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <array>
#include <list>
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) static_cast<int>((a).size())
#define FOR(i, a, b) for (int i(a), b_(b); i < b_; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a), b_(b); i >= b_; --i)
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

const int INF = static_cast<int>(1e9);
const long long INF_LL = static_cast<long long>(4e18);
const double pi = acos(-1.0);

template <class T> T& smin(T& x, const T& y) { if (x > y) x = y; return x; }
template <class T> T& smax(T& x, const T& y) { if (x < y) x = y; return x; }
template <class T> T sqr(const T& x) { return x * x; }

template <class T> T gcd(T a, T b) {
  for (a = abs(a), b = abs(b); a && b; a >= b ? a %= b : b %= a);
  return a + b;
}

template <typename Iterator>
void print(const char* fmt, Iterator begin, Iterator end,
           const char* delimiter = " ", const char* closing = "\n") {
  for (; begin != end; ++begin != end ? printf("%s", delimiter) : 0)
    printf(fmt, *begin);
  printf("%s", closing);
}

template <class T, bool COMMUTATIVE = true>
class SegmentTree {
  int n;
  vector<T> tree;

public:
  SegmentTree(int newn = 0) { init(newn); }
  void init(int newn) { n = newn; vector<T>(2*n).swap(tree); }

  int size() const { return n; }
  T& operator [] (int i) { return tree[i + n]; }
  const T& operator [] (int i) const { return tree[i + n]; }

  void build() {
    for (int i = n; --i; ) tree[i] = combine(tree[i<<1], tree[i<<1|1]);
  }

  void set(int i, const T& value) {
    for (tree[i += n] = value; i >>= 1; )
      tree[i] = combine(tree[i<<1], tree[i<<1|1]);
  }

  void add(int i, const T& delta) {
    assert(COMMUTATIVE);
    for (i += n; i; i >>= 1) tree[i].add(delta);
  }

  T query(int l, int r) const {  // [l, r)
    T resl = T(), resr = T();
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
      if (COMMUTATIVE) {
        if (l&1) resl.add(tree[l++]);
        if (r&1) resr.add(tree[--r]);
      } else {
        if (l&1) resl = combine(resl, tree[l++]);
        if (r&1) resr = combine(tree[--r], resr);
      }
    return combine(resl, resr);
  }
};

template <int V, bool ORIENTED = false>
class GraphUL {
  int n, m;
  vector<int> adjacent[V];

public:
  GraphUL(int newn = 0, int newm = -1) : n(0) { init(newn, newm); }

  void init(int newn, int newm = -1) {
    for (int i = 0; i < n; ++i) vector<int>().swap(adjacent[i]);
    n = newn;
    m = newm >= 0 ? newm : n;
  }

  void addEdge(int u, int v) {
    assert(u < n && v < m);
    adjacent[u].push_back(v);
    if (!ORIENTED && u != v) adjacent[v].push_back(u);
  }

  bool oriented() const { return ORIENTED; }
  int size() const { return n; }
  int size2() const { return m; }
  const vector<int>& operator [] (int v) const { return adjacent[v]; }
};

template <int V>
class LCA {
public:
  int i, treePos;
  int root[V], depth[V+1], pos[V];

  struct Imin {
    static int* data;
    int index;
    Imin(int index = V) : index(index) {}
    operator int() const { return index; }
    void add(const Imin& other) { if (data[other] < data[index]) index = other; }
    friend Imin combine(const Imin& lhs, const Imin& rhs) {
      return data[rhs] < data[lhs] ? rhs : lhs;
    }
  };
  SegmentTree<Imin> tree;

  template <class G>
  void dfs(const G& graph, int v) {
    root[v] = i;
    pos[v] = treePos;
    tree[treePos++] = v;
    for (int u : graph[v]) if (pos[u] == -1) {
      depth[u] = depth[v] + 1;
      dfs(graph, u);
      tree[treePos++] = v;
    }
  }

  template <class G>
  void build(const G& graph) {
    depth[V] = V;
    int n = graph.size();
    treePos = 0;
    fill_n(pos, n, -1);
    tree.init(2 * n - 1);
    for (i = 0; i < n; ++i) if (pos[i] == -1) {
      depth[i] = 0;
      dfs(graph, i);
    }
    Imin::data = depth;
    tree.build();
  }

  int lca(int u, int v) {
    if (root[u] != root[v]) return -1;
    if (pos[u] > pos[v]) swap(u, v);
    Imin::data = depth;
    return tree.query(pos[u], pos[v] + 1).index;
  }
};
template <int V> int* LCA<V>::Imin::data;

const int N = 1e5+5;
int n, q;
GraphUL<N> g;
LCA<N> lca;

int solve() {
  int k;
  scanf("%d", &k);
  vi a(k), pr(k), nx(k);
  REP(i, k) {
    scanf("%d", &a[i]);
    --a[i];
    pr[i] = i-1;
    nx[i] = i+1;
  }
  sort(all(a), [](int i, int j) { return lca.pos[i] < lca.pos[j]; });
//  print("%d", all(a));
  vi d(k);
  priority_queue<pii> q;
  auto add = [&](int i) {
    if (pr[i] == -1) {
      d[i] = -1;
      return;
    }
    int l = lca.lca(a[pr[i]], a[i]);
    d[i] = lca.depth[l];
    q.emplace(d[i], -i);
  };
  REP(i, k) add(i);
  int ans = 0;
  while (!q.empty()) {
    pii p = q.top();
    q.pop();
    int i = -p.Y, j = pr[i];
    if (d[i] != p.X) continue;
//    REP(u, k) printf("%d,%d(%d) ", pr[u], nx[u], d[u]); printf("\n%d\n", i);
    ++ans;
    bool lj = lca.depth[a[j]] == d[i];
    if (!lj) {
      d[j] = -1;
      j = pr[j];
    }
    int di = d[i];
    while (i != k && d[i] == di) {
      if (lj && lca.depth[a[i]] == d[i] + 1) return -1;
      d[i] = -1;
      i = nx[i];
      if (lj) break;
    }
    if (j != -1) nx[j] = i;
    if (i != k) {
      pr[i] = j;
      add(i);
    }
  }
  return ans;
}

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  g.init(n);
  REP(i, n-1) {
    int u, v;
    scanf("%d%d", &u, &v);
    g.addEdge(u-1, v-1);
  }
  lca.build(g);
  scanf("%d", &q);
  REP(i, q) printf("%d\n", solve());

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}