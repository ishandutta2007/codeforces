#include <iostream>
#include <set>
#include <vector>

#define int long long

const int MAXN = 100005;

std::vector<int> Adj[MAXN];
std::set<int> type[2];
int a[MAXN];
int sum = 0;

int n;

void list(int u, int p, int d) {
  type[d].insert(Adj[u].size());
  for(int j : Adj[u]) {
    if(j == p)
      continue;
    list(j, u, d^1);
  }
}

int mex(int u) {
  for(int i = 2; i <= n; i++) {
    if(!type[u].count(i))
      return i;
  }
}

const int LIM = 100000;

int test() {
  bool check = 1;
  for(int i = 0; i < n; i++)
    check &= -LIM <= a[i] && a[i] <= LIM && a[i] != 0;
  return check;
}

void dfs(int u, int p, int c, int tot) {
  int ct = 0;
  for(int j : Adj[u]) {
    if(j == p)
      continue;
    ct++;
    dfs(j, u, tot-c, tot);
  }
  a[u] = c - (tot-c)*ct;
  sum += a[u];
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    std::cin >> n;

    for(int i = 0; i < n; i++)
      Adj[i].clear();
    type[0].clear();
    type[1].clear();

    for(int i = 1; i < n; i++) {
      int u, v;
      std::cin >> u >> v;
      u--; v--;
      Adj[u].push_back(v);
      Adj[v].push_back(u);
    }

    bool search = true;
    for(int u = 0; u < 10 && search; u++) {
      for(int x = 0; x <= u && search; x++) {
        sum = 0;
        for(int j : Adj[0])
          dfs(j, 0, x, u);
        a[0] = u-sum;
        if(test())
          search = false;
      }
    }

    for(int i = 0; i < n; i++)
      std::cout << a[i] << " ";
    std::cout << std::endl;
  }

  return 0;
}