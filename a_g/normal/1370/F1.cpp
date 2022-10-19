#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
vector<int> G[N];
int dep[N];

pair<int, int> query(vector<int> a) {
  cout << "? " << a.size();
  for (int v: a) cout << ' ' << v;
  cout << endl;
  pair<int, int> ans;
  cin >> ans.first >> ans.second;
  return ans;
}

pair<int, int> query_at_depth(int d, int n) {
  vector<int> layer;
  for (int v = 1; v <= n; v++) {
    if (dep[v] == d) layer.push_back(v);
  }
  assert(!layer.empty());
  return query(layer);
}

void dfs(int v, int p) {
  if (v == p) dep[v] = 0;
  for (int u: G[v]) {
    if (u == p) continue;
    dep[u] = dep[v]+1;
    dfs(u, v);
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    dfs(1, 1);
    vector<int> all_vtxs(n);
    iota(all_vtxs.begin(), all_vtxs.end(), 1);
    int dist, root;
    tie(root, dist) = query(all_vtxs);
    dfs(root, root);
    int s = root;
    {
      int low = (dist-1)/2;
      int high = *max_element(dep+1, dep+n+1)+1;
      while (high-low > 1) {
        int mid = (low+high)/2;
        pair<int, int> ans = query_at_depth(mid, n);
        if (ans.second == dist) {
          s = ans.first;
          low = mid;
        }
        else {
          high = mid;
        }
      }
    }
    dfs(s, s);
    int f = query_at_depth(dist, n).first;
    cout << "! " << s << ' ' << f << endl;

    string verdict;
    cin >> verdict;
    assert(verdict == "Correct");
    for (int i = 1; i <= n; i++) {
      G[i].clear();
    }
  }
}