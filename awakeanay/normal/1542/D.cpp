#include <iostream>
#include <vector>

#define int long long

const int MOD = 998244353;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  int sum = 0;
  int a[n];
  for(int i = 0; i < n; i++) {
    a[i] = 0;
    char c;
    std::cin >> c;
    if(c == '+') {
      std::cin >> a[i];
      sum = (sum + a[i])%MOD;
    }
  }

  int p2[n+1];
  p2[0] = 1;
  for(int i = 1; i <= n; i++)
    p2[i] = (p2[i-1]*2)%MOD;

  int rem = 0;
  for(int i = 0; i < n; i++) {
    if(a[i] == 0)
      continue;
    std::vector<int> poss(n+1, 0);
    poss[0] = 1;

    for(int j = 0; j < i; j++) {
      if(a[j] == 0) {
        poss[0] = (2*poss[0]+poss[1])%MOD;
        for(int k = 1; k <= n; k++) {
          int nval = (poss[k] + ((k < n) ? poss[k+1] : 0))%MOD;
          poss[k] = nval;
        }
      }
      else if(a[j] <= a[i]) {
        for(int k = n; k >= 0; k--) {
          int nval = (poss[k] + ((k > 0) ? poss[k-1] : 0))%MOD;
          poss[k] = nval;
        }
      }
      else {
        for(int k = 0; k <= n; k++)
          poss[k] = (poss[k]*2)%MOD;
      }
    }

    for(int j = i+1; j < n; j++) {
      if(a[j] == 0) {
        int cur = poss[0]*a[i];
        cur %= MOD;
        cur = (cur*p2[n-1-j])%MOD;
        rem = (rem+cur)%MOD;
        poss[0] = (poss[0]+poss[1])%MOD;
        for(int k = 1; k <= n; k++) {
          int nval = (poss[k] + ((k < n) ? poss[k+1] : 0))%MOD;
          poss[k] = nval;
        }
      }
      else if(a[j] < a[i]) {
        for(int k = n; k >= 0; k--) {
          int nval = (poss[k] + ((k > 0) ? poss[k-1] : 0))%MOD;
          poss[k] = nval;
        }
      }
      else {
        for(int k = 0; k <= n; k++)
          poss[k] = (poss[k]*2)%MOD;
      }
    }
  }

  for(int i = 1; i < n; i++)
    sum = (sum*2)%MOD;

  std::cout << (sum-rem+MOD)%MOD << std::endl;

  return 0;
}