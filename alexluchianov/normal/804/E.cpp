#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 5;

int v[5 + nmax], mat[5 + nmax][5 + nmax];
std::vector<std::pair<int,int>> aux;

void backt(int n, int k, std::vector<std::pair<int,int>> &sol) {
  if(0 < sol.size())
    return ;
  if(k == n * (n - 1) / 2) {
    for(int i = 1;i <= n; i++)
      if(v[i] != i)
        return ;
    sol = aux;
  } else {
    for(int i = 1;i <= n; i++)
      for(int j = i + 1; j <= n; j++)
        if(mat[i][j] == 0) {
          mat[i][j] = 1;
          std::swap(v[i], v[j]);
          aux.push_back({i, j});
          backt(n, k + 1, sol);
          aux.pop_back();
          if(0 < sol.size())
            return ;
          std::swap(v[i], v[j]);
          mat[i][j] = 0;
        }
  }
}

std::vector<std::pair<int,int>> solve(int n) {
  for(int i = 1; i <= n; i++)
    v[i] = i;
  for(int i = 1;i <= n; i++)
    for(int j = i; j <= n; j++)
      mat[i][j] = 0;
  std::vector<std::pair<int,int>> sol;
  aux.clear();
  backt(n, 0, sol);
  return sol;
}

int main() {
  int n;
  std::cin >> n;
  if(n == 1) {
    std::cout << "YES\n";
  } else if(n % 4 == 0 || n % 4 == 1) {
    int blocks = n / 4;
    std::vector<std::pair<int,int>> sol4 = solve(4);
    std::vector<std::pair<int,int>> sol5 = solve(5);
    std::cout << "YES\n";
    for(int i = 0; i < blocks; i++)
      for(int j = i + 1; j < blocks; j++) {

        for(int h = 1; h <= 4; h++)
          std::cout << i * 4 + h << " " << j * 4 + h << '\n';
        for(int h = 0; h < sol4.size(); h++) {
          std::cout << sol4[h].first + i * 4 << " " << sol4[h].second + j * 4 << '\n';
          std::cout << sol4[h].second + i * 4 << " " << sol4[h].first + j * 4 << '\n';
        }
      }
    

    if(n % 4 == 0) {
      for(int i = 0; i < blocks; i++)
        for(int j = 0; j < sol4.size(); j++)
          std::cout << sol4[j].first + i * 4 << " " << sol4[j].second + i * 4 << '\n';
    } else if(n % 4 == 1) {
      for(int i = 0; i < blocks; i++)
        for(int j = 0; j < sol5.size(); j++) {
          if(sol5[j].second == 5)
            std::cout << sol5[j].first + i * 4 << " " << n << '\n';
          else
            std::cout << sol5[j].first + i * 4 << " " << sol5[j].second + i * 4 << '\n';
        }
    }
  } else
    std::cout << "NO\n";
  return 0;
}