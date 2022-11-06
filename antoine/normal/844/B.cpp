#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <string>

int whiteInRow[60] = { 0 };
int blackInRow[60] = { 0 };
int whiteInCol[60] = { 0 };
int blackInCol[60] = { 0 };

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			int x;
			std::cin >> x;
			if (x) {
				++whiteInRow[i];
				++whiteInCol[j];
			}
			else {
				++blackInRow[i];
				++blackInCol[j];
			}
		}

	long long ans = n*m;
	for (int i = 0; i < n; ++i) {
		if (whiteInRow[i] > 1)
			ans += (1LL << whiteInRow[i]) - whiteInRow[i] - 1;
		if (blackInRow[i] > 1)
			ans += (1LL << blackInRow[i]) - blackInRow[i] - 1;
	}
	for (int i = 0; i < m; ++i) {
		if (whiteInCol[i] > 1)
			ans += (1LL << whiteInCol[i]) - whiteInCol[i] - 1;
		if (blackInCol[i] > 1)
			ans += (1LL << blackInCol[i]) - blackInCol[i] - 1;
	}
	std::cout << ans << '\n';
	return 0;
}