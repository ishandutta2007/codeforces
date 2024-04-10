#include <iostream>

#define int long long

const int MOD = 1000000007;

signed main() {
  std::ios::sync_with_stdio(false);
  
  int n, k, q;
  std::cin >> n >> k >> q;
  k++;

  int count[n][k];
  int cur = 0;
  int a[n];
  int sum[n];
  for(int i = 0; i < n; i++) {
    count[i][0] = 1;
  }

  for(int i = 1; i < k; i++) {
    for(int j = 0; j < n; j++) {
      count[j][i] = 0;
      if(j+1 < n) {
        count[j][i] += count[j+1][i-1];
        count[j][i] %= MOD;
      }
      if(j) {
        count[j][i] += count[j-1][i-1];
        count[j][i] %= MOD;
      }
    }
  }

  for(int i = 0; i < n; i++) {
    sum[i] = 0;
    for(int j = 0; j < k; j++) {
      sum[i] = (sum[i] + count[i][j]*count[i][k-1-j])%MOD;
    }
  }
        

  for(int i = 0; i < n; i++)
    std::cin >> a[i];

  for(int i = 0; i < n; i++) {
    cur = (cur + a[i]*sum[i])%MOD;
  }

  for(int j = 0; j < q; j++) {
    int i, v;
    std::cin >> i >> v;
    i--;
    int k = 0;
    if(v > a[i])
      k = (v-a[i])%MOD;
    else {
      int u = a[i] - v;
      u %= MOD;
      k = MOD - u;
      k %= MOD;
    }
    cur = (cur + (sum[i]*k)%MOD)%MOD;
    a[i] = v;
    std::cout << cur << std::endl;
  }

  return 0;
}