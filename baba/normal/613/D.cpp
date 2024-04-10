// https://codeforces.com/contest/613/problem/D
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_set>
#include <vector>
using namespace std;

const int N = 1e5 + 10;
const int LOGN = 20;
int arr[N], dep[N], T, DP[LOGN][N], level[N];
vector<int> g[N];
vector<int> tree[N];
void dfs(int x, int p) {
  arr[x] = ++T;
  DP[0][x] = p;
  for (auto y : g[x]) {
    if (y != p) {
      level[y] = level[x] + 1;
      dfs(y, x);
    }
  }
  dep[x] = ++T;
}
int anc(int p, int x) { return arr[x] >= arr[p] && dep[x] <= dep[p]; }
int lca(int x, int y) {
  if (level[x] > level[y]) swap(x, y);
  if (anc(x, y)) return x;
  for (int i = LOGN - 1; i >= 0; i--) {
    if (!anc(DP[i][x], y)) {
      x = DP[i][x];
    }
  }
  return DP[0][x];
}
bool cmp(int u, int v) { return arr[u] < arr[v]; }
int create_tree(vector<int> &Q) {  // return root of tree
  // Sort based on arrival times.
  sort(Q.begin(), Q.end(), cmp);
  int k = Q.size();
  for (int i = 0; i + 1 < k; i++) {
    // add lca of adjacent pairs
    Q.push_back(lca(Q[i], Q[i + 1]));
  }
  // Sort & unique again based on arrival times.
  sort(Q.begin(), Q.end(), cmp);
  Q.resize(distance(Q.begin(), unique(Q.begin(), Q.end())));
  // Build the tree.
  stack<int> S;
  S.push(Q[0]);
  for (int i = 1; i < Q.size(); i++) {
    while (!anc(S.top(), Q[i])) S.pop();
    tree[S.top()].push_back(Q[i]);
    tree[Q[i]].push_back(S.top());
    S.push(Q[i]);
  }
  return Q[0];  // return root of tree
}
int is_marked[N], ans;
bool is_edge(int x, int y) {
  return binary_search(g[x].begin(), g[x].end(), y);
}
int dfs_query(int x, int p) {
  if (is_marked[x] && is_marked[p] && is_edge(x, p)) return ans = -1;
  int ret = 0;
  for (auto y : tree[x]) {
    if (y != p) {
      ret += dfs_query(y, x);
    }
  }
  if (ans == -1) return -1;
  if (is_marked[x])
    return (ans += ret, 1);
  else if (ret > 1)
    return (ans++, 0);
  else
    return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }
  for (int i = 1; i <= n; i++) sort(g[i].begin(), g[i].end());
  dfs(1, 1);
  for (int i = 1; i < LOGN; i++) {
    for (int x = 1; x <= n; x++) {
      DP[i][x] = DP[i - 1][DP[i - 1][x]];
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int k;
    cin >> k;
    vector<int> Q;
    for (int i = 0; i < k; i++) {
      int x;
      cin >> x;
      is_marked[x]++;
      Q.push_back(x);
    }
    int root = create_tree(Q);
    dfs_query(root, root);
    cout << ans << "\n";
    ans = 0;
    for (auto x : Q) {
      tree[x].clear();
      is_marked[x] = 0;
    }
  }
}