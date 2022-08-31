#include <bits/stdc++.h>
using namespace std;

const int maxN = 3e5 + 5;

vector<int> adj[maxN];
int fa[maxN], vis[maxN], sg[maxN];
int n, ans, cnt;

void dfs1(int u) {
  for (auto v : adj[u]) {
    if (v == fa[u]) continue;
    fa[v] = u; dfs1(v); sg[u] ^= (sg[v] + 1);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs1(1);
  for (int i = 1; i <= n; i++) {
    int u = i;
    while (u && !vis[u]) {
      vis[u] = 1; ++cnt;
      for (auto v : adj[u]) {
        if (v == fa[u] || vis[v]) continue;
        ans ^= (sg[v] + 1);
      }
      if (fa[u] && vis[fa[u]]) {
        ans ^= (sg[u] + 1);
      }
      u = fa[u];
    }
    if (ans ^ ((cnt - 1) & 1)) printf("1");
    else printf("2");
  }
  printf("\n");
  return 0;
}