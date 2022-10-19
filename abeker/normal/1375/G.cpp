#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  scanf("%d", &N);
  vector <vector <int>> adj(N + 1);
  for (int i = 1; i < N; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int cnt[2] = {0};
  function <void(int, int, int)> dfs = [&](int x, int p, int clr) {
    cnt[clr]++;
    for (auto it : adj[x])
      if (it != p)
        dfs(it, x, clr ^ 1);
  };
  dfs(1, 0, 0);
  printf("%d\n", *min_element(cnt, cnt + 2) - 1);
  return 0;
}