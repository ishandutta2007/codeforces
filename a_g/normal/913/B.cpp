#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
vector<int> children[N];
bool ok = 1;

int dfs(int v) {
  if (!children[v].size()) return 1;
  int leaves = 0;
  for (int u: children[v]) {
    leaves += dfs(u);
  }
  if (leaves < 3) ok = 0;
  return 0;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;
    children[p].push_back(i);
  }
  dfs(1);
  cout << (ok ? "Yes" : "No") << '\n';
}