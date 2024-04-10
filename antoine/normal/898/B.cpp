#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <array>

using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, a, b;
	cin >> n >> a >> b;

	for (int i = 0;; ++i) {
		if (a*i > n) {
			std::cout << "NO";
			return 0;
		}
		int rest = n - a*i;
		if (rest%b != 0)
			continue;
		int j = rest / b;
		std::cout << "YES\n";
		std::cout << i << ' ' << j;
		return 0;
	}
	return 0;
}