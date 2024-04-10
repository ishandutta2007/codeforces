#include <bits/stdc++.h>

const int N = 105;

int n;
char a[N];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> (a + 1);
	n = strlen(a + 1);
	int r = (n + 20 - 1) / 20, c = (n + r - 1) / r;
	std::cout << r << " " << c << "\n";
	int t = r * c - n, idx = 0;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (j < t / r || (j == t / r && i < t % r)) {
				std::cout << "*";
			} else {
				std::cout << a[++idx];
			}
		}
		std::cout << "\n";
	}
}