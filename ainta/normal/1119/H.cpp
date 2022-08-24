#include<cstdio>
#include<algorithm>
using namespace std;
void fwht(long long *a, int N) {
	int h = 1;
	while (h < N) {
		for (int i = 0; i < N; i += h * 2) {
			for (int j = i; j < i + h; j++) {
				long long x = a[j];
				long long y = a[j + h];
				a[j] = x + y;
				a[j + h] = x - y;
			}
		}
		h *= 2;
	}
}
int A, B, C, S;
struct point {
	int a, b, c;
}P[101000];
int n, K;
long long T[4][1 << 17], po[101000][4], U[4], Mod = 998244353, Res[1<<17];
long long Pow(long long a, int b) {
	long long r = 1;
	while (b) {
		if (b & 1)r = r * a%Mod;
		a = a * a%Mod; b >>= 1;
	}
	return r;
}
int main() {
	scanf("%d%d", &n, &K);
	scanf("%d%d%d", &A, &B, &C);
	U[0] = (long long)A + B + C;
	U[1] = A + B - C;
	U[2] = A - B + C;
	U[3] = A - B - C;
	int i, j;
	long long Inv = Pow(Pow(2,K), Mod - 2);
	for (i = 0; i < 4; i++) {
		U[i] %= Mod;
		if (U[i] < 0)U[i] += Mod;
	}
	for (i = 0; i <= n; i++) {
		for (j = 0; j < 4; j++) {
			if (!i)po[i][j] = 1;
			else po[i][j] = po[i - 1][j] * U[j] % Mod;
		}
	}
	for (i = 1; i <= n; i++) {
		scanf("%d%d%d", &P[i].a, &P[i].b, &P[i].c);
		S ^= P[i].a;
		P[i].b ^= P[i].a;
		P[i].c ^= P[i].a;
		P[i].a = 0;
	}
	for (i = 1; i <= n; i++)T[0][P[i].b]++;
	for (i = 1; i <= n; i++)T[1][P[i].c]++;
	for (i = 1; i <= n; i++)T[2][P[i].b^P[i].c]++;
	fwht(T[0], 1<<K);
	fwht(T[1], 1<<K);
	fwht(T[2], 1<<K);
	for (i = 0; i < (1 << K); i++) {
		long long r0 = n, r1 = T[0][i], r2 = T[1][i], r3 = T[2][i];
		long long x, y, z, w;
		x = (r0 + r1 + r2 + r3) / 4;
		y = (r0 + r1 - 2 * x) / 2;
		z = (r0 + r2 - 2 * x) / 2;
		w = (r0 + r3 - 2 * x) / 2;
		T[3][i] = po[x][0] * po[y][1] % Mod*po[z][2] % Mod*po[w][3] % Mod;
	}
	fwht(T[3], 1 << K);
	for (i = 0; i < (1 << K); i++) {
		Res[i^S] = (T[3][i]%Mod+Mod)%Mod;
	}
	for (i = 0; i < (1 << K); i++)printf("%lld ", Res[i]*Inv%Mod);
}