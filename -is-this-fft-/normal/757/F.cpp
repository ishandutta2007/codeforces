#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Tree {
  /* insert structure here */
  int root;
  vector<vector<int>> adj;
  
  void set_root (int u) {
    root = u;
  }
  
  void add_edge (int u, int v) {
    adj[u].push_back(v);
  }

  int solve_dfs (int vertex, int &ans) {
    int sum = 1;
    for (int nxt : adj[vertex]) {
      sum += solve_dfs(nxt, ans);
    }

    if (vertex != root) {
      ans = max(ans, sum);
    }
    return sum;
  }

  int solve () {
    int ans = 0;
    solve_dfs(root, ans);
    return ans;
  }
  
  Tree (int _vertexc) {
    root = -1;
    adj = vector<vector<int>> (_vertexc + 5, vector<int> (0));
  }
};

struct Graph {
  vector<vector<int>> in_edges, out_edges;
  vector<int> ord, dfs_index, parent;
  vector<int> sdom, idom;
  vector<vector<int>> rsdom; /* inverse of sdom */
  vector<int> dsu; /* slightly modified version of dsu-s root[] */
  vector<int> label;

  void dfs (int vertex, int par, vector<int> &visited) {
    ord.push_back(vertex);
    parent[vertex] = par;
    dfs_index[vertex] = (int) ord.size() - 1;
    visited[vertex] = 1;
    for (int nxt : out_edges[vertex]) {
      if (!visited[nxt]) {
        dfs(nxt, vertex, visited);
      }
    }
  }

  void add_edge (int u, int v) {
    in_edges[v].push_back(u);
    out_edges[u].push_back(v);
  }

  Graph (int _vertexc) {
    in_edges = vector<vector<int>> (_vertexc, vector<int> (0));
    out_edges = vector<vector<int>> (_vertexc, vector<int> (0));
    ord = vector<int> (0);
    dfs_index = vector<int> (_vertexc, -1);
    parent = vector<int> (_vertexc, -1);
    sdom = vector<int> (_vertexc);
    idom = vector<int> (_vertexc);
    rsdom = vector<vector<int>> (_vertexc, vector<int> (0));
    dsu = vector<int> (_vertexc);
    label = vector<int> (_vertexc);
    for (int i = 0; i < _vertexc; i++) { 
      idom[i] = i;
      sdom[i] = i;
      dsu[i] = i;
      label[i] = i;
    }
  }

  int find (int u, int x = 0) {
    if (u == dsu[u]) {
      if (x) {
        return -1;
      } else {
        return u;
      }
    }

    int v = find(dsu[u], x + 1);
    if (v < 0) {
      return u;
    }

    if (dfs_index[sdom[label[dsu[u]]]] < dfs_index[sdom[label[u]]]) {
      label[u] = label[dsu[u]];
    }
    dsu[u] = v;
    return x ? v : label[u];
  }

  void merge (int u, int v) {
    dsu[v] = u;
  }
  
  Tree dom_tree (int src) {
    vector<int> visited ((int) idom.size(), 0);
    dfs(src, -1, visited);

    for (int i = (int) ord.size() - 1; i >= 0; i--) {
      int u = ord[i];
      for (int v : in_edges[u]) {
        int w = find(v);
        if (dfs_index[sdom[u]] > dfs_index[sdom[w]]) {
          sdom[u] = sdom[w];
        }
      }

      if (i > 0) {
        rsdom[sdom[u]].push_back(u);
      }

      for (int w : rsdom[u]) {
        int v = find(w);
        if (sdom[v] == sdom[w]) {
          idom[w] = sdom[w];
        } else {
          idom[w] = v;
        }
      }

      if (i > 0) {
        merge(parent[u], u);
      }
    }
    
    Tree ans ((int) sdom.size() + 5);
    for (int i = 1; i < (int) ord.size(); i++) {
      int u = ord[i];
      if (idom[u] != sdom[u]) {
        idom[u] = idom[idom[u]];
      }
      ans.add_edge(idom[u], u);
    }
    ans.set_root(src);
    return ans;
  }
};

typedef long long ll;

const int maxn = 200005;
const ll inf = 1LL << 60;
vector<pair<int, ll>> adj [maxn];
ll dist [maxn];
vector<int> preds [maxn];
bool vis [maxn];

int main () {
  int vertexc, edgec, src;
  cin >> vertexc >> edgec >> src;

  for (int i = 0; i < edgec; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
  }

  for (int i = 1; i <= vertexc; i++) {
    dist[i] = inf;
  }

  Graph SPDAG (vertexc + 5);
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;
  dist[src] = 0;
  Q.push(make_pair(dist[src], src));
  while (!Q.empty()) {
    int u = Q.top().second;
    Q.pop();

    if (!vis[u]) {
      vis[u] = 1;

      for (int v : preds[u]) {
        SPDAG.add_edge(v, u);
      }
      
      for (pair<int, ll> nxt : adj[u]) {
        if (dist[u] + nxt.second < dist[nxt.first]) {
          dist[nxt.first] = dist[u] + nxt.second;
          preds[nxt.first] = vector<int> (1, u);
          Q.push(make_pair(dist[nxt.first], nxt.first));
        } else if (dist[u] + nxt.second == dist[nxt.first]) {
          preds[nxt.first].push_back(u);
        }
      }
    }
  }

  Tree dom = SPDAG.dom_tree(src);
  cout << dom.solve() << endl;
}