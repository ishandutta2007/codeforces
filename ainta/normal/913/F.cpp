#include<cstdio>
#include<algorithm>
using namespace std;
long long Mod = 998244353, F[2010], InvF[2010], P1[2010], P2[2010], D[2010][2010];
long long D1[2010], R[2010];
int n;
long long Pow(long long a, long long b) {
	long long r = 1;
	while (b) {
		if (b & 1)r = r*a%Mod;
		a = a*a%Mod; b >>= 1;
	}
	return r;
}
int main() {
	int AA, BB, i, j;
	F[0] = 1;
	for (i = 1; i <= 2000; i++)F[i] = F[i - 1] * i%Mod;
	for (i = 0; i <= 2000; i++)InvF[i] = Pow(F[i], Mod - 2);
	scanf("%d%d%d",&n, &AA, &BB);
	P1[0] = P2[0] = 1;
	P1[1] = AA*Pow(BB, Mod - 2) % Mod;
	P2[1] = (Mod + 1 - P1[1]) % Mod;
	for (i = 2; i <= n; i++) {
		P1[i] = P1[i - 1] * P1[1] % Mod;
		P2[i] = P2[i - 1] * P2[1] % Mod;
	}
	for (i = 0; i <= n; i++) {
		D[i][0] = 1;
		long long s = 1;
		long long d = 0;
		for (j = 1; j <= i; j++) {
			D[i][j] = (D[i - 1][j - 1] * P2[i - j] + D[i - 1][j] * P1[j]) % Mod;
			long long p = D[i][j] * D1[j] % Mod;
			if (j != i) {
				s = (s + Mod - p) % Mod;
				d = (d + p * (R[j] + R[i - j] - (i - j)*(i - j - 1) / 2 + Mod)) % Mod;
			}
		}
		D1[i] = s;
		R[i] = (i*(i - 1) / 2 + d) * Pow(Mod + 1 - s, Mod - 2) % Mod;
	}
	printf("%lld\n", R[n]);
	return 0;
}