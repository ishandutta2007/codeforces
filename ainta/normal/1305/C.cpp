#include<cstdio>
#include<algorithm>
#include<vector>
#include<random>
#include<ctime>
#include<iostream>
#include<cassert>
using namespace std;
int n, Mod, C[1010], w[201000];
void Solve() {
	int i, a, j;
	scanf("%d%d", &n, &Mod);
	for (i = 0; i < n; i++) {
		scanf("%d", &w[i]);
	}
	sort(w, w + n);
	int res = 1;
	for (i = 0; i < n; i++) {
		int a = w[i] % Mod;
		if (C[a]) {
			puts("0");
			return;
		}
		for (j = 0; j < a; j++) {
			if (C[j])res = res * (a - j) % Mod;
		}
		for (j = a + 1; j < Mod; j++) {
			if (C[j])res = res * (a - j + Mod) % Mod;
		}
		C[a]++;
	}
	printf("%d\n", res);
}
int main() {
	int TC = 1;
	while (TC--) {
		Solve();
	}
}