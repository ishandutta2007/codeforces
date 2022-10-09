#include <iostream>
#include <vector>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const modulo = 1000000007;
int const nmax = 20;

int lgpow(int a, int b) {
  if(b == 0)
    return 1;
  else if(b == 1)
    return a;
  else {
    int result = lgpow(a, b / 2);
    if(b % 2 == 0)
      return 1LL * result * result % modulo;
    else
      return 1LL * result * result % modulo * a % modulo;
  }
}
int dp[1 << nmax], dp2[1 << nmax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;

  for(int mask = 0; mask < (1 << n); mask++) {
    int val;
    val = s[mask] - '0';
    if(val == 0)
      dp[mask]++;
    else
      dp2[mask]++;
  }

  for(int i = 0; i < n; i++) {
    for(int mask = 0; mask < (1 << n); mask++) {
      if(0 < (mask & (1 << i))) {
        int mask2 = mask ^ (1 << i);
        int a = dp[mask], b = dp[mask2];
        dp[mask] = (a + 1LL * b * 2) % modulo;
        dp[mask2] = (b + 1LL * a * 2) % modulo;
      }
    }
  }


  int result = 0;
  for(int mask = 0; mask < (1 << n); mask++) {
    result += 1LL * dp[mask] * dp2[mask] % modulo;
    if(modulo <= result)
      result -= modulo;
  }
  std::cout << 1LL * result * 3 % modulo;
  return 0;
}