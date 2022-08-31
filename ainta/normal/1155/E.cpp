#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, TT[22];
long long Mod = 1000003, w[22][22], R[22], Ans[22], Z[22];
long long Pow(long long a, long long b) {
	long long r = 1;
	while (b) {
		if (b & 1)r = r * a%Mod;
		a = a * a%Mod; b >>= 1;
	}
	return r;
}
long long Inv(long long a) {
	return Pow(a, Mod - 2);
}

int main() {
	int i, j, k;
	for (i = 0; i < 20; i++) {
		printf("? %d\n", i);
		fflush(stdout);
		for (j = 0; j < 20; j++) {
			w[i][j] = Pow(i, j);
		}
		scanf("%lld", &R[i]);
		Z[i] = R[i];
	}
	int pv = 0;
	for (i = 0; i < 20; i++) {
		TT[i] = -1;
		for (j = pv; j < 20; j++) {
			if (w[j][i])break;
		}
		if (j == 20)continue;
		int tt = j;
		for (j = 0; j < 20; j++) {
			swap(w[pv][j], w[tt][j]);
		}
		swap(R[pv], R[tt]);
		TT[i] = pv;
		long long t = Inv(w[pv][i]);
		for (j = 0; j < 20; j++) {
			w[pv][j] = w[pv][j] * t%Mod;
		}
		R[pv] = R[pv] * t%Mod;
		for (j = pv + 1; j < 20; j++) {
			tt = w[j][i];
			for (k = 0; k < 20; k++) {
				w[j][k] = ((w[j][k] - tt * w[pv][k]) % Mod + Mod) % Mod;
			}
			R[j] = ((R[j] - tt * R[pv]) % Mod + Mod) % Mod;
		}
		pv++;
	}
	for (i = 19; i >= 0; i--) {
		if (TT[i] == -1)continue;
		pv = TT[i];
		Ans[i] = R[pv];
		for (j = pv - 1; j >= 0; j--) {
			long long tt = w[j][i];

			for(k=0;k<20;k++)w[j][k] = ((w[j][k] - tt * w[pv][k]) % Mod + Mod) % Mod;
			R[j] = ((R[j] - tt * R[pv]) % Mod + Mod) % Mod;
		}
	}
	for (i = 0; i <= 10; i++)if (Ans[i])break;
	if (i == 11) {
		puts("! -1");
		fflush(stdout);
		return 0;
	}
	for (i = 0; i < 20; i++) {
		long long s = 0;
		for (j = 0; j <= 10; j++) {
			s = (s + Pow(i, j)*Ans[j]) % Mod;
		}
		if (s != Z[i]) {
			puts("! -1");
			fflush(stdout);
			return 0;
		}
	}

	for (i = 0; i < Mod; i++) {
		long long t = 1, s = 0;
		for (j = 0; j <= 10; j++) {
			s = (s + t * Ans[j]) % Mod;
			t = t * i%Mod;
		}
		if (s == 0) {
			printf("! %d\n", i);
			return 0;
		}
	}
	printf("! -1\n");
}