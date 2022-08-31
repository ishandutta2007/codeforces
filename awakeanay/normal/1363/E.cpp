#include <iostream>
#include <vector>
#include <set>

#define int long long
#define MAXN 300000

int a[MAXN], b[MAXN], c[MAXN];
std::vector<int> Adj[MAXN];
std::set<std::pair<int, int> > st;
int ans;

std::pair<int, int> dfs(int u, int p) {
  st.insert({a[u], u});

  int x = 0, y = 0;
  for(int j : Adj[u]) {
    std::pair<int, int> next;
    if(j != p) {
      next = dfs(j, u);
      x += next.first;
      y += next.second;
    }
  }

  if(b[u] != c[u]) {
    if(b[u])
      x++;
    else
      y++;
  }

  if((*st.begin()).first == a[u]) {
    int done = std::min(x, y);
    ans += 2*done*a[u];
    x -= done;
    y -= done;
  }

  st.erase({a[u], u});
  return {x, y};
}

signed main() {
  int n;
  std::cin >> n;

  for(int i = 0; i < n; i++)
    std::cin >> a[i] >> b[i] >> c[i];

  for(int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    u--; v--;
    Adj[u].push_back(v);
    Adj[v].push_back(u);
  }

  std::pair<int, int> ret = dfs(0, -1);

  if(ret.first == 0 && ret.second == 0) {
    std::cout << ans << std::endl;
  }
  else
    std::cout << -1 << std::endl;

  return 0;
}