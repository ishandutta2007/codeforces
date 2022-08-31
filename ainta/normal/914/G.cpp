#include<cstdio>
int n, C[1<<17], F[1<<17], Mod = 1000000007;
int A[1 << 17], D[1 << 7], E[1 << 7];
long long B[1 << 17];
int BB[1 << 17];


struct Fourier {
	const int SZ = 17, N = 1 << SZ;
	int Rev(int x) {
		int i, r = 0;
		for (i = 0; i < SZ; i++) {
			r = r << 1 | x & 1;
			x >>= 1;
		}
		return r;
	}

	void FFT(long long *a, bool f) {
		int i, j, k;
		long long z;
		for (i = 0; i < N; i++) {
			j = Rev(i);
			if (i < j) {
				z = a[i];
				a[i] = a[j];
				a[j] = z;
			}
		}
		for (i = 1; i < N; i <<= 1) for (j = 0; j < N; j += i << 1) for (k = 0; k < i; k++) {
			z = a[i + j + k];
			a[i + j + k] = a[j + k] - z;
			a[j + k] += z;
		}
		if (f) for (i = 0; i < N; i++) a[i] /= N;
	}
}FF;

int XX[1 << 17], YY[1 << 17], ZZ[1<<17];

void Do(int *X, int *Y, int *Z) {
	int i, j;
	for (i = 0; i < (1 << 17); i++) {
		XX[i] = X[i], YY[i] = Y[i];
	}
	for (i = 0; i < 17; i++) {
		for (j = 0; j < (1 << 17); j++) {
			if (!(j&(1 << i)))continue;
			XX[j ^ (1 << i)] = (XX[j ^ (1 << i)]+XX[j])%Mod;
			YY[j ^ (1 << i)] = (YY[j ^ (1 << i)]+YY[j])%Mod;
		}
	}
	for (i = 0; i < (1 << 17); i++) {
		ZZ[i] = 1ll*XX[i] * YY[i] % Mod;
	}
	for (i = (1<<17)-1; i >=0; i--) {
		int mask = (1 << 17) - i - 1;
		long long s = 0;
		for (int j = mask; j; j = (j - 1)&mask) {
			s += Z[j | i];
		}
		Z[i] = (ZZ[i] + Mod - s%Mod) % Mod;
	}
}

int main() {
	int i, j, a;
	scanf("%d", &n);
	F[0] = 0, F[1] = 1;
	for (i = 2; i < (1 << 17); i++)F[i] = (F[i - 1] + F[i - 2]) % Mod;
	for (i = 1; i <= n; i++) {
		scanf("%d", &a);
		C[a]++;
	}
	for (i = 0; i < (1 << 17); i++) {
		B[i] = C[i];
		long long s = 0;
		for (j = i;; j = (j - 1)&i) {
			s += (long long)C[j] * C[j^i];
			if (!j)break;
		}
		A[i] = s%Mod;
	}
	FF.FFT(B, false);
	for (i = 0; i < (1 << 17); i++)B[i] *= B[i];
	FF.FFT(B, true);
	for (i = 0; i < (1 << 17); i++)B[i] %= Mod;
	for (i = 0; i < (1 << 17); i++) {
		A[i] = 1ll * A[i] * F[i] % Mod;
		BB[i] = 1ll * B[i] * F[i] % Mod;
		C[i] = 1ll * C[i] * F[i] % Mod;
	}
	long long r = 0;
	Do(A, BB, D);
	Do(D, C, E);
	for (i = 0; i < 17; i++)r = (r + E[1<<i]) % Mod;
	printf("%lld\n", r);
}