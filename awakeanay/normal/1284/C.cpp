#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

signed main() {
	int n, m;
	std::cin >> n >> m;
	
  int fac[n+1];
  fac[0] = 1;
  for(int i = 1; i <= n; i++)
    fac[i] = (i*fac[i-1])%m;

	int ans = 0;
  for(int i = 1; i <= n; i++) {
    ans += (((fac[i]*fac[n-i])%m)*(n-i+1)%m)*(n-i+1)%m;
    ans %= m;
  }

  std::cout << ans << std::endl;
}