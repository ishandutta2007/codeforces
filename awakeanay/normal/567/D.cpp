#include <iostream>
#include <vector>

#define int long long

const int MAXN = 200005;

int tot = 0;
std::vector<int> par;
int n, k, a;

int root(int u) {
  if(par[u] < 0)
    return u;
  return par[u] = root(par[u]);
}

void merge(int u, int v) {
  u = root(u);
  v = root(v);

  if(u == v)
    return;

  if(par[u] > par[v])
    u ^= v ^= u ^= v;

  tot -= (-par[u]+1)/a;
  tot -= (-par[v]+1)/a;

  par[u] += par[v];
  par[v] = u;

  tot += (-par[u]+1)/a;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  
  std::cin >> n >> k >> a;
  a++;

  std::vector<int> set(n, 0);
  par = std::vector<int>(n, -1);

  int m;
  std::cin >> m;

  int x[m];
  int nset = 0;
  for(int i = 0; i < m; i++) {
    std::cin >> x[i];
    x[i]--;
    set[x[i]] = 1;
    nset++;
  }

  tot = (n-nset)*(2/a);

  for(int i = 1; i < n; i++) {
    if(set[i] || set[i-1])
      continue;

    merge(i-1, i);
  }

  if(tot >= k) {
    std::cout << -1 << std::endl;
    return 0;
  }

  for(int i = m-1; i >= 0; i--) {
    tot += (2/a);
    set[x[i]] = 0;

    if(x[i] && (!set[x[i]-1]))
      merge(x[i]-1, x[i]);
    if(x[i]+1 < n && (!set[x[i]+1]))
      merge(x[i]+1, x[i]);

    if(tot >= k) {
      std::cout << i+1 << std::endl;
      return 0;
    }
  }

  return 0;
}