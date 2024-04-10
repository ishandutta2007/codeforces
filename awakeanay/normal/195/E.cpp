#include <iostream>
#include <vector>

#define int long long

const int MAXN = 100005;
const int MOD = 1000000007;

std::vector<int> par(MAXN, -1), depth(MAXN, 0);

std::pair<int, int> get(int x) {
  if(par[x] < 0)
    return {x, 0};
  std::pair<int, int> next = get(par[x]);
  par[x] = next.first;
  depth[x] = (depth[x] + next.second)%MOD;
  return {par[x], depth[x]};
}

signed main() {
  int n;
  std::cin >> n;
  int ans = 0;

  for(int i = 0; i < n; i++) {
    int k;
    std::cin >> k;

    while(k--) {
      int v, e;
      std::cin >> v >> e;
      e %= MOD;
      if(e < 0)
        e = 2*MOD+e;
      e %= MOD;
      v--;

      std::pair<int, int> next = get(v);
      int w = (next.second+e)%MOD;
      par[next.first] = i;
      depth[next.first] = w;
      ans = (ans+w)%MOD;
    }
  }

  std::cout << ans << std::endl;
}