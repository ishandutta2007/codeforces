#include<cstdio>
#include<algorithm>
using namespace std;
int Mod = 998244353;
long long po[2010000], F[2010000], InvF[2010000];
long long res;
long long Pow(long long a, long long b) {
	long long r = 1;
	while (b) {
		if (b & 1)r = r*a%Mod;
		a = a*a%Mod; b >>= 1;
	}
	return r;
}
long long Comb(int a, int b) {
	return F[a] * InvF[b] % Mod*InvF[a - b] % Mod;
}
int n;
int main() {
	int i;
	po[0] = F[0] = 1;
	for (i = 1; i <= 2000000; i++) {
		po[i] = po[i - 1] * 3 % Mod;
		F[i] = F[i - 1] * i%Mod;
	}
	InvF[2000000] = Pow(F[2000000], Mod - 2);
	for (i = 2000000; i >= 1; i--)InvF[i - 1] = InvF[i] * i%Mod;
	scanf("%d", &n);
	res = Pow(3, 1ll * n*n);
	for (i = 1; i <= n; i++) {
		long long t = Pow(3, 1ll*(n - i)*n) * Pow(3, i) * 2 % Mod * Comb(n,i)%Mod;
		if (i & 1)res = (res - t + Mod) % Mod;
		else res = (res + t) % Mod;
	}
	for (i = 1; i <= n; i++) {
		long long t = po[n - i];
		long long A = Pow(Mod + 1 - t, n) - Pow(Mod - t, n) + Mod;
		long long r = Comb(n, i) * 3 % Mod*A%Mod;
		if ((i + n) % 2)r = Mod - r;
		res = (res + r) % Mod;
	}
	printf("%lld\n", (Pow(3,1ll*n*n) - res+Mod)%Mod);
}