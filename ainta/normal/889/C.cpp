#include<cstdio>
#include<algorithm>
using namespace std;
int n, K;
long long D[1010000], Mod = 1000000007, F[1010000], InvF[1010000], res;
long long Pow(long long a, long long b) {
	long long r = 1;
	while (b) {
		if (b & 1)r = r*a%Mod;
		a = a*a%Mod; b >>= 1;
	}
	return r;
}
long long Comb(int a, int b) {
	if (a < b)return 0;
	return F[a] * InvF[b] % Mod*InvF[a - b] % Mod;
}
int main() {
	scanf("%d%d", &n, &K);
	int i;
	F[0] = 1;
	for (i = 1; i <= n; i++)F[i] = F[i - 1] * i%Mod;
	InvF[n] = Pow(F[n], Mod - 2);
	for (i = n - 1; i >= 0; i--)InvF[i] = InvF[i + 1] * (i + 1) % Mod;
	D[K + 1] = F[K];
	for (i = K + 2; i <= n; i++) {
		D[i] = D[i - 1] * i;
		D[i] = (D[i] + (F[i-K-1] - D[i - K - 1] + Mod) * Comb(i - 1, K) % Mod * F[K]) % Mod;
	}
	for (i = 0; i < n; i++) {
		res = (res + (F[i] - D[i] + Mod) * Comb(n - 1, i) % Mod * F[n - i - 1]) % Mod;
	}
	printf("%lld\n", (F[n] - res + Mod)%Mod);
}