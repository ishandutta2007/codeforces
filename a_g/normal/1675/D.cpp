#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
vector<int> children[N];
vector<vector<int>> paths;

void dfs(int v) {
  int c = children[v].size();
  if (!c) {
    paths.emplace_back(1, v);
    return;
  }
  for (int u: children[v]) {
    dfs(u);
  }
  paths.back().push_back(v);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int root = -1;
    for (int i = 1; i <= n; i++) {
      int p;
      cin >> p;
      if (p == i) root = i;
      else children[p].push_back(i);
    }
    dfs(root);
    cout << paths.size() << '\n';
    for (vector<int>& p: paths) {
      cout << p.size() << '\n';
      reverse(p.begin(), p.end());
      for (int v: p) {
        cout << v << ' ';
      }
      cout << '\n';
    }
    for (int i = 1; i <= n; i++) {
      children[i].clear();
    }
    paths.clear();
  }
}