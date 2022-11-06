#include <iostream>
#include <algorithm>
#include <string>

int n;
int a[100];

int best(int i) {
	int count[] = { 0, 0 };
	int ans = -999;
	for (int j = i; j < n; ++j) {
		++count[a[j]];
		ans = std::max(ans, count[0] - count[1]);
	}
	return ans;
}

int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];

	int change = -999;
	int count[] = { 0, 0 };
	for (int i = 0; i < n; ++i) {
		change = std::max(change, best(i));
		++count[a[i]];
	}
	std::cout << count[1] + change;
	return 0;
}