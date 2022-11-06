#include <iostream>
#include <algorithm>
#include <cstring>

int h, w;
char grid[500][501];
long long dp1[500][500];
long long dp2[500][500];

bool domino(char &a, char &b) {
	return a == '.' && b == '.';
}

long long f1(int i, int j) {
	if (i <= 0 || j < 0)
		return 0;
	if (dp1[i][j] != -1)
		return dp1[i][j];
	return dp1[i][j] = domino(grid[i][j], grid[i - 1][j]) + f1(i - 1, j) + f1(i, j - 1) - f1(i - 1, j - 1);
}


long long f2(int i, int j) {
	if (i < 0 || j <= 0)
		return 0;
	if (dp2[i][j] != -1)
		return dp2[i][j];
	return dp2[i][j] = domino(grid[i][j], grid[i][j - 1]) + f2(i - 1, j) + f2(i, j - 1) - f2(i - 1, j - 1);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::memset(dp1, -1, sizeof dp1);
	std::memset(dp2, -1, sizeof dp2);
	dp1[0][0] = dp2[0][0] = 0;
	
	std::cin >> h >> w;
	for (int i = 0; i < h; ++i)
		std::cin >> grid[i];
	int q;
	std::cin >> q;

	for (; q > 0; --q) {
		static int r1, r2, c1, c2;
		std::cin >> r1 >> c1 >> r2 >> c2;
		--r1; --c1; --r2; --c2;
		std::cout << f1(r2, c2) - f1(r2, c1 - 1) - f1(r1, c2) + f1(r1, c1 - 1) + f2(r2, c2) - f2(r1 - 1, c2) - f2(r2, c1) + f2(r1 - 1, c1) << '\n';
	}
	return 0;
}