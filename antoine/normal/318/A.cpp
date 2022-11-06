
#include <iostream>
#include <algorithm>
#include <cstring>

int main() {
	long long n, k;
	
	std::cin >> n >> k;
	
	if(k <= (n+1)/2) {
		std::cout << 1 + (k-1)*2 << "\n";
	} else {
		k -= (n+1)/2;
		std::cout << 2*k << "\n";
	}
	
	return 0;
}