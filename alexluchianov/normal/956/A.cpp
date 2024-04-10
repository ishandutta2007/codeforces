#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int const nmax = 100;
std::vector<int> g[1 + 2 * nmax];
int edge[1 + nmax][1 + nmax];
int seen[1 + nmax];

void dfs(int node, std::vector<int> &aux) {
  seen[node] = 1;
  aux.push_back(node);
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(seen[to] == 0) 
      dfs(to, aux);
  }
}

int main() {
  int n, m;
  std::cin >> n >> m;
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++) {
      char val;
      std::cin >> val;
      if(val == '#') {
        edge[i][j] = 1;
        g[i].push_back(j + n);
        g[j + n].push_back(i);
      }
    }
  
  bool verdict = true;

  for(int i = 1;i <= n + m; i++) {
    std::vector<int> aux; 
    dfs(i, aux);
    std::vector<int> rows, cols;
    for(int j = 0; j < aux.size(); j++) 
      if(aux[j] <= n)
        rows.push_back(aux[j]);
      else
        cols.push_back(aux[j] - n);
    for(int j = 0; j < rows.size(); j++)
      for(int k = 0; k < cols.size(); k++)
        verdict &= edge[rows[j]][cols[k]];
  }

  if(verdict == false)
    std::cout << "No";
  else
    std::cout << "Yes";
  return 0;
}