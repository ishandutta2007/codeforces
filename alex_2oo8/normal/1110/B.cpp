#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, k;
	ignore = scanf("%d %d %d", &n, &m, &k);
	
	vector<int> vec;
	int p;
	ignore = scanf("%d", &p);
	for (int i = 1; i < n; i++) {
		int x;
		ignore = scanf("%d", &x);
		vec.push_back(x - p - 1);
		p = x;
	}
	
	sort(vec.begin(), vec.end());
	
	int ans = n;
	for (int i = 0; i < n - k; i++) ans += vec[i];
	
	printf("%d\n", ans);
	
	return 0;
}