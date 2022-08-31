#include <iostream>
#include <vector>

using namespace std;

void failure () {
  cout << 0 << endl;
  exit(0);
}

const int MAX_N = 3e5 + 5;

class Fenwick {
  int n;
  vector<int> _tree;
  vector<int> age;
  int cur_age;

  int& tree (int pos) {
    if (age[pos] != cur_age) {
      age[pos] = cur_age;
      _tree[pos] = 0;
    }
    return _tree[pos];
  }
  
public:
  Fenwick (int _n = 0) : n(_n), _tree(_n, 0), age(_n, 0), cur_age(0) {}

  void reset () {
    cur_age++;
  }

  void add (int pos, int val) {
    for (int i = pos; i < n; i += i & -i) {
      tree(i) += val;
    }
  }

  int get (int pos) {
    int ans = 0;
    for (int i = pos; i != 0; i -= i & -i) {
      ans += tree(i);
    }
    return ans;
  }

  int get (int l, int r) {
    return get(r) - get(l - 1);
  }

  int at (int pos) {
    return get(pos, pos);
  }
};

namespace Tree {
  int root;
  int par [MAX_N];
  vector<int> adj [MAX_N];
  int lfend [MAX_N];
  int rgend [MAX_N];
  Fenwick fenp, fenpm;

  void dfs (int u, int &cur) {
    cur++;
    lfend[u] = cur;
    for (int nxt : adj[u]) {
      dfs(nxt, cur);
    }
    rgend[u] = cur;
  }
  
  void build () {
    int cur = 0;
    dfs(root, cur);

    fenp = Fenwick(cur + 5);
    fenpm = Fenwick(cur + 5);
  }
  
  bool validate (const vector<int> &arr) {
    fenp.reset();
    fenpm.reset();
    
    for (int u : arr) {
      if (fenp.get(lfend[u], rgend[u])) {
        return false; // we have been in a child of this node
      }

      if (u != root && !fenp.at(lfend[par[u]]) && fenpm.get(lfend[u])) {
        return false; // we have been in a non-immediate ancestor but not at the parent
      }

      fenp.add(lfend[u], 1);
      fenpm.add(lfend[u], 1);
      fenpm.add(rgend[u] + 1, -1);
    }
    return true;
  }
}

int nxt [MAX_N];
int prv [MAX_N];
int src [MAX_N];

vector<int> get_path (int u) {
  vector<int> vec;

  int cur = u;
  do {
    vec.push_back(cur);
    src[cur] = u;
    cur = nxt[cur];
  } while (cur != 0);

  return vec;
}

void add_to (vector<int> &ans, int u) {
  int cur = u;
  do {
    ans.push_back(cur);
    cur = nxt[cur];
  } while (cur != 0);
}

namespace Graph {
  vector<int> in_adj [MAX_N];

  void add_edge (int u, int v) {
    in_adj[v].push_back(u);
  }

  int vis [MAX_N];
  void dfs (int u, vector<int> &ans) {
    vis[u] = 1;
    for (int p : in_adj[u]) {
      if (vis[p] == 1) {
        failure();
      }

      if (vis[p] == 0) {
        dfs(p, ans);
      }
    }
    add_to(ans, u);
    vis[u] = 2;
  }
  
  vector<int> solve (int n) {
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
      if (prv[i] == 0 && !vis[i]) {
        dfs(i, ans);
      }
    }
    return ans;
  }
}

int main () {
  ios::sync_with_stdio(false);

  int n, K;
  cin >> n >> K;

  for (int i = 1; i <= n; i++) {
    cin >> Tree::par[i];
    if (Tree::par[i] == 0) {
      Tree::root = i;
    } else {
      Tree::adj[Tree::par[i]].push_back(i);
    }
  }
  Tree::build();

  for (int i = 0; i < K; i++) {
    int u, v;
    cin >> u >> v;

    if (nxt[u] != 0) failure();
    if (prv[v] != 0) failure();

    nxt[u] = v;
    prv[v] = u;
  }

  for (int i = 1; i <= n; i++) {
    if (prv[i] == 0) {
      auto vec = get_path(i);
      if (!Tree::validate(vec)) {
        failure();
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    if (src[i] == 0) {
      failure();
    }
  }

  for (int i = 1; i <= n; i++) {
    if (Tree::par[i] != 0) {
      int u = src[Tree::par[i]];
      int v = src[i];
      if (u != v) {
        Graph::add_edge(u, v);
      }
    }
  }

  auto ans = Graph::solve(n);
  for (int u : ans) {
    cout << u << " ";
  }
  cout << '\n';
}