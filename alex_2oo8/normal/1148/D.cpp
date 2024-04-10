#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	ignore = scanf("%d", &n);
	
	vector<pair<int, int>> inc, dec;
	for (int i = 0, a, b; i < n; i++) {
		ignore = scanf("%d %d", &a, &b);
		if (a < b) inc.emplace_back(-1 * b, i + 1);
		else dec.emplace_back(b, i + 1);
	}
	
	if (inc.size() < dec.size()) swap(inc, dec);
	sort(inc.begin(), inc.end());
	
	printf("%d\n", (int)inc.size());
	for (auto& p : inc) printf("%d ", p.second);
	printf("\n");
	
	return 0;
}