#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const sigma = 3;
ll const inf = 1000000000000000000;

struct Disk{
  ll dp[sigma][sigma];
  Disk operator + (Disk a) {
    Disk result;
    for(int i = 0; i < sigma; i++)
      for(int j = 0; j < sigma; j++)
        if(i != j)
          result.dp[i][j] = std::min(a.dp[i][3 - i - j] + dp[i][j] + a.dp[3 - i - j][j], a.dp[i][j] + dp[i][3 - i - j] + a.dp[j][i] + dp[3 - i - j][j] + a.dp[i][j]);
    return result;
  }

  void normalize() {
    dp[0][0] = dp[1][1] = dp[2][2] = 0;
    for(int mid = 0; mid < sigma; mid++)
      for(int i = 0; i < sigma; i++)
        for(int j = 0; j < sigma; j++)
          dp[i][j] = std::min(dp[i][j], dp[i][mid] + dp[mid][j]);
  }
};

int main() {
  Disk basic;
  for(int i = 0;i < sigma; i++)
    for(int j = 0;j < sigma; j++)
      std::cin >> basic.dp[i][j];
  int n;
  std::cin >> n;
  Disk up = basic;
  up.normalize();

  for(int i = n - 1; 1 <= i; i--) {
    up = basic + up;
    up.normalize();
  }
  std::cout << up.dp[0][2];
  return 0;
}