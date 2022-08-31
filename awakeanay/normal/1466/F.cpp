#include <iostream>
#include <vector>

#define int long long

const int MAXM = 500005;
const int MOD = 1000000007;

std::vector<int> par(MAXM, -1), done(MAXM, 0);

int ans = 1;

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
  done[u] |= done[v];
}

signed main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<int> mark(n, 0);
  int count = 0;
  for(int i = 0; i < n; i++) {
    int k;
    std::cin >> k;

    if(k == 1) {
      int x;
      std::cin >> x;

      if(!done[root(x)]) {
        done[root(x)] = 1;
        count++;
        mark[i] = 1;
        ans = (ans*2)%MOD;
      }
    }
    else {
      int x, y;
      std::cin >> x >> y;

      if(root(x) == root(y))
        continue;

      if(done[root(x)] && done[root(y)]) {
        merge(x, y);
        continue;
      }

      merge(x, y);
      ans = (ans*2)%MOD;
      count++;
      mark[i] = 1;
    }
  }

  std::cout << ans << " " << count << std::endl;
  for(int i = 0; i < n; i++)
    if(mark[i])
      std::cout << i+1 << " ";
  std::cout << std::endl;

  return 0;
}