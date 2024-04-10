#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+2;
const int K = 20;
int par[N][K], dep[N], tin[N], tout[N];
vector<int> G[N];
int timer = 1;

int bit[2*N];

void add(int i, int x) {
  for (; i < 2*N; i += i&-i) bit[i] += x;
}

int query(int i) {
  int ans = 0;
  for (; i > 0; i -= i&-i) ans += bit[i];
  return ans;
}

void dfs1(int v) {
  tin[v] = timer++;
  for (int i = 1; i < K; i++) {
    par[v][i] = par[par[v][i-1]][i-1];
  }
  for (int u: G[v]) {
    dep[u] = dep[v]+1;
    dfs1(u);
  }
  tout[v] = timer++;
}

int kth_ancestor(int v, int k) {
  for (int i = K-1; i >= 0; i--) {
    if ((k>>i)&1) {
      v = par[v][i];
    }
  }
  return v;
}

int sum_subtree(int v) {
  return query(tout[v])-query(tin[v]-1);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;
    G[p].push_back(i);
    par[i][0] = p;
  }
  dfs1(1);

  vector<pair<int, int>> back_edges;
  vector<pair<int, int>> cross_edges;
  while (m--) {
    int u, v;
    cin >> u >> v;
    if (dep[u] > dep[v]) swap(u, v);
    if (par[v][0] == u) {
      cout << "-1\n";
      return 0;
    }
    if (tin[u] <= tin[v] && tout[u] >= tout[v]) {
      back_edges.emplace_back(u, v);
    }
    else cross_edges.emplace_back(u, v);
  }

  sort(back_edges.begin(), back_edges.end(),
      [&] (pair<int, int>& e1, pair<int, int>& e2) {
      return dep[e1.first] > dep[e2.first];
      });

  int marked = 0;
  for (auto& [u, v]: back_edges) {
    int w = kth_ancestor(v, dep[v]-dep[u]-1);
    if (sum_subtree(w)-sum_subtree(v) == 0) {
      add(tin[w], 1);
      marked++;
    }
  }

  for (auto& [u, v]: cross_edges) {
    if (sum_subtree(u)+sum_subtree(v) == marked) {
      marked++;
      break;
    }
  }
  cout << marked << '\n';
}