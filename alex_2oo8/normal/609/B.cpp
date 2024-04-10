#include<bits/stdc++.h>

using namespace std;

int a[10];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		
		a[x - 1] += 1;
	}
	
	long long ans = n * 1ll * (n - 1) / 2;
	for (int i = 0; i < m; i++) ans -= a[i] * 1ll * (a[i] - 1) / 2;
	
	printf("%d\n", (int)(ans));
	
	return 0;
}