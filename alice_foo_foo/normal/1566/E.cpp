#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;

vector<int> adj[maxN];
int f[maxN];
int T, n, ans;

void dfs(int u, int fa) {
  f[u] = 0;
  int cnt = 0;
  for (auto v : adj[u]) {
    if (v == fa) continue;
    dfs(v, u);
    if (f[v] == 0) f[u] = 1, ++cnt;
  }
  ans += max(0, cnt - 1); 
}

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) adj[i].clear();
    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    ans = 1;
    dfs(1, 0);
    printf("%d\n", ans);
  }
  return 0;
}