#include <iostream>

#define MOD 1000000007
#define int long long

signed main() {
	int n;
	std::cin >> n;
	
	int f[1000000];
	f[0] = 1; f[1] = 2;
	for(int i = 2; i < 1000000; i++) {
		f[i] = f[i-1]+f[i-2];
		if(f[i] > n) {
			std::cout << i-1 << std::endl;
			return 0;
		}
	}
	
	return 0;
}