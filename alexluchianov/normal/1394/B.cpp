#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <algorithm>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int const sigma = 9;

std::vector<std::pair<int,int>> g[1 + nmax];
std::vector<int> id[1 + sigma];
int in_grade[1 + nmax]; 

int compat[1 + sigma][1 + sigma][1 + sigma][1 + sigma];
int lim;

bool check_compat(int x, int x2, int y, int y2) {
  bool valid = 1;
  for(int i = 0; i < id[x].size(); i++) {
    int to = g[id[x][i]][x2].second;
    in_grade[to]++;
    if(1 < in_grade[to])
      valid = 0;
  }
  for(int i = 0; i < id[y].size(); i++) {
    int to = g[id[y][i]][y2].second;
    in_grade[to]++;
    if(1 < in_grade[to])
      valid = 0;
  }
  for(int i = 0; i < id[x].size(); i++) {
    int to = g[id[x][i]][x2].second;
    in_grade[to]--;
  }
  for(int i = 0; i < id[y].size(); i++) {
    int to = g[id[y][i]][y2].second;
    in_grade[to]--;
  }
  return valid;
}

int sol[1 + nmax];

int backtracking(int k) {
  if(k == lim + 1)
    return 1;
  else {
    int result = 0;
    for(int i = 0; i < k; i++) {
      int valid = 1;
      sol[k] = i;
      for(int j = 1;j < k; j++)
        if(compat[j][sol[j]][k][sol[k]] == 0)
          valid = 0;
      if(valid == 1)
        result += backtracking(k + 1);
    }
    return result;
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m >> lim;
  for(int i = 1;i <= m; i++) {
    int x, y, cost;
    std::cin >> x >> y >> cost;
    g[x].push_back({cost, y});
  }
  
  for(int i = 1;i <= n; i++) {
    std::sort(g[i].begin(), g[i].end());
    id[g[i].size()].push_back(i);
  }
  if(check_compat(0, 0, 1, 0) == 0) {
    std::cout << 0;
    return 0;
  }

  for(int i = 1;i <= lim; i++)
    for(int i2 = 0; i2 < i; i2++)
      for(int j = 1;j <= lim; j++)
        for(int j2 = 0; j2 < j; j2++)
          compat[i][i2][j][j2] = check_compat(i, i2, j, j2);

  std::cout << backtracking(1);
  return 0;
}