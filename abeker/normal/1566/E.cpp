#include <bits/stdc++.h>
using namespace std;

typedef pair <int, bool> pib;

const int MAXN = 2e5 + 5;

int N;
vector <int> adj[MAXN];

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

pib dfs(int x, int p) {
  int children = 0, leaves = 0;
  for (auto it : adj[x])
    if (it != p) {
      pib tmp = dfs(it, x);
      children += tmp.second;
      leaves += tmp.first;
    }
  leaves += children;
  return {leaves, !children};
}

int solve() {
  pib sol = dfs(1, 0);
  return 2 * sol.first + sol.second - N + 1;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    printf("%d\n", solve());
  }
  return 0;
}