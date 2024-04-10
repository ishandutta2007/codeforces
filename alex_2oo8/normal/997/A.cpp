#include <bits/stdc++.h>

using namespace std;

const int MX = 300000;

char s[MX + 1];

int main() {
	int n, x, y;
	ignore = scanf("%d %d %d %s", &n, &x, &y, s);
	
	int k = 0;
	for (int i = 0, z = 0; i <= n; i++)
		if (s[i] == '0') {
			if (z == 0) k++;
			z++;
		}
		else z = 0;
	
	long long ans;
	if (k == 0) ans = 0;
	else ans = y + (k - 1ll) * min(x, y);
	
	printf("%lld\n", ans);
	
	return 0;
}