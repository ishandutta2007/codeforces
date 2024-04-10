#include<cstdio>
#include<algorithm>
using namespace std;
int n;
long long F[1010000], Mod = 998244353, res = 1, InvF[1010000];
long long Pow(long long a, long long b) {
	long long r = 1;
	while (b) {
		if (b & 1)r = r*a%Mod;
		a = a*a%Mod; b >>= 1;
	}
	return r;
}
int main() {
	int i;
	scanf("%d", &n);
	F[0] = 1;
	for (i = 1; i <= n; i++) {
		F[i] = F[i - 1] * i%Mod;
	}
	InvF[n] = Pow(F[n], Mod - 2);
	for (i = n; i >= 1; i--)InvF[i - 1] = InvF[i] * i%Mod;
	for (i = 1; i <= n; i++) {
		res = (res + F[n] - F[n] * InvF[i]%Mod + Mod)%Mod;
	}
	printf("%lld\n", res);
}