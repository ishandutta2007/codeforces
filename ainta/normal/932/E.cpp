#include<cstdio>
#include<algorithm>
using namespace std;
int n, P[5010], K, Mod = 1000000007;

int Pow(int a, int b) {
	int r = 1;
	while (b) {
		if (b & 1)r = 1ll * r*a%Mod;
		a = 1ll * a*a%Mod; b >>= 1;
	}
	return r;
}
struct Poly {
	int w[5010];
}T[5010], U;

int main() {
	int i, j;
	scanf("%d%d", &n, &K);
	int tp = 1;
	T[0].w[0] = 1;
	for (i = 1; i <= K; i++) {
		tp = 1ll * tp * (n - i + 1) % Mod;
		if(n>=i)P[i] = 1ll * Pow(2, n - i) * tp % Mod;
		else P[i] = 0;
		for (j = 0; j < i; j++) {
			T[i].w[j + 1] = T[i].w[j + 1] + T[i - 1].w[j];
			if (T[i].w[j + 1] >= Mod)T[i].w[j + 1] -= Mod;
			T[i].w[j] = (T[i].w[j] + (long long)T[i - 1].w[j] * (Mod-i+1)) % Mod;
		}
	}
	long long res = P[K];
	for (i = 0; i <= K; i++)U.w[i] = T[K].w[i];
	for (i = K-1; i >= 0; i--) {
		int t = Mod - U.w[i];
		res = (res + 1ll * t * P[i]) % Mod;
		for (j = 0; j <= i; j++) {
			U.w[j] = (U.w[j] + (long long)t*T[i].w[j]) % Mod;
		}
	}
	printf("%lld\n", res);
}