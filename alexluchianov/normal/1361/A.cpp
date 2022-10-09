#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int const nmax = 500000;
std::vector<int> g[1 + nmax];
int id[1 + nmax], sol[1 + nmax];

bool compare(int x, int y){
  return id[x] < id[y];
}

int solve(int node){
  std::vector<int> temp;
  temp.push_back(0);

  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    temp.push_back(sol[to]);
  }
  std::sort(temp.begin(), temp.end());
  temp.erase(unique(temp.begin(), temp.end()), temp.end());
  for(int i = 0; i < temp.size(); i++)
    if(temp[i] != i)
      return i;
  return temp.size();
}

int main(){
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;
  for(int i = 1; i <= m; i++){
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for(int i = 1;i <= n; i++)
    std::cin >> id[i];

  std::vector<int> ord;
  for(int i = 1; i <= n; i++)
    ord.push_back(i);
  std::sort(ord.begin(), ord.end(), compare);
  
  for(int i = 0; i < ord.size(); i++)
    sol[ord[i]] = solve(ord[i]);
  
  for(int i = 1; i <= n; i++)
    if(sol[i] != id[i]){
      std::cout << -1;
      return 0;
    }

  for(int i = 0; i < ord.size(); i++)
    std::cout << ord[i] << " ";
  std::cout << '\n';
  return 0;
}