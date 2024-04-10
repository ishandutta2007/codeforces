#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int const kmax = 20;

int v[1 + nmax];
int dp[1 + (1 << kmax)][1 + kmax];

int getcost(int a, int b, int k) {
  for(int i = k; 0 <= i; i--)
    if((a>>(k - i)) == (b & ((1 << i) - 1)))
      return k - i;
  return k;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  int k;
  for(int i = 1;i <= n; i++) {
    std::string s;
    std::cin >> s;
    k = s.size();
    for(int j = 0; j < k; j++)
      v[i] |= ((s[j] - '0')<<j);
  }
  
  for(int i = 0; i < (1 << k); i++)
    for(int j = 0; j <= k; j++)
      dp[i][j] = nmax * kmax;
  
  int base = k;
  dp[0][0] = 0;
  
  for(int i = 2; i <= n; i++) {
    int aux = getcost(v[i - 1], v[i], k);
    int result = nmax * kmax;
    for(int j = 0; j <= k; j++)
      result = std::min(result, base + dp[(v[i] & ((1 << j) - 1))][j] + k - j);

    for(int j = 0; j <= k; j++)
      dp[v[i - 1]>>(k - j)][j] = std::min(dp[v[i - 1]>>(k - j)][j], result - base - aux);
    base += aux;
  }
  std::cout << dp[0][0] + base;
  return 0;
}