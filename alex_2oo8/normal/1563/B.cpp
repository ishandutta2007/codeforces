#include <bits/stdc++.h>

using namespace std;

const int MX = 4000000;

int f[MX + 1];
long long g[MX + 1];

int main() {
	int n, m;
	ignore = scanf("%d %d", &n, &m);
	
	f[1] = 1;
	for (int i = 2; i <= n; i++) {
		f[i] = (g[i] + f[i - 1] * 2 + 1) % m;
		if (f[i] < 0) f[i] += m;
		
		if (i == 2) f[i] = 2;
		
		for (int k = 2 * i; k <= n; k += i) {
			g[k] += f[i] - f[i - 1];
		}
	}
	
	printf("%d\n", f[n]);
	
	return 0;
}