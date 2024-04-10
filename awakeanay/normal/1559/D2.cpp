#include <iostream>
#include <set>

#define int long long

const int MAXN = 100005;

std::set<int> roots[2];
int par[2][MAXN];
int min, max;

int root(int u, int x) {
  if(par[x][u] < 0)
    return u;
  return par[x][u] = root(par[x][u], x);
}

void merge(int u, int v, int x) {
  u = root(u, x);
  v = root(v, x);

  if(u == v)
    return;

  if(par[x][u] > par[x][v])
    u ^= v ^= u ^= v;

  roots[x].erase(v);
  par[x][u] += par[x][v];
  par[x][v] = u;
}

void addEdge(int u, int v) {
  merge(u, v, 0);
  merge(u, v, 1);
  std::cout << u+1 << " " << v+1 << std::endl;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m[2];
  std::cin >> n >> m[0] >> m[1];

  int out = n-1-std::max(m[0], m[1]);

  std::cout << out << std::endl;

  for(int i = 0; i < n; i++) {
    par[0][i] = par[1][i] = -1;
    roots[0].insert(i);
    roots[1].insert(i);
  }

  min = 1;
  max = 0;

  if(m[0] > m[1]) {
    min = 0;
    max = 1;
  }

  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < m[i]; j++) {
      int u, v;
      std::cin >> u >> v;
      u--; v--;
      merge(u, v, i);
    }
  }
  
  while(m[min] != n-1) {
    int u = *roots[max].begin();
    int v = *roots[max].rbegin();

    if(root(u, min) != root(v, min)) {
      addEdge(u, v);
    }
    else {
      int x = *roots[min].begin();
      int y = *roots[min].rbegin();
      int z = root(u, min);

      if(x == z)
        x ^= y ^= x ^= y;

      if(root(x, max) != root(u, max)) {
        addEdge(x, u);
      }
      else {
        addEdge(x, v);
      }
    }
    
    m[min]++; m[max]++;
  }

  return 0;
}