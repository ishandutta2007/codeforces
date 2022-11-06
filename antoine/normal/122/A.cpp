#include <iostream>

bool isLucky(int n) {
	for(;;) {
		int digit = n % 10;
		if(digit != 4 && digit != 7)
			return false;
		
		n /= 10;
		if(n == 0)
			return true;
	}
}

bool isAlmost(int n) {
	for(int d = 4; d <= n; ++d)
		if(n % d == 0 && isLucky(d))
			return true;
	return false;
}

int main() {
	int n;
	std::cin >> n;
	if(isAlmost(n))
		std::cout << "YES";
	else
		std::cout << "NO";
}