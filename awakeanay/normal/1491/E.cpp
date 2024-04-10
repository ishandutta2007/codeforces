#include <iostream>
#include <vector>
#include <set>

#define int long long

const int MAXN = 200005;
int fib[200];

struct data
{
  int u, p, sz;
};

std::vector<data> cur;
std::set<std::pair<int, int> > used;
std::vector<int> Adj[MAXN];
std::vector<int> dis(MAXN, 0);

data dfs(int u, int p) {
  data add;
  add.p = p;
  add.u = u;
  add.sz = 1;

  for(int j : Adj[u]) {
    if(dis[j])
      continue;
    if(j == p)
      continue;

    data next = dfs(j, u);
    add.sz += next.sz;
  }

  cur.push_back(add);
  return add;
}

bool check(int u, int f) {
  if(f == 1 || f == 0)
    return true;

  cur.clear();

  for(int j : Adj[u]) {
    if(dis[j])
      continue;
    dfs(j, u);
  }

  for(data j : cur) {
    if(j.sz == fib[f-1]) {
      bool poss = true;
      dis[j.u] = true;
      poss &= check(j.p, f-2);
      dis[j.u] = false;
      dis[j.p] = true;
      poss &= check(j.u, f-1);
      return poss;
    }
    else if(j.sz == fib[f-2]) {
      bool poss = true;
      dis[j.u] = true;
      poss &= check(j.p, f-1);
      dis[j.u] = false;
      dis[j.p] = true;
      poss &= check(j.u, f-2);
      return poss;
    }
  }

  return false;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  for(int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    u--; v--;
    Adj[u].push_back(v);
    Adj[v].push_back(u);
  }

  fib[0] = fib[1] = 1;
  int right = -1;
  for(int i = 2; i < 200; i++)
    fib[i] = fib[i-1] + fib[i-2];

  for(int i = 0; i < 200; i++)
    if(n == fib[i])
      right = i;

  if(right == -1 || (!check(0, right)))
    std::cout << "NO" << std::endl;
  else
    std::cout << "YES" << std::endl;
    

  return 0;
}