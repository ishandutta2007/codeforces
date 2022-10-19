#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int f[MAXN];
int pref[MAXN][3];
int phi[MAXN];

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
	else if (x < 0)
		x += MOD;
	return x;
}

inline int mul(int x, int y) {
	return (ll)x * y % MOD;
}

void init() {
	for (int i = 1; i < MAXN; i++)
		phi[i] = i;
	for (int i = 1; i < MAXN; i++)
		for (int j = 2 * i; j < MAXN; j += i)
			phi[j] -= phi[i];
	
	for (int i = 1; i < MAXN; i++)
		for (int j = i; j < MAXN; j += i)
			f[j] = add(f[j], mul(2 * i, phi[j / i]));
			
	for (int i = 1; i < MAXN; i++) {
		f[i] = add(f[i], (ll)i * ((ll)2 * i * i - 6 * i + 1) / 3 % MOD);
		pref[i][0] = add(pref[i - 1][0], f[i]);
		pref[i][1] = add(pref[i - 1][1], mul(i, f[i]));
		pref[i][2] = add(pref[i - 1][2], mul(mul(i, i), f[i]));
	}
}

int solve(int n, int m) {
	if (n > m)
		swap(n, m);
	return add(add(mul(mul(n + 1, m + 1), pref[n][0]), -mul(pref[n][1], n + m + 2)), pref[n][2]); 
}

int main() {
	init();
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		printf("%d\n", solve(n, m));
	}
	return 0;
}