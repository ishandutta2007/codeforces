#include <iostream>
#include <vector>

std::vector<int> par;

int root(int u) {
  if(par[u] < 0)
    return u;
  return par[u] = root(par[u]);
}

void merge(int u, int v) {
  u = root(u);
  v = root(v);

  if(par[u] > par[v])
    u ^= v ^= u ^= v;

  par[u] += par[v];
  par[v] = u;
}

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int ans[n+1];

    par = std::vector<int>(n+1, -1);
    for(int i = 0; i < n; i++) {
      if((i%2)^(s[i]=='R')) {
        merge(i, i+1);
      }
    }

    for(int i = 0; i <= n; i+=2)
      ans[i] = -par[root(i)];

    par = std::vector<int>(n+1, -1);
    for(int i = 0; i < n; i++) {
      if((i%2)^(s[i]=='L')) {
        merge(i, i+1);
      }
    }

    for(int i = 1; i <= n; i+=2)
      ans[i] = -par[root(i)];

    for(int i = 0; i <= n; i++)
      std::cout << ans[i] << " ";
    std::cout << std::endl;
  }

  return 0;
}