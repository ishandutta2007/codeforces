#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <bitset>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 8000;
int const sigma = 614;
std::bitset<1 + nmax> mat[1 + nmax];
int dir[1 + nmax];
int dist[1 + nmax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  int n;
  std::cin >> n;
  std::string s;

  for(int i = 1;i <= n; i++) {
    std::cin >> s;
    for(int j = 0; j < s.size(); j++) {
      int val = 0;
      if('0' <= s[j] && s[j] <= '9')
        val = s[j] - '0';
      else
        val = s[j] - 'A' + 10;
      for(int h = 0; h < 4; h++) 
        if(0 < (val & (1 << h)))
          mat[i][j * 4 + 4 - h] = 1;
        else
          mat[i][j * 4 + 4 - h] = 0;
    }
  }
  
  for(int i = 1; i <= n; i++) {
    dir[i] = i;
    for(int j = 1;j <= n; j++) 
      if(mat[i][j] == 1 && mat[dir[i]][j] == 1)
        dir[i] = j;
  }

  ll result = 0;

  for(int i = 1;i <= n; i++) {
    for(int j = 1;j <= n; j++)
      dist[j] = sigma * n;
    dist[i] = 0;
    int node = i;
    for(int step = 1; step <= 3; step++) {
      for(int j = 1;j <= n; j++)
        if(mat[node][j] == 1)
          dist[j] = std::min(dist[j], step);
      node = dir[node];
    }
    for(int j = 1;j <= n; j++)
      result = result + dist[j];
  }
  std::cout << result;
  return 0;
}