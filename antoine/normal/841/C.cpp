#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <climits>
#include <string>
#include <map> 
#include <set>

// C
// http://codeforces.com/contest/841/problem/C

int m;
int a[200000];
std::pair<int, int> b[200000];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> m;
	for (int i = 0; i < m; ++i)
		std::cin >> a[i];

	for (int i = 0; i < m; ++i) {
		b[i].first = i;
		std::cin >> b[i].second;
	}

	std::sort(a, a + m, [](const int &l, const int &r) {
		return l > r;
	});

	std::sort(b, b + m, [](const std::pair<int, int> &l, const std::pair<int, int> &r) {
		return l.second < r.second;
	});

	for (int i = 0; i < m; ++i)
		b[i].second = a[i];

	std::sort(b, b + m);

	std::cout << b[0].second;
	for (int i = 1; i < m; ++i)
		std::cout << ' ' << b[i].second;
	return 0;
}