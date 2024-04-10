#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int const nmax = 1000000;
int const modulo = 998244353;

int lgpow(int a, int b) {
  if(b == 0)
    return 1;
  else if(b == 1)
    return a;
  else {
    int result = lgpow(a, b / 2);
    if (b % 2 == 0)
      return 1LL * result * result % modulo;
    else
      return 1LL * result * result % modulo * a % modulo;
  }
}

class Mint{
public:
  int val;
  Mint(int _val = 0) {
    val = _val % modulo;
  }
  Mint(ll _val) {
    val = _val % modulo;
  }

  Mint operator + (Mint oth) {
    return val + oth.val;
  }
  Mint operator * (Mint oth) {
    return 1LL * val * oth.val;
  }
  Mint operator - (Mint oth) {
    return val - oth.val + modulo;
  }
  Mint operator / (Mint oth) {
    return 1LL * val * lgpow(oth.val, modulo - 2);
  }
};
Mint dp[1 + nmax], sum[1 + nmax];

int main() {
  int n;
  std::cin >> n;
  
  dp[0] = 1;
  sum[0] = 1;
  for(int i = 1;i <= n; i++) {
    dp[i] = dp[i - 1] * 2;
    if(2 <= i)
      dp[i] = dp[i] + dp[i - 1] * sum[i - 2];
    dp[i] = dp[i] + dp[i - 1] * (dp[i - 1] - 1) / 2;
    sum[i] = sum[i - 1] + dp[i];
  }

  /*
  for(int i = 0;i <= n; i++)
    std::cout << dp[i].val << " " << sum[i].val << '\n';
  */

  Mint result = (dp[n] - dp[n - 1]) * 2;
  Mint aux = 0;
  aux = aux + sum[n - 1] * (sum[n - 1] - 1) * (sum[n - 1] - 2) / 6;
  aux = aux + sum[n - 1] * (sum[n - 1] - 1);
  aux = aux + sum[n - 1];
  
  if(2 <= n) {
    aux = aux - sum[n - 2] * (sum[n - 2] - 1) * (sum[n - 2] - 2) / 6;
    aux = aux - sum[n - 2] * (sum[n - 2] - 1);
    aux = aux - sum[n - 2];
  }
  result = result + aux * 2;
  result = result + dp[n - 1];

  for(int i = 1; i <= n - 1; i++) {
    result = result + (dp[i] - dp[i - 1]) * dp[n - 1 - i];
  }

  std::cout << result.val;
  return 0;
}