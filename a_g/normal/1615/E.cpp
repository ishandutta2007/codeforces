#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+2;
vector<int> adj[N];
int leaves[N];
int parent[N];
int depth[N];
int marked[N];

void dfs(int v, int p) {
  if (v == p) depth[v] = 0;
  else depth[v] = depth[p]+1;
  bool is_leaf = 1;
  parent[v] = p;
  for (int u: adj[v]) {
    if (u != p) {
      is_leaf = 0;
      dfs(u, v);
      leaves[v] += leaves[u];
    }
  }
  leaves[v] += is_leaf;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 1);
  if (leaves[1] <= k) {
    int u = max(leaves[1], min(k, n/2));
    cout << 1LL * u * (n-u) << '\n';
    return 0;
  }

  vector<pair<int, int>> ld;
  for (int i = 2; i <= n; i++) {
    if (adj[i].size() == 1) {
      ld.push_back({depth[i], i});
    }
  }
  sort(ld.begin(), ld.end(), greater<pair<int, int>>());

  vector<pair<int, int>> lv;
  for (pair<int, int> x: ld) {
    int v = x.second;
    int c = 0;
    while (1) {
      marked[v] = 1;
      v = parent[v];
      if (marked[v]) break;
      c++;
    }
    lv.push_back({c, x.second});
  }
  nth_element(lv.begin(), lv.begin()+k-1, lv.end(), greater<pair<int, int>>());
  int w = 0;
  for (int i = 0; i < k; i++) w += lv[i].first;
  int b = min(n-k-w, n/2);
  cout << 1LL * (n-b-k) * (k-b) << endl;
}