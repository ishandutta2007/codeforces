#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
long long Mod = 998244353;
long long F[2001000], InvF[2010000];
char p[1010000];
int n, SB[1010000], S1[1010000], S2[1010000];
long long Pow(long long a, long long b) {
	long long r = 1;
	while (b) {
		if (b & 1)r = r * a%Mod;
		a = a * a%Mod; b >>= 1;
	}
	return r;
}
long long Comb(int a, int b) {
	if (b < 0 || a < b)return 0ll;
	return F[a] * InvF[b] % Mod*InvF[a - b] % Mod;
}
long long Calc(int A, int B, int c, int c1) {
	return (A * Comb(A + B - 1, c-1) % Mod + c1 * Comb(A+B,c)%Mod)%Mod;
}
int main() {
	int i, j;
	scanf("%d", &n);
	F[0] = 1;
	for (i = 1; i <= 2000000; i++)F[i] = F[i - 1] * i%Mod;
	InvF[i - 1] = Pow(F[i - 1], Mod - 2);
	for (i = 2000000; i >= 1; i--)InvF[i - 1] = InvF[i] * i%Mod;
	scanf("%s", p + 1);
	for (i = 1; p[i]; i++);
	n = i - 1;
	for (i = 1; i <= n; i++) {
		S1[i] = S1[i - 1];
		S2[i] = S2[i - 1];
		SB[i] = SB[i - 1];
		if (p[i] == '?')SB[i]++;
		if (p[i] == '(')S1[i]++;
		if (p[i] == ')')S2[i]++;
	}
	long long res = 0;
	for (i = 1; i < n; i++) {
		int c1 = S1[i];
		int c2 = S2[n] - S2[i];
		int A = SB[i];
		int B = SB[n] - SB[i];
		res = (res + Calc(A, B, B + c2 - c1, c1)) % Mod;
		
	}
	printf("%lld\n", res);
}