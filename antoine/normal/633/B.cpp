#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

int noOfZ(int n) {
	int count = 0;
	do {
		n /= 5;
		count += n;
	} while (n);
	return count;
}

// find the first number that has m zeros in its factorial
int find(int m) {
	int lo = 0;
	int hi = 5 * m;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (noOfZ(mid) >= m)
			hi = mid;
		else
			lo = mid + 1;
	}
	return lo;
}

int main() {
	int m;
	std::cin >> m;
	int min = find(m);
	int max = find(m + 1);
	std::cout << (max - min) << "\n";
	if (min < max)
		std::cout << min;
	for (int i = min+1; i < max; ++i)
		std::cout << " " << i;
	return 0;
}