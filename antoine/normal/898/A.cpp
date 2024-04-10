#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <array>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	std::cin >> n;
	if (n % 10 <= 4)
		n -= (n % 10);
	else {
		n /= 10;
		++n;
		n *= 10;
	}
	std::cout << n;
	return 0;
}