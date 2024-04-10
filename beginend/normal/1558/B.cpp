#include<bits/stdc++.h>
using namespace std;

const int N = 8000005;

int n, MOD, f[N];

int main() {
	scanf("%d%d", &n, &MOD);
	f[n] = 1;
	for (int i = n - 1; i >= 1; i--) {
		f[i] = f[i + 1];
		for (int j = 2; i * j <= n; j++) {
			(f[i] += f[i * j]) %= MOD;
			(f[i] -= f[(i + 1) * j]) %= MOD;
		}
		(f[i] += f[i + 1]) %= MOD;
	}
	printf("%d\n", ((f[1] - f[2]) % MOD + MOD) % MOD);
	return 0;
}