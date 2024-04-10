#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
vector<int> G[N];
int sz[N], dep[N], par[N];
bool live[N];

void dfs(int v, int p) {
  live[v] = 1;
  sz[v] = 1;
  par[v] = p;
  for (int u: G[v]) {
    if (u == p) continue;
    dep[u] = dep[v]+1;
    dfs(u, v);
    sz[v] += sz[u];
  }
}

void delete_edge(int u, int v) {
  G[v].erase(find(G[v].begin(), G[v].end(), u));
  G[u].erase(find(G[u].begin(), G[u].end(), v));
}

int query(int u, int v) {
  cout << "? " << u << " " << v << endl;
  int l;
  cin >> l;
  return l;
}

int answer(int v) {
  cout << "! " << v << endl;
  exit(0);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  int root = 1;
  dfs(root, root);
  while (sz[root] > 1) {
    bool found = 0;
    vector<int> children;
    for (int i = 1; i <= n; i++) {
      if (live[i] && dep[i] == 1) {
        children.push_back(i);
      }
      if (live[i] && dep[i] == 2) {
        found = 1;
        int k = query(root, i);
        if (k == root) {
          delete_edge(root, par[i]);
        }
        else if (k == par[i]) {
          delete_edge(root, par[i]);
          delete_edge(i, par[i]);
          root = par[i];
        }
        else {
          assert(k == i);
          delete_edge(i, par[i]);
          root = i;
        }
        break;
      }
    }

    if (!found) {
      if (children.size() == 1) {
        answer(query(root, children[0]));
      }
      int k = query(children[0], children[1]);
      if (k == children[0]) {
        delete_edge(root, children[0]);
        root = children[0];
      }
      else if (k == children[1]) {
        delete_edge(root, children[1]);
        root = children[1];
      }
      else {
        assert(k == root);
        delete_edge(root, children[0]);
        delete_edge(root, children[1]);
      }
    }

    fill(live+1, live+n+1, 0);
    dep[root] = 0;
    dfs(root, root);
  }
  answer(root);
}