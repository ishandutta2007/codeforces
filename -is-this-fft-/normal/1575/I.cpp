#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

class Fenwick {
  vector<ll> tree;

public:
  Fenwick () {
  }

  Fenwick (int n, ll init) : tree(n + 5, 0) {
  }

  void add (int idx, ll val) {
    for (int i = idx; i < (int) tree.size(); i += i & -i) {
      tree[i] += val;
    }
  }

  ll get (int idx) {
    ll ans = 0;
    for (int i = idx; i > 0; i -= i & -i) {
      ans += tree[i];
    }
    return ans;
  }
  
  ll query (int l, int r) {
    ll ans = get(r) - get(l - 1);
    return ans;
  }

  void set (int idx, ll val) {
    add(idx, val - query(idx, idx));
  }
};

/* T should be the type of the data stored in each
 * vertex; DS should be the underlying data structure
 * that is used to peform the group operation. It should
 * have the following methods:
 * * DS () - empty constructor
 * * DS (int size, T initial) - constructs the structure
 * with the given size, initially filled with initial.
 * * void set (int index, T value) - set the value at
 * index `index` to `value`
 * * T query (int left, int right) - return the "sum" of
 * elements between left and right, inclusive.
 */
//!start
template <typename T, class DS>
class HLD {
  int vertexc;
  vector<int> *adj;
  vector<int> subtree_size;
  DS structure;
  DS aux;

  void build_sizes(int vertex, int parent) {
    subtree_size[vertex] = 1;
    for (int child : adj[vertex]) {
      if (child != parent) {
        build_sizes(child, vertex);
        subtree_size[vertex] += subtree_size[child];
      }
    }
  }

  int cur;
  vector<int> ord;
  vector<int> chain_root;
  vector<int> par;
  void build_hld(
    int vertex, int parent, int chain_source) {
    cur++;
    ord[vertex] = cur;
    chain_root[vertex] = chain_source;
    par[vertex] = parent;

    if (adj[vertex].size() > 1 ||
        (vertex == 1 && adj[vertex].size() == 1)) {
      int big_child, big_size = -1;
      for (int child : adj[vertex]) {
        if ((child != parent) &&
            (subtree_size[child] > big_size)) {
          big_child = child;
          big_size = subtree_size[child];
        }
      }

      build_hld(big_child, vertex, chain_source);
      for (int child : adj[vertex]) {
        if ((child != parent) && (child != big_child))
          build_hld(child, vertex, child);
      }
    }
  }

 public:
  HLD(int _vertexc) {
    vertexc = _vertexc;
    adj = new vector<int>[vertexc + 5];
  }

  void add_edge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  void build(T initial) {
    subtree_size = vector<int>(vertexc + 5);
    ord = vector<int>(vertexc + 5);
    chain_root = vector<int>(vertexc + 5);
    par = vector<int>(vertexc + 5);
    cur = 0;
    build_sizes(1, -1);
    build_hld(1, -1, 1);
    structure = DS(vertexc + 5, initial);
    aux = DS(50, initial);
  }

  void set(int vertex, int value) {
    structure.set(ord[vertex], value);
  }

  T query_path(int u,
    int v) { /* returns the "sum" of the path u->v */
    int cur_id = 0;
    while (chain_root[u] != chain_root[v]) {
      if (ord[u] > ord[v]) {
        cur_id++;
        aux.set(cur_id,
          structure.query(ord[chain_root[u]], ord[u]));
        u = par[chain_root[u]];
      } else {
        cur_id++;
        aux.set(cur_id,
          structure.query(ord[chain_root[v]], ord[v]));
        v = par[chain_root[v]];
      }
    }

    cur_id++;
    aux.set(cur_id, structure.query(min(ord[u], ord[v]),
                      max(ord[u], ord[v])));

    return aux.query(1, cur_id);
  }
  //!finish

  void print() {
    for (int i = 1; i <= vertexc; i++)
      cout << i << ' ' << ord[i] << ' ' << chain_root[i]
           << ' ' << par[i] << endl;
  }
};

const int MAX_N = 1e5 + 5;

ll arr [MAX_N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, qc;
  cin >> n >> qc;
  
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    arr[i] = abs(arr[i]);
  }

  HLD<ll, Fenwick> hld (n + 5);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    hld.add_edge(u, v);
  }
  hld.build(1);

  for (int i = 1; i <= n; i++) {
    hld.set(i, arr[i]);
  }
  
  for (int i = 0; i < qc; i++) {
    int type;
    cin >> type;

    if (type == 1) {
      int u, c;
      cin >> u >> c;

      arr[u] = abs(c);
      hld.set(u, arr[u]);
    } else {
      int u, v;
      cin >> u >> v;

      ll ans = hld.query_path(u, v);
      ans *= 2;
      ans -= arr[u];
      ans -= arr[v];
      cout << ans << '\n';
    }
  }
}