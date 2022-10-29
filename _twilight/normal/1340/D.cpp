#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, D;
vector<int> G[N];
vector<pair<int, int>> ans;

void dfs(int p, int fa, int s) {
  ans.emplace_back(p, s);
  int s0 = s;
  for (auto e : G[p]) {
    if (e == fa) {
      continue;
    }
    if (s == D) {
      ans.emplace_back(p, s = D - (signed) G[p].size());
    }
    dfs(e, p, s += 1);
    ans.emplace_back(p, s);
  }
  if (p > 1 && s != s0 - 1) {
    ans.emplace_back(p, s0 - 1);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1, u, v; i < n; i++) {
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    D = max(D, (int) G[i].size());
  }
  dfs(1, 0, 0);
  printf("%d\n", (signed) ans.size());
  for (auto x : ans) {
    printf("%d %d\n", x.first, x.second);
  }
  return 0;
}