#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

int n;
int a[2][100];
int b[100];

int main() {
	std::cin >> n;
	for (int i = 0; i < 2; ++i)
	for (int j = 0; j < n - 1; ++j)
		std::cin >> a[i][j];
	for (int j = 0; j < n; ++j)
		std::cin >> b[j];

	int ans = -1;
	for (int c1 = 0; c1 < n; ++c1)
	for (int c2 = c1 + 1; c2 < n; ++c2) {
		int sum = 0;
		for (int i = 0; i < c1; ++i)
			sum += a[0][i];
		sum += b[c1];
		for (int i = c1; i < n - 1; ++i)
			sum += a[1][i];

		for (int i = c2; i < n - 1; ++i)
			sum += a[1][i];
		sum += b[c2];
		for (int i = 0; i < c2; ++i)
			sum += a[0][i];
		if (ans == -1 || ans > sum)
			ans = sum;
	}
	std::cout << ans;
	return 0;
}