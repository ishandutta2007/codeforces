#include <iostream>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;
int const modulo = 1000000007;

int const lgmax = 20;

int dp[(1 << lgmax)];

int lgpow(int a, int b){
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

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for(int i = 1;i <= n; i++) {
    int a;
    cin >> a;
    dp[a]++;
  }
  for(int i = 0; i < lgmax; i++)
    for(int mask = (1 << lgmax) - 1; 0 <= mask; mask--)
      if(0 == (mask & (1 << i)))
        dp[mask] = dp[mask] + dp[mask + (1 << i)];

  int result = 0;
  for(int mask = 0; mask < (1 << lgmax); mask++) {
    result += 1LL * lgpow(2, dp[mask]) * lgpow(-1, __builtin_popcount(mask)) % modulo;
    if(modulo <= result)
      result -= modulo;
    if(result < 0)
      result += modulo;
  }
  cout << result;
  return 0;
}