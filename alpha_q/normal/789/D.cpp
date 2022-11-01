#include <bits/stdc++.h> 

using namespace std;

const int N = 1000010;

bitset <N> vis, looped;
vector <int> g[N];
int n, m, tot, loop, size;

void dfs (int u) {
  vis[u] = 1, ++size;
  for (int v : g[u]) {
    if (!vis[v]) dfs(v);
  }
}

int main (int argc, char const *argv[]) {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    if (u == v) {
      ++loop;
      looped[u] = 1;
      continue;
    }
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      size = 0;
      dfs(i);
      if (size > 1) ++tot;
      else if (looped[i]) ++tot;
      if (tot > 1) {
        puts("0");
        return 0;
      }
    }
  }
  long long res = (loop * 1ll * (loop - 1))/2 + loop * 1ll * (m - loop);
  for (int i = 1; i <= n; ++i) {
    int d = g[i].size();
    res += (d * 1ll * (d - 1))/2;
  }
  printf("%lld\n", res);
  return 0;
}