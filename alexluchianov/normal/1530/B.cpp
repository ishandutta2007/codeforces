#include <iostream>
#include <vector>

using ll = long long;
int const iplus[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int const jplus[8] = {1, -1, -1, 0, 1, -1, 0, 1};

int const nmax = 20;
int v[5 + nmax][5 + nmax];

int check(int x, int y) {
  int result = v[x][y];
  for(int h = 0; h < 8; h++)
    result += v[x + iplus[h]][y + jplus[h]];
  return result;
}

int main() {
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++) {
    int x, y;
    std::cin >> x >> y;
    for(int i = 1;i <= x + 1; i++)
      for(int j = 1; j <= y + 1; j++)
        v[i][j] = 0;
    for(int i = 1;i <= y; i++)
      if(check(1, i) == 0)
        v[1][i] = 1;
    for(int i = 1; i <= x; i++)
      if(check(i, y) == 0)
        v[i][y] = 1;
    for(int i = y; 1 <= i; i--)
      if(check(x, i) == 0)
        v[x][i] = 1;
    for(int i = x; 1 <= i; i--)
      if(check(i, 1) == 0)
        v[i][1] = 1;
    
    for(int i = 1;i <= x; i++) {
      for(int j = 1;j <= y; j++)
        std::cout << v[i][j];
      std::cout << '\n';
    }
    std::cout << '\n';
  }
  return 0;
}