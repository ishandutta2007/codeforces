#include <iostream>

#define MOD 1000000007
#define int long long

long long power(long long x, long long p) {
	long long res = 1;

	while(x < 0)
		x += MOD;

	while(p > 0) {
		if(p & 1)
			res = (res*x)%MOD;

		x = (x*x)%MOD;
		p >>= 1;
	}

	return res;
}

signed main() {
	int n, m;
	std::cin >> n >> m;

	int t = power(2, m);
	t = (t + MOD - 1)%MOD;
	std::cout << power(t, n) << std::endl;

	return 0;
}