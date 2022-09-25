#include <bits/stdc++.h>

using namespace std;

const int MX = 300000;

int p[MX];

int main() {
	int n;
	ignore = scanf("%d", &n);
	for (int i = 0; i < n; i++) ignore = scanf("%d", p + i);
	
	vector<pair<int, int>> vec;
	for (int i = 0; i < n;) {
		if (p[i] == i + 1) {
			i++;
			continue;
		}
		
		int x = i + 1;
		int y = p[i];
		if (x > y) swap(x, y);
		
		if (2 * abs(x - y) >= n) vec.emplace_back(x, y);
		else if (2 * (y - 1) < n) {
			vec.emplace_back(x, n);
			vec.emplace_back(y, n);
			vec.emplace_back(x, n);
		}
		else if (2 * (n - x) < n) {
			vec.emplace_back(x, 1);
			vec.emplace_back(y, 1);
			vec.emplace_back(x, 1);
		}
		else {
			vec.emplace_back(x, n);
			vec.emplace_back(1, y);
			vec.emplace_back(1, n);
			vec.emplace_back(1, y);
			vec.emplace_back(x, n);
		}
		
		swap(p[x - 1], p[y - 1]);
	}
	
	printf("%d\n", (int)vec.size());
	for (auto p : vec) {
		int x, y;
		tie(x, y) = p;
		printf("%d %d\n", x, y);
	}
	
	return 0;
}