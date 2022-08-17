#include <iostream>

#define int long long

const int MAXN = 100005;

int par[MAXN];

int root(int x) {
  if(par[x] < 0)
    return x;
  return par[x] = root(par[x]);
}

void merge(int u, int v) {
  u = root(u);
  v = root(v);

  if(u == v)
    return;

  if(par[u] > par[v])
    u ^= v ^= u ^= v;

  par[u] += par[v];
  par[v] = u;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n], b[n];

    for(int i = 0; i < n; i++) {
      par[i] = -1;
      std::cin >> a[i];
      a[i]--;
    }

    for(int i = 0; i < n; i++) {
      std::cin >> b[i];
      b[i]--;
      merge(a[i], b[i]);
    }

    int num = n;
    for(int i = 0; i < n; i++) {
      if(par[i] < 0 && (-par[i])%2 == 1)
        num--;
    }

    int ans = 0;
    for(int i = 0; i < num/2; i++)
      ans += n-1-i-i;

    std::cout << 2*ans << std::endl;
  }

  return 0;
}