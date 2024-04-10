#include <cstdio>
#include <algorithm>
int n, Mod = 998244353, w[40] = { 1,2,4,5 };
long long S[1010000], D[1010][2];
int main() {
	int i, j;
/*	for (i = 1; i <= 1000000; i++) {
		S[i] = S[i / 2] + S[(i - 1) / 2] + (i - 1);
	}
	D[0][0] = 1;
	for (i = 1; i <= 1000; i++) {
		for (j = 0; j < i; j++) {
			if (S[i] == S[j] + S[i - j - 1] + i - 1) {
				if (j % 2 == 1) {
					D[i][0] = (D[i][0] + D[j][1] * D[i - j - 1][0]) % Mod;
				}
				else {
					D[i][1] = (D[i][1] + D[j][0] * D[i - j - 1][0]) % Mod;
				}
			}
		}
		if(D[i][0]+D[i][1])printf("%d : %lld %lld\n", i, D[i][0], D[i][1]);
	}*/
	int T;
	for (i = 4;; i += 4) {
		w[i] = w[i - 1] * 2 - 1;
		w[i + 1] = w[i] + 1;
		w[i + 2] = w[i + 1] * 2;
		w[i + 3] = w[i + 2] + 1;
		if (w[i + 3] > 1e6)break;
	}
	T = i + 3;
	scanf("%d", &n);
	for (i = 0; i <= T; i++) {
		if (w[i] == n) {
			puts("1");
			return 0;
		}
	}
	puts("0");
}