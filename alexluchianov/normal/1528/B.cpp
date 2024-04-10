#include <iostream>
#include <vector>

using ll = long long;

int const nmax = 1000000;
int const modulo = 998244353;

int dp[1 + nmax], sum[1 + nmax];
int counter[1 + nmax];

int main() {
  ll n;
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    for(int j = i; j <= n; j += i)
      counter[j]++;

  for(int i = 1;i <= n; i++) {
    dp[i] = sum[i - 1];
    dp[i] += counter[i]; 
    if(modulo <= dp[i])
      dp[i] -= modulo;

    sum[i] = sum[i - 1] + dp[i];
    if(modulo <= sum[i])
      sum[i] -= modulo;
  }
  std::cout << dp[n];
  return 0;
}