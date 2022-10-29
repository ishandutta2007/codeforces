#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <random>
#include <cmath>
#include <ctime>
#include <functional>
#include <algorithm>
#include <complex>
#include <numeric>
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

template <class T> T& smin(T& x, const T& y) { if (x > y) x = y; return x; }
template <class T> T& smax(T& x, const T& y) { if (x < y) x = y; return x; }
template <class T> T sqr(const T& x) { return x * x; }

template <typename Iterator>
void print(const char* fmt, Iterator begin, Iterator end,
           const char* delimiter = " ", const char* closing = "\n") {
  for (; begin != end; ++begin != end ? printf("%s", delimiter) : 0)
    printf(fmt, *begin);
  printf("%s", closing);
}

class DSU {
  vector<int> parent, size;

public:
  DSU(int n = 0) { init(n); }

  int add() {
    int v = (int)parent.size();
    parent.emplace_back(v);
    size.emplace_back(1);
    return v;
  }

  void init(int n) {
    parent.resize(n);
    for (int i = 0; i < n; ++i) parent[i] = i;
    size.assign(n, 1);
  }

  int find(int v) {
    int u = v, t;
    while (u != parent[u]) u = parent[u];
    while (parent[v] != u) t = parent[v], parent[v] = u, v = t;
    return u;
  }

  bool join(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (size[a] < size[b]) swap(a, b);
    size[a] += size[b];
    parent[b] = a;
    return true;
  }
};

template <class T, int V, int E>
class GraphWE {
  int n, m, k;
  vector<int> adjacent[V];

  struct Edge {
    int uv;
    T weight;
    Edge(int u = 0, int v = 0, const T& weight = T())
    : uv(u ^ v), weight(weight) {}
  } edges[E];

  class Row {
    const GraphWE& graph;
    int v;

    class iterator {
      const Row& row;
      vector<int>::const_iterator it;
    public:
      iterator(const Row& row, vector<int>::const_iterator it)
      : row(row), it(it) {}
      bool operator != (const iterator& other) const { return it != other.it; }
      pair<int, T> operator * () const {
        const Edge& edge = row.graph.edges[*it];
        return {row.v ^ edge.uv, edge.weight};
      }
      const iterator& operator ++ () { ++it; return *this; }
      int operator - (const iterator& other) { return it - other.it; }
      iterator operator + (int offset) { return iterator(row, it + offset); }
    };

  public:
    Row(const GraphWE& graph, int v) : graph(graph), v(v) {}
    iterator begin() const { return iterator(*this, graph.adjacent[v].begin());}
    iterator end() const { return iterator(*this, graph.adjacent[v].end()); }
  };

public:
  GraphWE(int newn = 0, int newm = -1) : n(0) { init(newn, newm); }

  void init(int newn, int newm = -1) {
    for (int i = 0; i < n; ++i) vector<int>().swap(adjacent[i]);
    n = newn;
    m = newm >= 0 ? newm : n;
    k = 0;
  }

  void addEdge(int u, int v, const T& weight) {
    assert(u < n && v < m);
    adjacent[u].push_back(k);
    if (u != v) adjacent[v].push_back(k);
    edges[k++] = Edge(u, v, weight);
  }

  bool oriented() const { return false; }
  int size() const { return n; }
  int size2() const { return m; }
  Row operator [] (int v) const { return Row(*this, v); }
};

template <int N> struct Log2 { enum { value = 1 + Log2<N/2>::value }; };
template <>   struct Log2<0> { enum { value = 0 }; };

template <class T, int V>
class LCA {
  static const int L = Log2<V>::value;
  int depth[V];
  int parent[V][L];
  T value[V][L];

  template <class G>
  void dfs(const G& graph, int v) {
    for (auto&& edge : graph[v]) {
      int u = edge.first;
      if (depth[u] != -1) continue;
      depth[u] = depth[v] + 1;
      value[u][0] = edge.second;
      int w = parent[u][0] = v;
      for (int j = 0; w != -1 && j + 1 < L; ++j) {
        value[u][j+1] = combine(value[u][j], value[w][j]);
        parent[u][j+1] = w = parent[w][j];
      }
      dfs(graph, u);
    }
  }

public:
  template <class G>
  void build(const G& graph) {
    int n = graph.size();
    for (int i = 0; i < n; ++i) fill_n(parent[i], L, -1);
    fill_n(depth, n, -1);
    for (int i = 0; i < n; ++i) if (depth[i] == -1) {
      depth[i] = 0;
      dfs(graph, i);
    }
  }

  pair<int, T> lca(int u, int v) {
    T res = T();
    if (depth[u] < depth[v]) swap(u, v);
    for (int d = depth[u] - depth[v], j = 0; d; d >>= 1, ++j) if (d&1) {
      res.add(value[u][j]);
      u = parent[u][j];
    }
    if (u == v) return {u, res};
    for (int j = L-1; j >= 0; --j) if (parent[u][j] != parent[v][j]) {
      res.add(value[u][j]);
      u = parent[u][j];
      res.add(value[v][j]);
      v = parent[v][j];
    }
    if (parent[u][0] == -1 || parent[v][0] == -1 ||
        parent[u][0] != parent[v][0]) return {-1, T()};
    res.add(combine(value[u][0], value[v][0]));
    return {parent[u][0], res};
  }
};

template <class T> struct Tmax {
  T value;
  Tmax(const T& value = numeric_limits<T>::min()) : value(value) {}
  operator T() const { return value; }
  void add(const Tmax& other) { smax(value, other.value); }
  friend Tmax combine(const Tmax& lhs, const Tmax& rhs) {
    return max(lhs.value, rhs.value); }
};


struct Edge {
  int u, v, i;
  int weight;
  void inp() { scanf("%d%d%d", &u, &v, &weight); --u; --v; }
};

vector<int> MST(int n, const vector<Edge>& edges) {
  int m = (int)edges.size();
  vector<int> p(m);
  for (int i = 0; i < m; ++i) p[i] = i;
  sort(p.begin(), p.end(), [&edges](int i, int j) {
    return edges[i].weight < edges[j].weight; });
  DSU dsu(n);
  int joins = 0;
  for (int i : p) if (dsu.join(edges[i].u, edges[i].v)) {
    p[joins++] = i;
    if (joins == n - 1) break;
  }
  p.erase(p.begin() + joins, p.end());
  return p;
}

const int N = 2e5+5;
int n, m;
vector<Edge> e;
bool used[N];

GraphWE<int, N, N> g;
LCA<Tmax<int>, N> lca;

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &n, &m);
  e.resize(m);
  REP(i, m) e[i].inp();
  vi mst = MST(n, e);

  ll w = 0;
  g.init(n);
  for (int i : mst) {
    used[i] = true;
    w += e[i].weight;
    g.addEdge(e[i].u, e[i].v, e[i].weight);
  }
  lca.build(g);

  REP(i, m) {
    if (used[i]) printf("%I64d\n", w);
    else printf("%I64d\n", w + e[i].weight - lca.lca(e[i].u, e[i].v).Y);
  }

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}