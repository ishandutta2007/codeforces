#include <iostream>
#include <set>

#define int long long

const int MAXN = 200005;

std::set<int> neigh[MAXN];
int cur[MAXN];

int sum;

void calc(int u) {
  sum -= cur[u];
  cur[u] = 0;
  if((neigh[u].size()) && ((*neigh[u].rbegin()) > u)) {
    cur[u] = 1;
  }
  sum += cur[u];
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m, q;
  std::cin >> n >> m;

  for(int i = 0; i < m; i++) {
    int u, v;
    std::cin >> u >> v;
    neigh[u].insert(v);
    neigh[v].insert(u);
    calc(u);
    calc(v);
  }

  std::cin >> q;

  while(q--) {
    int t;
    std::cin >> t;

    if(t == 1) {
      int u, v;
      std::cin >> u >> v;
      neigh[u].insert(v);
      neigh[v].insert(u);
      calc(u);
      calc(v);
    }
    else if(t == 2) {
      int u, v;
      std::cin >> u >> v;
      neigh[u].erase(v);
      neigh[v].erase(u);
      calc(u);
      calc(v);
    }
    else {
      std::cout << n-sum << std::endl;
    }
  }

  return 0;
}