#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9 + 5;

class Segtree {
  int n;
  vector<pair<int, int>> tree;
  vector<int> lfend;
  vector<int> rgend;

public:
  Segtree (int _n) {
    n = 1;
    while (n < _n) {
      n *= 2;
    }

    tree = vector<pair<int, int>> (2 * n, {INF, -INF});
    lfend = vector<int> (2 * n);
    rgend = vector<int> (2 * n);

    for (int i = n; i < 2 * n; i++) {
      lfend[i] = i - n;
      rgend[i] = i - n;
    }

    for (int i = n - 1; i > 0; i--) {
      lfend[i] = lfend[2 * i];
      rgend[i] = rgend[2 * i + 1];
    }
  }

  pair<int, int> op (pair<int, int> a, pair<int, int> b) {
    return make_pair(min(a.first, b.first), max(a.second, b.second));
  }
  
  pair<int, int> query (int ql, int qr, int u = 1) {
    ql = max(ql, lfend[u]);
    qr = min(qr, rgend[u]);

    if (ql > qr) return {INF, -INF};
    if (ql == lfend[u] && qr == rgend[u]) return tree[u];
    return op(query(ql, qr, 2 * u), query(ql, qr, 2 * u + 1));
  }

  void set (int pos, pair<int, int> val) {
    tree[n + pos] = val;
    for (int u = (n + pos) / 2; u != 0; u /= 2) {
      tree[u] = op(tree[2 * u], tree[2 * u + 1]);
    }
  }
};

class DSU {
  vector<int> root;

public:
  DSU (int _vertexc) {
    root = vector<int> (_vertexc);
    for (int i = 0; i < _vertexc; i++) {
      root[i] = i;
    }
  }

  int find (int u) {
    if (u != root[u]) {
      root[u] = find(root[u]);
    }
    return root[u];
  }

  void merge (int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v) {
      return;
    }

    root[v] = u;
  }
};

const int MAX_N = 3e5 + 5;
const int MAX_LG = 20;

vector<int> adj [MAX_N];
int ord [MAX_N];
int rev_ord [MAX_N];
int lvl [MAX_N];
int jmp [MAX_LG][MAX_N];

void dfs (int u, int p, int &cur) {
  ord[u] = cur;
  rev_ord[cur] = u;
  cur++;

  lvl[u] = lvl[p] + 1;
  jmp[0][u] = p;
  for (int k = 1; k < MAX_LG; k++) {
    jmp[k][u] = jmp[k - 1][jmp[k - 1][u]];
  }

  for (int nxt : adj[u]) {
    if (nxt == p) continue;
    dfs(nxt, u, cur);
  }
}

int lca (int u, int v) {
  if (lvl[u] < lvl[v]) swap(u, v);
  int diff = lvl[u] - lvl[v];
  for (int k = 0; k < MAX_LG; k++) {
    if (diff & 1 << k) {
      u = jmp[k][u];
    }
  }

  if (u == v) return u;
  
  for (int k = MAX_LG - 1; k >= 0; k--) {
    if (jmp[k][u] != jmp[k][v]) {
      u = jmp[k][u];
      v = jmp[k][v];
    }
  }

  return jmp[0][u];
}

void add_edge (int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

void solve () {
  int n, m, qc;
  cin >> n >> m >> qc;

  for (int i = 0; i < n + m; i++) {
    adj[i].clear();
    lvl[i] = 0;
  }

  int root;
  DSU dsu (n + m);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;

    u = dsu.find(u);
    v = dsu.find(v);
    if (u != v) {
      add_edge(n + i, u);
      add_edge(n + i, v);
      dsu.merge(n + i, u);
      dsu.merge(n + i, v);
      root = n + i;
    }
  }

  int tmp = 0;
  dfs(root, root, tmp);

  Segtree tree (n);
  for (int i = 0; i < n; i++) {
    tree.set(i, {ord[i], ord[i]});
  }

  for (int i = 0; i < qc; i++) {
    int l, r;
    cin >> l >> r;
    l--; r--;

    if (l == r) {
      cout << 0 << " ";
      continue;
    }

    auto ab = tree.query(l, r);
    int u = lca(rev_ord[ab.first], rev_ord[ab.second]);
    cout << u - n + 1 << " ";
  }
  cout << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}