#include <stdexcept>
#include <iostream>
#include <iomanip>
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

template <class T, int V, int E>
class Flow {
public:
  struct Edge {
    int to, next;
    T capacity, flow;
    Edge(int to = -1, const T& capacity = 0, int next = -1)
        : to(to), next(next), capacity(capacity), flow(0) {}
    T residual() { return capacity - flow; }
  } edges[2 * E];

  int n, k;
  int head[V], dist[V], queue[V];

  bool bfs(int s, int t) {
    fill_n(dist, n, -1);
    queue[0] = s;
    dist[s] = 1;
    for (int *v = queue, *tail = v + 1; v != tail; ++v)
      for (int e = head[*v]; e != -1; e = edges[e].next)
        if (edges[e^1].residual() != 0 && dist[s = edges[e].to] == -1) {
          dist[*tail++ = s] = dist[*v] + 1;
          if (s == t) return true;
        }
    return false;
  }

  T dfs(int s, int t, T flow) {
    if (s == t) return flow;
    T initial = flow, value;
    for (int& e = queue[s]; e != -1; e = edges[e].next)
      if (edges[e].residual() != 0 && dist[edges[e].to] == dist[s]-1 &&
          (value = dfs(edges[e].to, t, min(edges[e].residual(), flow))) != 0) {
        edges[e].flow += value;
        edges[e^1].flow -= value;
        if ((flow -= value) == 0) break;
      }
    return initial - flow;
  }

  Flow(int n = 0) { init(n); }

  void init(int newn) {
    n = newn;
    k = 0;
    fill_n(head, n, -1);
  }

  void addEdge(int u, int v, const T& capacity, bool bidir = true) {
    assert(u < n && v < n);
    edges[k] = Edge(v, capacity, head[u]);
    head[u] = k++;
    edges[k] = Edge(u, bidir ? capacity : 0, head[v]);
    head[v] = k++;
  }

  T maxFlow(int s, int t) {
    T flow = 0;
    while (bfs(t, s)) {
      copy_n(head, n, queue);
      flow += dfs(s, t, numeric_limits<T>::max());
    }
    return flow;
  }
};

class Prufer {
  vector<int> parent;

  template <class G>
  void dfs(const G& graph, int v) {
    for (int u : graph[v]) if (u != parent[v]) {
      parent[u] = v;
      dfs(graph, u);
    }
  }

  template <class UnaryOperation>
  bool go(int n, int i, vector<int>& code, UnaryOperation op) {
    if (i == n - 2) return op(pruferDecode(code));
    for (code[i] = 0; code[i] < n; ++code[i])
      if (go(n, i + 1, code, op)) return true;
    return false;
  }

public:
  template <class G>
  vector<int> pruferEncode(const G& graph) {
    int n = graph.size();
    parent.resize(n);
    parent[n - 1] = -1;
    dfs(graph, n - 1);
    vector<int> degree(n);
    for (int i = 0; i < n; ++i) degree[i] = graph[i].size();
    int ptr = static_cast<int>(find(degree.begin(), degree.end(), 1)
                               - degree.begin());
    vector<int> code(n - 2);
    for (int i = 0, leaf = ptr; i < n - 2; ++i) {
      int next = code[i] = parent[leaf];
      if (--degree[next] == 1 && next < ptr) leaf = next;
      else {
        for (++ptr; ptr < n && degree[ptr] != 1; ++ptr);
        leaf = ptr;
      }
    }
    return code;
  }

  vector<int> pruferDecode(const vector<int>& code) {  // returns parents
    int n = static_cast<int>(code.size()) + 2;
    parent.resize(n);
    vector<int> degree(n, 1);
    for (int i = 0; i < n - 2; ++i) ++degree[code[i]];
    int ptr = static_cast<int>(find(degree.begin(), degree.end(), 1)
                               - degree.begin());
    int leaf = ptr;
    for (int i = 0; i < n - 2; ++i) {
      int v = parent[leaf] = code[i];
      if (--degree[v] == 1 && v < ptr) leaf = v;
      else {
        for (++ptr; ptr < n && degree[ptr] != 1; ++ptr);
        leaf = ptr;
      }
    }
    parent[leaf] = n - 1;
    parent[n - 1] = -1;
    return parent;
  }

  template <class UnaryOperation>
  bool generate(int n, UnaryOperation op) {
    vector<int> code(n - 2);
    return go(n, 0, code, op);
  }
};

const int N = 2e5+5, D = 6;
int n, m;
int e1[D], e[D][D];
vi v[D];

Flow<int, D*D + D + 2, 3*D*D + D> flow;
Prufer prufer;
vi parent;

bool check(const vi& p) {
  REP(i, m-1) if (e[i][p[i]] == 0) {
    if (e[p[i]][i] == 0) return false;
    ++e[i][p[i]];
    --e[p[i]][i];
  }
  REP(i, m-1) --e[i][p[i]];
  int k = m*m+m+2;
  flow.init(k);
  REP(i, m) REP(j, m) {
    int u = i*m+j;
    flow.addEdge(u, m*m+i, n, false);
    flow.addEdge(u, m*m+j, n, false);
  }
  REP(i, m) {
    REP(j, m) flow.addEdge(k-2, i*m+j, e[i][j], false);
    flow.addEdge(m*m+i, k-1, sz(v[i]) - 1, false);
  }
  REP(i, m-1) ++e[i][p[i]];
  parent = p;
  return flow.maxFlow(k-2, k-1) == n - m;
}

bool solve() {
  if (m == 1) {
    FOR(i, 2, n+1) printf("1 %d\n", i);
    return true;
  }
  if (!prufer.generate(m, check)) return false;
  REP(i, m-1) printf("%d %d\n", v[i][0], v[parent[i]][0]);
  int e = 0;
  REP(i, m) REP(j, m) {
    REP(u, flow.edges[e].flow) {
      printf("%d %d\n", v[j][0], v[i].back());
      v[i].pop_back();
    }
    e += 2;
    REP(u, flow.edges[e].flow) {
      printf("%d %d\n", v[i][0], v[j].back());
      v[j].pop_back();
    }
    e += 2;
  }
  return true;
}

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  char s1[2*D], s2[2*D];
  REP(i, n-1) {
    scanf("%s%s", s1, s2);
    ++e[strlen(s1) - 1][strlen(s2) - 1];
  }
  for (int i = 1, t = 1; i <= n; ++i) {
    if (i == t) ++m, t *= 10;
    v[m-1].pb(i);
  }
  if (!solve()) printf("-1\n");

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}