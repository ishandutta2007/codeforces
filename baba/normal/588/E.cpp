// Accepted code for https://acm.timus.ru/problem.aspx?space=1&num=1471
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int N = 1e5 + 10;
const int LOGN = 20;
// Original Tree
vector<int> g[N];
int sub[N], nn, U[N], V[N], deleted[N];
vector<int> people[N];
// Centroid Tree
int par[N], level[N];
set<int> min_people[LOGN][N];
int adj(int x, int e) { return U[e] ^ V[e] ^ x; }
void dfs_sz(int u, int p) {
  sub[u] = 1;
  nn++;
  for (auto e : g[u]) {
    int w = adj(u, e);
    if (w != p && !deleted[e]) dfs_sz(w, u), sub[u] += sub[w];
  }
}
int find_centroid(int u, int p) {
  for (auto e : g[u]) {
    if (deleted[e]) continue;
    int w = adj(u, e);
    if (w != p && sub[w] > nn / 2) return find_centroid(w, u);
  }
  return u;
}
void add_edge_in_centroid_tree(int parent, int child) {
  par[child] = parent;
  level[child] = level[parent] + 1;
}
void dfs(int u, int p, int lvl) {
  min_people[lvl][u].insert(people[u].begin(), people[u].end());
  while (min_people[lvl][u].size() > 10)
    min_people[lvl][u].erase(--min_people[lvl][u].end());
  for (auto e : g[u]) {
    int w = adj(u, e);
    if (w == p || deleted[e]) continue;
    min_people[lvl][w] = min_people[lvl][u];
    dfs(w, u, lvl);
  }
}
void decompose(int root, int p = -1) {
  nn = 0;
  // Compute subtree sizes and no. of nodes (nn) in this tree.
  dfs_sz(root, root);
  // Find the centroid of the tree and make it the new root.
  int centroid = find_centroid(root, root);
  // Construct the Centroid Tree
  if (p == -1) p = centroid;
  add_edge_in_centroid_tree(p, centroid);
  // Process the O(N) paths from centroid to all leaves in this component.
  dfs(centroid, centroid, level[centroid]);
  // Delete the adjacent edges and recursively decompose the adjacent subtrees.
  for (auto e : g[centroid]) {
    if (deleted[e]) continue;
    deleted[e] = 1;
    int w = adj(centroid, e);
    decompose(w, centroid);
  }
}
int lca(int x, int y) {
  while (x != y) {
    if (level[x] > level[y]) swap(x, y);
    y = par[y];
  }
  return x;
}
set<int> query(int x, int y, int a) {
  // We need to compute the LCA(x, y) in the centroid tree.
  // O(logN).
  int lvl = level[lca(x, y)];
  auto res = min_people[lvl][x];
  res.insert(min_people[lvl][y].begin(), min_people[lvl][y].end());
  while(res.size() > a){
    res.erase(--res.end());
  }
  return res;
}

int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1; i < n; i++) {
    scanf("%d %d", U + i, V + i);
    g[U[i]].push_back(i);
    g[V[i]].push_back(i);
  }
  for (int i = 1; i <= m; i++) {
    int c;
    scanf("%d", &c);
    if (people[c].size() < 10) {
      people[c].push_back(i);
    }
  }
  decompose(1);
  while (q--) {
    int x, y, a;
    scanf("%d %d %d", &x, &y, &a);
    auto out = query(x, y, a);
    printf("%d ", (int)out.size());
    for (auto o : out) {
      printf("%d ", o);
    }
    puts("");
  }
}