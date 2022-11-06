

#include <iostream>

int pow(int n, int p) {
	if(p == 0)
		return 1;
	if(p%2 == 1)
		return (n*pow(n, p-1))%10;
	return (pow((n*n)%10, p/2))%10;
}

int main() {
	int n;
	std::cin >> n;
	std::cout << pow(8, n);
}