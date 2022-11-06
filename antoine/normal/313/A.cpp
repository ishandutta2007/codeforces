

#include <iostream>

int max(int a, int b) {
	return a > b ? a : b;
}
int get() {
	int n;
	std::cin >> n;
	if(n > 0)
		return n;
	
	n *= -1;
	int a = n/10;
	int b = n/100;
	b = b*10 + n%10;
	return max(-a, -b);
}

int main() {
	std::cout << get();
}