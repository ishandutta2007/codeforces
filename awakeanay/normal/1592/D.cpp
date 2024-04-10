#include <iostream>
#include <set>
#include <vector>

#define int long long

const int MAXN = 1005;

std::vector<int> et;
std::vector<int> Adj[MAXN];
std::set<int> s;

void dfs(int u, int p) {
  et.push_back(u);
  for(int j : Adj[u]) {
    if(j == p)
      continue;
    dfs(j, u);
    et.push_back(u);
  }
}

int query() {
  std::cout << "? ";
  std::cout << s.size() << " ";
  for(int j : s)
    std::cout << j+1 << " ";
  std::cout << std::endl;
  int x;
  std::cin >> x;
  s.clear();
  return x;
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

  dfs(0, -1);
  int best;
  for(int i = 0; i < n; i++)
    s.insert(i);
  best = query();

  int lo = 0, hi = 2*n-2;
  while(lo < hi) {
    int mid = (lo+hi)/2;
    for(int i = lo; i <= mid+1; i++)
      s.insert(et[i]);
    if(query() == best)
      hi = mid;
    else
      lo = mid+1;
  }

  std::cout << "! " << et[lo]+1 << " " << et[lo+1]+1 << std::endl;

  return 0;
}