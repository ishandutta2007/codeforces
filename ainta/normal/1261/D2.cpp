#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#define pii pair<int,int>
using namespace std;
long long F[401000], Mod = 998244353, InvF[401000];
long long Pow(long long a, long long b) {
	long long r = 1;
	while (b) {
		if (b & 1)r = r * a%Mod;
		a = a * a%Mod; b >>= 1;
	}
	return r;
}
int A[201000], n, K;
long long S[201000], res;
long long Comb(int a, int b) {
	return F[a] * InvF[b] % Mod*InvF[a - b] % Mod;
}
int main() {
	int i;
	F[0] = 1;
	for (i = 1; i <= 400000; i++)F[i] = F[i - 1] * i%Mod;
	InvF[i - 1] = Pow(F[i - 1], Mod - 2);
	for (i = i - 1; i >= 1; i--)InvF[i - 1] = InvF[i] * i%Mod;
	scanf("%d%d", &n, &K);
	for (i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	int c2 = 0, c1 = 0;
	for (i = 0; i < n; i++) {
		if (A[i] == A[(i + 1) % n])c2++;
		else c1++;
	}
	for (i = 0; i <= c1; i++) {
		if (i % 2 == 1) {
			S[i] = Pow(2, i - 1) % Mod;
		}
		else {
			S[i] = (Pow(2, i) - Comb(i, i / 2) + Mod)*(Mod / 2 + 1) % Mod;
		}
	}
	for (i = 0; i <= c1; i++) {
		if (K >= 2 || i==c1) {
			res = (res + Pow(K - 2, c1 - i) * S[i] % Mod * Comb(c1,i)) % Mod;
		}
	}
	res = res * Pow(K, c2) % Mod;
	printf("%lld\n", res);
	
}