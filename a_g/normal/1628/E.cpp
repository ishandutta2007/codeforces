#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+2;
const int INF = 1e9;
vector<tuple<int, int, int>> edges;
int line_index[N]; // vtx -> index in line tree
vector<int> costs;
int n, q;
int lazy[4*N]; // 1 = activate all, -1 = deactivate all
int segmax[4*N][2]; // 0 = current, 1 = if all active
int segmin[4*N][2];

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

void push(int v, int tl, int tr) {
  if (!lazy[v]) return;
  lazy[2*v] = lazy[v];
  lazy[2*v+1] = lazy[v];
  int tm = (tl+tr)/2;
  for (int u = 0; u < 2; u++) {
    segmax[2*v+u][0] = (lazy[v] == 1 ? segmax[2*v+u][1] : -INF);
    segmin[2*v+u][0] = (lazy[v] == 1 ? segmin[2*v+u][1] : INF);
  }
  lazy[v] = 0;
}

void combine(int v, int k) {
  segmax[v][k] = max(segmax[2*v][k], segmax[2*v+1][k]);
  segmin[v][k] = min(segmin[2*v][k], segmin[2*v+1][k]);
}

void init(int v, int tl, int tr) {
  segmax[v][0] = -INF;
  segmin[v][0] = INF;
  if (tl == tr) {
    segmax[v][1] = line_index[tl];
    segmin[v][1] = line_index[tl];
    return;
  }
  int tm = (tl+tr)/2;
  init(2*v, tl, tm);
  init(2*v+1, tm+1, tr);
  combine(v, 1);
}

void init() {
  init(1, 1, n);
}

void activate(int v, int tl, int tr, int l, int r, int x) {
  if (l > r) return;
  if (l == tl && r == tr) {
    lazy[v] = x;
    segmax[v][0] = (x == 1 ? segmax[v][1] : -INF);
    segmin[v][0] = (x == 1 ? segmin[v][1] : INF);
    return;
  }
  push(v, tl, tr);
  int tm = (tl+tr)/2;
  activate(2*v, tl, tm, l, min(r, tm), x);
  activate(2*v+1, tm+1, tr, max(l, tm+1), r, x);
  combine(v, 0);
}

void activate(int l, int r, int x) {
  activate(1, 1, n, l, r, x);
}

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
  sort(edges.begin(), edges.end());
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
  cin >> n >> q;

  edges.resize(n-1);
  for (int i = 0; i < n-1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[i] = make_tuple(w, u, v);
  }
  linearize();
  init();
  maxSparseTable<int> mst(costs);

  while (q--) {
    int t;
    cin >> t;
    if (t != 3) {
      int l, r;
      cin >> l >> r;
      if (t == 1) {
        activate(l, r, 1);
      }
      else {
        activate(l, r, -1);
      }
    }
    else {
      int x; 
      cin >> x;
      int l = min(segmin[1][0], line_index[x]);
      int r = max(segmax[1][0], line_index[x])-1;
      cout << mst.query(l, r) << '\n';
    }
  }
}