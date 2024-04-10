#include <iostream>
#include <vector>

#define int long long

signed main() {
	int n;
	std::cin >> n;

	int coef[3];
	for(int j = 0; j < 3; j++)
		std::cin >> coef[j];

	int a[n];
	for(int i = 0; i < n; i++)
		std::cin >> a[i];

	std::vector<int> last(n, 0);
	for(int j = 2; j >= 0; j--) {
		for(int i = n-1; i >= 0; i--) {
			last[i] = coef[j]*a[i] + last[i];
			if(i + 1 < n) last[i] = std::max(last[i], last[i+1]);
		}
	}

	std::cout << last[0] << std::endl;
	return 0;
}