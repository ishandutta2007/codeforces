#include <iostream>
#include <vector>

#define int long long

const int MAXN = 100005;

std::vector<int> Adj[MAXN];
int rm[MAXN];
int sub[MAXN];
int val[MAXN];

int dfs(int u, int p) {
  sub[u] = 1;
  for(int j : Adj[u]) {
    if(j == p || rm[j])
      continue;
    sub[u] += dfs(j, u);
  }
  return sub[u];
}

int get_cen(int u, int p, int sz) {
  for(int j : Adj[u]) {
    if(j == p || rm[j])
      continue;
    if(2*sub[j] > sz)
      return get_cen(j, u, sz);
  }
  return u;
}

void centroid_decomp(int u, int d) {
  int cur_root = get_cen(u, -1, dfs(u, -1));
  val[cur_root] = d;
  rm[cur_root] = 1;

  for(int j : Adj[cur_root]) {
    if(rm[j])
      continue;
    centroid_decomp(j, d+1);
  }
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  for(int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    u--; v--;
    Adj[u].push_back(v);
    Adj[v].push_back(u);
  }

  centroid_decomp(0, 0);
  for(int i = 0; i < n; i++) {
    std::cout << (char)(val[i] + 'A') << " ";
  }

  return 0;
}