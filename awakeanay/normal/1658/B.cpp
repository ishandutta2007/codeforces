#include <iostream>

#define int long long

const int MOD = 998244353;
const int MAXN = 1005;

int fact[MAXN];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  fact[0] = 1;
  for(int i = 1; i < MAXN; i++)
    fact[i] = (fact[i-1]*i)%MOD;

  while(t--) {
    int n;
    std::cin >> n;

    int ans = 1;
    if(n%2)
      std::cout << 0 << std::endl;
    else {
      std::cout << (fact[n/2]*fact[n/2])%MOD << std::endl;
    }
  }

  return 0;
}