#include <iostream>
#include <algorithm>

#define int long long

signed main() {
	int v;
	std::cin >> v;
	
	int a[10];
	int min = 10000000;
	for(int i = 1; i < 10; i++) {
		std::cin >> a[i];
		min = std::min(a[i], min);
	}
	
	int d = v/min;
	std::string s(d, '1');
	for(int i = 0; i < d; i++) {
		for(int j = 9; j > 0; j--) {
			if((v - a[j])/min == d-i-1 && v >= a[j]) {
				s[i] = '0'+j;
				v -= a[j];
				break;
			}
		}
	}
	
	if(d == 0) {
		std::cout << -1 << std::endl;
	}
	
	std::cout << s << std::endl;
	
	return 0;
}