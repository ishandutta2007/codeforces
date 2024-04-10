#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200;

struct Interval{
  int x;
  int y;
  int id;
  bool operator < (Interval a) {
    return x < a.x;
  }
} v[1 + nmax];
int dp[1 + nmax][1 + nmax];

int intersect(int x, int y, int x2, int y2) {
  return std::max(0, std::min(y, y2) - std::max(x, x2));
}

int main() {
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++) {
    int a, l;
    std::cin >> a >> l;
    v[2 * i - 1] = {a - l, a, i};
    v[2 * i] = {a, a + l, i};
  }
  std::sort(v + 1, v + 2 * n + 1);
  
  for(int i = 1; i <= 2 * n; i++) {
    dp[0][i] = v[i].y - v[i].x;
    for(int j = 1;j < i; j++) {
      if(v[i].id != v[j].id && v[j].x < v[i].x && v[j].y < v[i].y) {
        dp[j][i] = dp[0][j] + v[i].y - v[i].x - intersect(v[i].x, v[i].y, v[j].x, v[j].y);
        for(int h = 1; h < j; h++) {
          if(v[h].y < v[i].x)
            dp[j][i] = std::max(dp[j][i], dp[h][j] + v[i].y - v[i].x - intersect(v[i].x, v[i].y, v[j].x, v[j].y));
        }
      }
    }
  }
  int result = 0;
  for(int i = 0; i <= 2 * n; i++)
    for(int j = i + 1; j <= 2 * n; j++)
      result = std::max(result, dp[i][j]);
  std::cout << result;
  return 0;
}