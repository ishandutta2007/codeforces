#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <limits.h>
#include <queue>
using namespace std;
int main() {
	long long int n, m;
	std::cin >> n;
	std::cin >> m;
	if (n > 26) {
		std::cout << m << std::endl;
		return 0;
	}
	long long int x = 1;
	while (n > 0) {
		x *= 2;
		n--;
	}
	if (m >= x) {
		while (m >= x) {
			m -= x;
		}
	}
	std::cout << m << std::endl;
	return 0;
}