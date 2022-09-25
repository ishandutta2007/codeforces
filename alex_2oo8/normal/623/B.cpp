#include<bits/stdc++.h>

using namespace std;

const int MX = 1000001;
const long long INF = 10000000000000000;

int n, a, b, x[MX];
long long g[MX];

long long h(int n, int d) {
	n %= d;
	
	if (n == 0) return 0;
	if (n == 1 || n == d - 1) return b;
	
	return INF;
}

long long solve(int d) {
	g[0] = 0;
	for (int i = 1; i <= n; i++) g[i] = min(g[i - 1] + h(x[i], d), INF);
	for (int i = 1; i <= n; i++) g[i] = min(g[i - 1], g[i] - a * 1ll * i);
	
	long long f = 0, ans = INF;
	for (int i = n; i > 0; i--) {
		ans = min(ans, g[i] + f + a * 1ll * i);
		
		f = min(f + h(x[i], d), INF);
	}
	
	return ans;
}

int main() {
	scanf("%d %d %d", &n, &a, &b);
	for (int i = 1; i <= n; i++) scanf("%d", x + i);
	
	long long ans = INF;
	
	int y[6] = {x[1] - 1, x[1], x[1] + 1, x[n] - 1, x[n], x[n] + 1};
	for (int z : y) {
		for (int i = 2; i * i <= z; i++)
			if (z % i == 0) {
				while (z % i == 0) z /= i;
				
				ans = min(solve(i), ans);
			}
		
		if (z != 1) ans = min(solve(z), ans);
	}
	
	printf("%lld\n", ans);
	
	return 0;
}