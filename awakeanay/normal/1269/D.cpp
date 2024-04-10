#include <iostream>

#define int long long

signed main() {
	int n;
	std::cin >> n;

	int seq[n];
	for(int i = 0; i < n; i++)
		std::cin >> seq[i];

	int a = 0, b = 0;
	for(int i = 0; i < n; i++) {
		if(i%2) {
			a += seq[i]/2;;
			b += seq[i] - seq[i]/2;
		} else {
			b += seq[i]/2;;
			a += seq[i] - seq[i]/2;
		}
	}

	std::cout << std::min(a, b);

	return 0;
}