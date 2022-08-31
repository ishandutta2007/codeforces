#include<cstdio>
#include<algorithm>
using namespace std;
int Mod = 1000000007, F[1010000], InvF[1010000], w[1010000];
int Pow(int a, int b) {
	int r = 1;
	while (b) {
		if(b&1)r = r * 1ll * a%Mod;
		a = 1ll * a*a%Mod; b >>= 1;
	}
	return r;
}
int n;
int main() {
	int i;
	F[0] = InvF[0] = 1;
	for (i = 1; i <= 1000000; i++) {
		F[i] = 1ll*F[i - 1] * i%Mod;
	}
	InvF[i - 1] = Pow(F[i - 1], Mod - 2);
	for (i = i - 1; i >= 1; i--) {
		InvF[i - 1] = 1ll * InvF[i] * i%Mod;
	}
	scanf("%d", &n);
	for (i = 1; i <= n; i++)scanf("%d", &w[i]);
	sort(w + 1, w + n + 1);
	int pv = 0;
	long long res = 0;
	for (i = 1; i <= n; i++) {
		while (w[pv+1] < w[i])pv++;
		res = (res + 1ll * F[n] * InvF[n - pv] % Mod*F[n - pv - 1] % Mod*w[i]) % Mod;
	}
	res = (res - 1ll * F[n] * w[n] % Mod + Mod) % Mod;
	printf("%lld\n", res);
}