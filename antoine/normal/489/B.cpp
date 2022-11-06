#include <iostream>
#include <algorithm>
#include <string>

int n, m;
int a[100];
int b[100];

int DP(int i = 0, int j = 0) {
	if (i == n || j == m)
		return 0;
	
	if (std::abs(a[i] - b[j]) <= 1)
		return 1 + DP(i + 1, j + 1);
	if (a[i] < b[j])
		return DP(i + 1, j);
	return DP(i, j + 1);
}

int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];
	std::cin >> m;
	for (int i = 0; i < m; ++i)
		std::cin >> b[i];

	std::sort(a, a + n);
	std::sort(b, b + m);
	std::cout << DP();
}