#include <bits/stdc++.h>

using namespace std;

const int MX = 1000;

int a[MX];

int main() {
	int n, h;
	ignore = scanf("%d %d", &n, &h);
	for (int i = 0; i < n; i++) ignore = scanf("%d", a + i);
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int j = i;
		while (j > 0 && a[j] > a[j - 1]) {
			swap(a[j], a[j - 1]);
			j--;
		}
		
		long long S = 0;
		for (int k = 0; k <= i; k += 2) S += a[k];
		
		if (S > h) break;
		ans++;
	}
	
	printf("%d\n", ans);
	
	return 0;
}