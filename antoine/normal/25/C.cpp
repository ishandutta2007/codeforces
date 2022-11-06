#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>

int n;
long long d[300][300];

int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			std::cin >> d[i][j];

	long long S = 0;
	for (int i = 1; i < n; ++i)
		for (int j = 0; j < i; ++j)
			S += d[i][j];

	int k;
	std::cin >> k;
	for (; k > 0; --k) {
		int a, b;
		long long c;
		std::cin >> a >> b >> c;
		--a;
		--b;

		for(int i = 1; i < n; ++i)
			for (int j = 0; j < i; ++j) {
				long long dist = c + std::min(d[i][a] + d[b][j], d[i][b] + d[a][j]);
				long long diff = dist - d[i][j];
				if (diff < 0) {
					S += diff;
					d[i][j] = d[j][i] = dist;
				}
			}
		std::cout << S << " ";
	}
	return 0;
}