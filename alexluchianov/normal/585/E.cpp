#pragma GCC optimize("O3")
#pragma GCC optimization ("unroll-loops")

#include <iostream>
#include <vector>

using ll = long long;

int const nmax = 500000;
int const valmax = 10000000;
int const modulo = 1000000007;

int v[1 + nmax], pow2[1 + nmax];
int frec[1 + valmax], frec2[1 + valmax], dp[1 + valmax];

void precompute() {
  pow2[0] = 1;
  for(int i = 1; i <= nmax; i++)
    pow2[i] = pow2[i - 1] * 2 % modulo;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  precompute();
  
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++) {
    std::cin >> v[i];
    frec[v[i]]++;
  }
  for(int i = valmax; 1 <= i; i--) {
    int acc = 0;
    for(int j = i; j <= valmax; j += i) {
      acc += frec[j];
      frec2[i] -= frec2[j];
      if(frec2[i] < 0)
        frec2[i] += modulo;
    }
    frec2[i] += (pow2[acc] - 1);
    if(modulo <= frec2[i])
      frec2[i] -= modulo;
  }
  frec2[1] = 0;
  for(int i = valmax; 1 <= i; i--) {
    int acc1 = 0, acc2 = 0;
    for(int j = i; j <= valmax; j += i) {
      acc1 += frec[j];
      acc2 += frec2[j];
      if(modulo <= acc2)
        acc2 -= modulo;
      dp[i] -= dp[j];
      if(dp[i] < 0)
        dp[i] += modulo;
    }
    dp[i] += 1LL * acc1 * acc2 % modulo;
    if(modulo <= dp[i])
      dp[i] -= modulo;
  }
  std::cout << dp[1] << '\n';
  return 0;
}