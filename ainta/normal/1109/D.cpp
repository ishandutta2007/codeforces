#include<cstdio>
#include<algorithm>
#define N_ 2010000
using namespace std;
long long F[N_], InvF[N_], Mod = 1000000007, po[N_];
long long Pow(long long a, long long b) {
	long long r = 1;
	while (b) {
		if (b & 1)r = r*a%Mod;
		a = a*a%Mod; b >>= 1;
	}
	return r;
}
long long Comb(int a, int b) {
	if (b < 0 || a < b)return 0;
	return F[a] * InvF[b] % Mod*InvF[a - b] % Mod;
}
int main() {
	int i;
	int n, a, b, m;
	scanf("%d%d%d%d", &n, &m, &a, &b);
	F[0] = 1;
	po[0] = 1;
	for (i = 1; i < N_; i++) {
		F[i] = F[i - 1] * i%Mod;
		po[i] = po[i - 1] * m%Mod;
	}
	InvF[N_ - 1] = Pow(F[N_ - 1], Mod - 2);
	for (i = N_ - 1; i >= 1; i--) {
		InvF[i - 1] = InvF[i] * i%Mod;
	}
	long long res = 0;
	for (i = 1; i < n&&i <= m; i++) {
		long long t = Comb(m - 1, m - i) * Comb(n - 2, i - 1) % Mod*F[i - 1] % Mod*po[n - 1 - i]%Mod;
		if (i == n - 1) {
			res = (res + t) % Mod;
			continue;
		}
		t = t * Pow(n,n-i-2)%Mod*(i+1) % Mod;
		res = (res + t) % Mod;
	}
	printf("%lld\n", res);
}