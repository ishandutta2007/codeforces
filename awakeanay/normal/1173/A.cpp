#include <iostream>
using namespace std;

#define int long long

signed main() {
	int a, b, c;
	std::cin >> a >> b >> c;
	
	int k = a-b;
	if(abs(a-b) <= c && c)
		std::cout << "?";
	else if(a-b > 0)
		std::cout << "+";
	else if(a-b < 0)
		std::cout << "-";
	else std::cout << 0;
}