#include <bits/stdc++.h>

using namespace std;

const int md = 998244353;

int main() {
	int n, m, ans = 1;
	ignore = scanf("%d %d", &n, &m);
	for (int i = 0; i < n + m; i++) ans = ans * 2 % md;
	
	printf("%d\n", ans);
	
	return 0;
}