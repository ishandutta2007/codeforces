#include <bits/stdc++.h>

long long n, k;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n >> k;
	std::cout << (k - 1) / n + 1 << "\n";
}