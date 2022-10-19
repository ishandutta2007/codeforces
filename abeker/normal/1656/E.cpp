#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N;
vector <int> adj[MAXN];
int ans[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
    adj[i].clear();
  for (int i = 1; i < N; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
}

void dfs(int x, int p, int d) {
  ans[x] = adj[x].size();
  if (d)
    ans[x] *= -1;
  for (auto it : adj[x])
    if (it != p)
      dfs(it, x, d ^ 1);
}

void solve() {
  dfs(1, 0, 0);
  for (int i = 1; i <= N; i++)
    printf("%d ", ans[i]);
  puts("");
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    solve();
  }
  return 0;
}