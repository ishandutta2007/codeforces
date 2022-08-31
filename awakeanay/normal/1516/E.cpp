#include <iostream>
#include <vector>

#define int long long

const int MAXA = 405;
const int MAXB = 205;
const int MAXC = 505;
const int MOD = 1000000007;

int n;

int binom[MAXA][MAXA];
int dp[MAXA][MAXB];

int expo(int x, int p) {
  int ret = 1;
  while(p > 0) {
    if(p&1)
      ret = (ret*x)%MOD;

    p >>= 1;
    x = (x*x)%MOD;
  }
  return ret;
}

int inv(int x) {
  return expo(x, MOD-2);
}

int fact[MAXC];
int rfact[MAXC];
int ifm[MAXC];
int choice[MAXA][MAXA];

int choose(int n, int j) {
  return (rfact[j]*ifm[j])%MOD;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cin >> n;

  for(int i = 0; i < MAXA; i++)
    choice[i][0] = choice[i][i] = 1;
  for(int i = 1; i < MAXA; i++)
    for(int j = 1; j < i; j++)
      choice[i][j] = (choice[i-1][j] + choice[i-1][j-1])%MOD;

  fact[0] = ifm[0] = 1;
  for(int i = 1; i < MAXC; i++) {
    fact[i] = (fact[i-1]*i)%MOD;
    ifm[i] = inv(fact[i]);
  }

  dp[0][0] = 1;
  for(int i = 2; i < MAXA; i++) {
    for(int j = 1; j < i; j++) {
      for(int k = 1; k <= j; k++) {
        dp[i][j] += ((choice[i-1][k]*dp[i-k-1][j-k])%MOD)*fact[k];
        dp[i][j] %= MOD;
      }
    }
  }

  int k;
  std::cin >> k;

  rfact[0] = 1;
  for(int i = 1; i <= MAXC; i++) {
    rfact[i] = (rfact[i-1]*(n-i+1))%MOD;
  }

  std::vector<int> sum(k+1, 0);
  sum[0] = 1;

  for(int i = 1; i <= k; i++) {
    for(int j = 1; j <= 2*i; j++) {
      sum[i] += choose(n, j)*dp[j][i];
      sum[i] %= MOD;
    }
    if(i-2 >= 0) {
      sum[i] += sum[i-2];
      sum[i] %= MOD;
    }
    std::cout << sum[i] << " ";
  }

  std::cout << std::endl;

  return 0;
}