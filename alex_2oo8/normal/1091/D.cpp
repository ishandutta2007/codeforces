#include <bits/stdc++.h>

using namespace std;

const int MX = 1000001, md = 998244353;

int main() {
	int n;
	ignore = scanf("%d", &n);
	
	int f = 1;
	for (int i = 1; i <= n; i++) f = f * 1ll * i % md;
	
	int ans = f * 1ll * n % md;
	
	f = 1;
	for (int i = n; i > 1; i--) {
		f = f * 1ll * i % md;
		ans = (ans + md - f) % md;
	}
	
	printf("%d\n", ans);
	
	return 0;
}