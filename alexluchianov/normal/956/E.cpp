#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <algorithm>

using ll = long long;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 10000;
std::pair<int,int> v[1 + nmax];

bool compare(std::pair<int,int> f1, std::pair<int, int> f2) {
  if(f1.second != f2.second)
    return f1.second < f2.second;
  else 
    return f1.first > f2.first;
}

int dp[1 + nmax], dp2[1 + nmax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, l, r;
  std::cin >> n >> l >> r;
  int allsum = 0;

  for(int i = 1;i <= n; i++) {
    std::cin >> v[i].first;
    allsum += v[i].first;
  }
  r = std::min(r, allsum);
  if(r < l) {
    std::cout << 0;
    return 0;
  }

  for(int i = 1;i <= n; i++)
    std::cin >> v[i].second;

  std::sort(v + 1, v + n + 1, compare);
  for(int i = 0;i <= nmax; i++)
    dp2[i] = -nmax;
  for(int i = 0; i <= nmax; i++)
    dp[i] = -nmax;
  dp[0] = 0;
  
  int sum = 0;
  for(int i = 1; i <= n; i++){
    for(int j = 0; j <= sum; j++) {  
      int oth = sum - j;
      dp2[j + v[i].first] = std::max(dp2[j + v[i].first], dp[j] + (v[i].second & (l <= j && j <= r)));
      dp2[j] = std::max(dp2[j], dp[j] + (v[i].second & (l <= allsum - oth - v[i].first && allsum - oth - v[i].first <= r)));
    }
    sum += v[i].first;
    for(int j = 0; j <= sum; j++) {
      dp[j] = dp2[j];
      dp2[j] = -nmax;
    }
  }

  int result = 0;
  for(int i = 0; i <= sum; i++)
    result = std::max(result, dp[i]);
  std::cout << result;
  return 0;
}