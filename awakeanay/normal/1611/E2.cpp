#include <iostream>
#include <vector>

#define int long long

const int MAXN = 200005;

std::vector<int> Adj[MAXN];

int fr[MAXN];
int frf[MAXN];
int ans;
int lost;
int stack[MAXN];
int st;

void dfs(int u, int p, int d) {
  stack[st++] = u;

  if(fr[u]) {
    frf[stack[(d+1)/2]] = 1;
  }

  for(int j : Adj[u]) {
    if(j == p)
      continue;
    dfs(j, u, d+1);
  }

  st--;
}

void dfs2(int u, int p) {
  if(frf[u]) {
    ans++;
    return;
  }

  int ct = 0;
  for(int j : Adj[u]) {
    if(j == p)
      continue;
    dfs2(j, u);
    ct++;
  }

  if(ct == 0) {
    lost = 1;
  }
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, k;
    std::cin >> n >> k;

    for(int i = 0; i < n; i++) {
      Adj[i].clear();
      fr[i] = 0;
      frf[i] = 0;
    }

    for(int i = 0; i < k; i++) {
      int x;
      std::cin >> x;
      x--;
      fr[x] = 1;
    }

    for(int i = 1; i < n; i++) {
      int u, v;
      std::cin >> u >> v;
      u--; v--;
      Adj[u].push_back(v);
      Adj[v].push_back(u);
    }

    st = 0;
    dfs(0, -1, 0);

    lost = 0;
    ans = 0;
    dfs2(0, -1);

    if(lost) {
      std::cout << -1 << std::endl;
    }
    else
      std::cout << ans << std::endl;
  }

  return 0;
}