#include <bits/stdc++.h>

using namespace std;

const int MX = 1000;

int a[MX];

int main() {
	int n;
	ignore = scanf("%d", &n);
	for (int i = 0, x = 0; i < n; i++) {
		ignore = scanf("%d", a + i);
		a[i] -= x;
		x += a[i];
	}
	
	vector<int> ans;
	for (int k = 1; k <= n; k++) {
		bool ok = true;
		for (int i = 0; i + k < n && ok; i++) ok = a[i] == a[i + k];
		
		if (ok) ans.push_back(k);
	}
	
	printf("%d\n", (int)ans.size());
	for (int x : ans) printf("%d ", x);
	printf("\n");
	
	return 0;
}