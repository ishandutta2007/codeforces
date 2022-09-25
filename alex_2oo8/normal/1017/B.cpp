#include <bits/stdc++.h>

using namespace std;

const int MX = 100000;

char s[MX + 1], t[MX + 1];

int main() {
	int n;
	ignore = scanf("%d %s %s", &n, s, t);
	
	int o = 0, z = 0, a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		(s[i] == '0' ? a : b)++;
		if (t[i] == '1')
			(s[i] == '0' ? z : o)++;
	}
	
	printf("%lld\n", a * 1ll * b - z * 1ll * o);
	
	return 0;
}