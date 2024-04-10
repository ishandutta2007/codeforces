#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int Mod = 1e9 + 7;

int add(int a, int b) {
	return ((a += b) >= Mod) ? (a - Mod) : (a);
}

const int N = 1e6 + 3, bzmax = 22;

bitset<N> vis;
int f[N][bzmax];
int pri[N], ls[N], mt[N];

void Euler() {
	vis.reset();
	int num = 0;
	for (int i = 2; i < N; i++) {
		if (!vis.test(i)) {
			pri[num++] = i, ls[i] = 1, mt[i] = 1;
		}
		for (int j = 0, x; j < num && (x = pri[j] * i) < N; j++) {
			vis.set(x);
			if (!(i % pri[j])) {
				ls[x] = ls[i], mt[x] = mt[i] + 1;
				break;
			} else {
				ls[x] = i, mt[x] = 1;
			}
		}
	}
}

void prepare() {
	for (int i = 0; i < bzmax; i++) {
		f[0][i] = (i != 0) + 1;
	}
	for (int i = 1; i <= 1000000; i++) {
		int sum = 0;
		for (int j = 0; j < bzmax; j++) {
			sum = add(sum, f[i - 1][j]);
			f[i][j] = sum;
		}
	}
}

int Q, r, n;
int main() {
	Euler();
	prepare();
	scanf("%d", &Q);
	while (Q--) {
		scanf("%d%d", &r, &n);
		int ans = 1;
		while (n) {
			ans = 1ll * ans * f[r][mt[n]] % Mod;
			n = ls[n];
		}
		printf("%d\n", ans);
	}
	return 0;
}