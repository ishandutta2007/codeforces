#include <iostream>
#include <vector>

#define int long long 

int MOD;

long long power(long long x, long long p) {
	long long res = 1;

	while(p > 0) {
		if(p & 1)
			res = (res*x)%MOD;

		x = (x*x)%MOD;
		p >>= 1;
	}

	return res;
}

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int d;
    std::cin >> d >> MOD;

    int exp[40];
    exp[0] = 1;
    for(int i = 1; i < 40; i++)
      exp[i] = exp[i-1]*2;

    std::vector<int> c;
    for(int i = 0; i < 40; i++) {
      c.push_back(std::min(d, exp[i+1] - 1) - exp[i] + 1);
      if(exp[i+1]-1 >= d)
        break;
    }

    int ans = 1;
    for(int i = 0; i < c.size(); i++) {
      ans *= (c[i] + 1);
      ans %= MOD;
    }

    ans += MOD - 1;
    ans %= MOD;

    std::cout << ans << std::endl;
  }

  return 0;
}