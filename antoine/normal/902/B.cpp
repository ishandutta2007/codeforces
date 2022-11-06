#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> c(n + 1), p(n + 1);

	for (int i = 2; i <= n; ++i)
		cin >> p[i];

	for (int i = 1; i <= n; ++i)
		cin >> c[i];

	int ans = 1;
	for (int i = 2; i <= n; ++i)
		ans += c[i] != c[p[i]];
	cout << ans;
	return 0;
}