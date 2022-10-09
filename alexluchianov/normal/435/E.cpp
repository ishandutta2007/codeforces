#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using ll = long long;

int const nmax = 1000;
char v[5 + nmax][5 + nmax];
char sol[5 + nmax][5 + nmax];

bool valid(int n, int m, std::string s) {
  for(int i = 0; i < n; i++) {
    if(i % 2 == 0) {
      for(int j = 0; j < m; j++)
        sol[i][j] = s[j % 2];
      for(int j = 0; j < m; j++) {
        if('0' != v[i][j]) {
          if(v[i][j] == s[0]) {
            for(int h = 0; h < m; h++)
              sol[i][h] = s[(j ^ h) % 2];
            break;
          } else if(v[i][j] == s[1]) {
            for(int h = 0; h < m; h++)
              sol[i][h] = s[(1 ^ j ^ h) % 2];
            break;
          } else {
            return 0;
          }
        }
      }
    } else {
      for(int j = 0; j < m; j++)
        sol[i][j] = s[2 + j % 2];
      for(int j = 0; j < m; j++) {
        if('0' != v[i][j]) {
          if(v[i][j] == s[2]) {
            for(int h = 0; h < m; h++)
              sol[i][h] = s[2 + (j ^ h) % 2];
            break;
          } else if(v[i][j] == s[3]) {
            for(int h = 0; h < m; h++)
              sol[i][h] = s[2 + (1 ^ j ^ h) % 2];
            break;
          } else {
            return 0;
          }
        }
      }
    }
    for(int j = 0; j < m; j++)
      if('0' != v[i][j] && sol[i][j] != v[i][j])
        return 0;
  }
  return 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  for(int i = 0;i < n; i++)
    std::cin >> v[i];
  
  std::string s = "1234";
  do {
    if(valid(n, m, s) == 1) {
      for(int i = 0; i < n; i++)
        std::cout << sol[i] << '\n';
      return 0;
    }
  } while(std::next_permutation(s.begin(), s.end()));
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      sol[i][j] = 0;
  s = "1234";

  for(int i = 0; i < std::max(n, m); i++)
    for(int j = 0; j < i; j++)
      std::swap(v[i][j], v[j][i]);
  std::swap(n, m);
  do {
    if(valid(n, m, s) == 1) {
      for(int i = 0; i < std::max(n, m); i++)
        for(int j = 0; j < i; j++)
          std::swap(sol[i][j], sol[j][i]);
      std::swap(n, m);

      for(int i = 0; i < n; i++)
        std::cout << sol[i] << '\n';
      return 0;
    }
  } while(std::next_permutation(s.begin(), s.end()));
  std::cout << 0 << '\n';
  return 0;
}