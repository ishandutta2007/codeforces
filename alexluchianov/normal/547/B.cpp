#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

int const nmax = 200000;
int st[5 + nmax], dr[5 + nmax];
int v[5 + nmax];

int main() {
  int n;
  std::cin >> n;
  for(int i = 1; i <= n; i++) 
    std::cin >> v[i];
  v[0] = v[n + 1] = 0;
  for(int i = 1; i <= n; i++) {
    st[i] = i - 1;
    while(v[i] <= v[st[i]])
      st[i] = st[st[i]];
  }
  for(int i = n; 1 <= i; i--) {
    dr[i] = i + 1;
    while(v[i] <= v[dr[i]])
      dr[i] = dr[dr[i]];
  }
  std::vector<std::pair<int,int>> aux;

  for(int i = 1; i <= n; i++)
    aux.push_back({v[i], dr[i] - st[i] - 1});
  
  int ptr = 0;
  std::sort(aux.begin(), aux.end());
  std::reverse(aux.begin(), aux.end());
  for(int i = 0;i < aux.size(); i++) {
    while(ptr < aux[i].second) {
      std::cout << aux[i].first << " ";
      ptr++;
    }
  }
  std::cout << '\n';
  return 0;
}