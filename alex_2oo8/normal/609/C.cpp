#include<bits/stdc++.h>

using namespace std;

int a[100000];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	
	sort(a, a + n);
	
	int sum = 0;
	for (int i = 0; i < n; i++) sum += a[i];
	
	int ans = 0, f = sum / n;
	for (int i = 0; i < n && a[i] <= f; i++) {
		ans += f - a[i];
		
		if (sum % n == n - 1 - i) f++;
	}
	
	printf("%d\n", ans);
	
	return 0;
}