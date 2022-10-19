#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
const int INF = 1e9;
vector<tuple<int, int, int>> edges;
int line_index[N]; // vtx -> index in line tree
vector<int> costs;
int n, q;

template<typename T>
class maxSparseTable {
  public:
    int n;
    int rows;
    vector<vector<T>> st;
    maxSparseTable (vector<T> vals) {
      n = vals.size();
      rows = floor(log2(n))+1;
      for (int i = 0; i < n; i++) {
        st.push_back(vector<T>(rows));
      }
      for (int i = 0; i < n; i++) {
        st[i][0] = vals[i];
      }
      for (int j = 1; j < rows; j++) {
        for (int i = 0; i + (1<<j) <= n; i++) {
          st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
      }
    }
    T query(int l, int r) {
      if (l > r) return -1;
      int j = 31-__builtin_clz(r-l+1);
      return max(st[l][j], st[r-(1<<j)+1][j]);
    }
};

class dsu {
  // only path compression
  public:
    vector<int> parents;
    vector<int> leftpts;
    // root is always at the right
    dsu (int n) {
      parents.resize(n);
      leftpts.resize(n);
      iota(parents.begin(), parents.end(), 0);
      iota(leftpts.begin(), leftpts.end(), 0);
    }
    int root(int u) {
      return parents[u] == u ? u : parents[u] = root(parents[u]);
    }
    bool join(int u, int v) {
      // u = left part, v = right part
      int a = root(u);
      int b = root(v);
      if (a == b) return 0;
      parents[a] = b;
      leftpts[b] = leftpts[a];
      return 1;
    }
};

void linearize() {
  // input 1-indexed, output 0-indexed
  dsu d(n+1);
  vector<int> nextpt(n+1);
  vector<int> nextedge(n+1);
  for (tuple<int, int, int> e: edges) {
    int w, u, v;
    tie(w, u, v) = e;
    nextpt[d.root(u)] = d.leftpts[d.root(v)];
    nextedge[d.root(u)] = w;
    d.join(u, v);
  }
  vector<bool> is_start(n+1, 1);
  for (int i = 1; i <= n; i++) {
    is_start[nextpt[i]] = 0;
  }

  costs.resize(n);
  for (int i = 1; i <= n; i++) {
    if (is_start[i]) {
      int v = i;
      int index = 0;
      while (v) {
        costs[index] = nextedge[v];
        line_index[v] = index++;
        v = nextpt[v];
      }
      break;
    }
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int m;
    cin >> n >> m >> q;
    dsu D(n+1);
    for (int i = 1; i <= m; i++) {
      int u, v;
      cin >> u >> v;
      if (D.join(u, v)) {
        edges.emplace_back(i, u, v);
      }
    }

    linearize();
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
      c[i] = line_index[i+1];
    }
    maxSparseTable<int> rightmost(c);
    for (int& x: c) x = -x;
    maxSparseTable<int> leftmost(c);
    maxSparseTable<int> mst(costs);

    while (q--) {
      int l, r;
      cin >> l >> r;
      int nl = -leftmost.query(l-1, r-1);
      int nr = rightmost.query(l-1, r-1);
      if (nl == nr) {
        cout << "0 ";
      }
      else cout << mst.query(nl, nr-1) << ' ';
    }
    cout << '\n';
    edges.clear();
  }
}