#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using ll = long long;

int const nmax = 500000;
int v[5 + nmax], ptr = 0;
int seen[1 + nmax], mark[1 + nmax];
std::pair<int,int> aint[5 + 4 * nmax];

void update(int node, int from, int to, int x, int val) {
  if(from < to) {
    int mid = (from + to) / 2;
    if(x <= mid)
      update(node * 2, from, mid, x, val);
    else
      update(node * 2 + 1, mid + 1, to, x, val);
    aint[node] = std::max(aint[node * 2], aint[node * 2 + 1]);
  } else
    aint[node] = {val, from};
}

std::pair<int,int> query(int node, int from, int to, int x, int y) {
  if(from == x && to == y)
    return aint[node];
  else {
    int mid = (from + to) / 2;
    if(x <= mid && y <= mid)
      return query(node * 2, from, mid, x, y);
    else if(mid + 1 <= x && mid + 1 <= y)
      return query(node * 2, from, mid, x, y);
    else
      return std::max(query(node * 2, from, mid, x, mid),
          query(node * 2 + 1, mid + 1, to, mid + 1, y));
  }
}

int n;

void dfs(int node, std::vector<int> &ord) {
  seen[node] = 1;
  if(0 < mark[node]) 
    if(seen[mark[node]] == 0)
      dfs(mark[node], ord);

  if(-1 == v[node]) 
    v[node] = n; 

  std::pair<int,int> smin = query(1, 1, n, 1, v[node]); 
  while(node < smin.first) {
    update(1, 1, n, smin.second, 0);
    if(seen[smin.second] == 0)
      dfs(smin.second, ord);
    smin = query(1, 1, n, 1, v[node]); 
  }
  ord.push_back(node);
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  std::cin >> n;
  for(int i = 1;i <= n; i++) {
    std::cin >> v[i];
    if(0 <= v[i])
      mark[v[i]] = i;
  }

  for(int i = 1;i <= n; i++)
    if(0 < mark[i])
      update(1, 1, n, i, mark[i]);
    else
      update(1, 1, n, i, n + 1);

  std::vector<int> ord;

  for(int i = 1; i <= n; i++)
    if(seen[i] == 0)
      dfs(i, ord);
  std::vector<int> sol(1 + n);
  int acc = 0;
  for(int i = 0; i < ord.size(); i++) {
    if(ord[i] <= n) {
      sol[ord[i]] = ++acc;
    }
  }

  for(int i = 1; i <= n; i++)
    std::cout << sol[i] << " ";
  std::cout << '\n';
  return 0;
}