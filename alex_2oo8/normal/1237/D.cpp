#include <bits/stdc++.h>

using namespace std;

const int MX = 500000;

int a[MX + 1], f[MX];

int main() {
	int n;
	ignore = scanf("%d", &n);
	for (int i = 0; i < n; i++) ignore = scanf("%d", a + i);
	
	int mx = *max_element(a, a + n);
	int mn = *min_element(a, a + n);
	
	if (2 * mn >= mx) {
		for (int i = 0; i < n; i++) printf("-1 ");
		printf("\n");
		return 0;
	}
	
	a[5 * n] = -1;
	for (int i = 0; i < n; i++) a[n + i] = a[i];
	
	vector<int> stack = {5 * n};
	for (int i = 2 * n - 1; i >= 0; i--) {
		if (i < n) {
			int k = stack.size();
			for (int p = (1 << 20); p > 0; p /= 2)
				if (k - p >= 0 && 2 * a[stack[k - p]] >= a[i])
					k -= p;
			
			f[i] = stack[k - 1] - i;
		}
		
		while (a[i] <= a[stack.back()]) stack.pop_back();
		stack.push_back(i);
	}
	
	set<pair<int, int>> S;
	for (int i = 0; i < n; i++) S.emplace(f[i], i);
	
	while (S.empty() == false) {
		int i = S.begin()->second;
		S.erase(S.begin());
		
		int j = (i + n - 1) % n;
		if (f[j] > f[i] + 1) {
			S.erase(make_pair(f[j], j));
			f[j] = f[i] + 1;
			S.emplace(f[j], j);
		}
	}
	
	for (int i = 0; i < n; i++) printf("%d ", f[i]);
	printf("\n");
	
	return 0;
}