#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

int n;
int b[100000];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n;
	std::cin >> n;
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		int a;
		std::cin >> a;
		sum += a;
	}
	for (int i = 0; i < n; ++i) {
		std::cin >> b[i];
	}
	std::sort(b, b + n);
	int cap = n == 1 ? b[n - 1] : (b[n - 1] + b[n - 2]);
	if (sum <= cap)
		std::cout << "YES";
	else
		std::cout << "NO";

	return 0;
}