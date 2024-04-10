#include <iostream>
#include <set>

#define int long long

const int MAXN = 1003;

int par[MAXN];

int root(int x) {
  if(par[x] < 0)
    return x;
  return par[x] = root(par[x]);
}

int max = 1;

void merge(int u, int v) {
  u = root(u);
  v = root(v);

  if(u == v)
    return;

  if(par[u] > par[v])
    u ^= v ^= u ^= v;

  par[u] += par[v];
  par[v] = u;

  max = std::max(max, -par[u]);
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, d;
  std::cin >> n >> d;

  for(int i = 0; i < n; i++) {
    par[i] = -1;
  }

  int a[d], b[d];
  for(int i = 0; i < d; i++) {
    std::cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }

  int extra = 0;
  for(int i = 0; i < d; i++) {
    if(root(a[i]) != root(b[i])) {
      merge(a[i], b[i]);
    }
    else 
      extra++;

    std::set<std::pair<int, int> > poss;
    for(int j = 0; j < n; j++) {
      if(par[j] < 0)
        poss.insert({par[j], j});
    }

    int cur = 0;
    for(int j = 0; j <= extra; j++) {
      if(poss.empty())
        break;
      cur -= (*poss.begin()).first;
      poss.erase(poss.begin());
    }

    std::cout << cur-1 << std::endl;
  }

  return 0;
}