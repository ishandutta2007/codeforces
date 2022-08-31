#include <iostream>
#include <iomanip>

#define int long long

const int MAXM = 600;
const long double ONE = 1.0000000000000000000000000;
const long double TWO = 2.0000000000000000000000000;
const long double ZERO = 0.0000000000000000000000000;

long double dp[MAXM];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, k;
  std::cin >> n >> k;

  long double kld = k;
  for(int i = 0; i < MAXM; i++)
    dp[i] = ZERO;

  for(int i = 0; i < n; i++) {
    for(int j = 1; j < MAXM; j++) {
      long double jld = j;
      long double next = (j+1 < MAXM ? dp[j+1] : ZERO);
      dp[j] = ((kld-ONE)/kld)*dp[j] + ((ONE/(jld+ONE))*(next + jld) + (jld/(jld+ONE))*(dp[j] + (jld+ONE)/TWO))/kld;
    }
  }

  long double ans = dp[1]*kld;

  std::cout << std::fixed << std::setprecision(15) << ans << std::endl;

  return 0;
}