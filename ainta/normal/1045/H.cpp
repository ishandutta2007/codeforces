#include<cstdio>
#include<algorithm>
char p[101000], q[101000];
int w[101000], C[4], n, S[4];
long long res, Mod = 1000000007, res2;
long long F[301000], InvF[301000];
long long Pow(long long a, long long b) {
	long long r = 1;
	while (b) {
		if (b & 1)r = r*a%Mod;
		a = a*a%Mod; b >>= 1;
	}
	return r;
}
long long Comb(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return F[a] * InvF[b] % Mod*InvF[a - b] % Mod;
}
long long CombH(int a, int b) {
	if (a == 0 && b == 0)return 1;
	return Comb(a + b - 1, b);
}
void Go(int L) {
	int i, T[4];
	for (i = 0; i < 4; i++) {
		T[i] = C[i] - S[i];
		if (T[i] < 0)return;
	}
	if (T[1] > T[2] + 1 || T[1] < T[2]) return;
	int c = T[1] + T[2];
	long long r1 = 1;
	long long r2 = CombH((c + 2) / 2, T[0]);
	long long r3 = CombH((c + 1) / 2, T[3]);
	res = (res + r1*r2%Mod*r3) % Mod;
}
void Do(int ck) {
	int i, prv = -1;
	int LL = C[0] + C[1] + C[2] + C[3] + 1;
	if (LL > n)return;
	if (LL != n) {
		for (i = n - 1; i >= 0; i--) w[i] = 1;
		n = LL;
		ck = 1;
	}
	for (i = 0; i < 4; i++)S[i] = 0;
	for (i = n - 1; i >= 0; i--) {

		if (i!=n-1 && w[i] == 1) {
			S[prv * 2 + 0]++;
			Go(i);
			S[prv * 2 + 0]--;
		}

		if (prv != -1) {
			S[prv * 2 + w[i]]++;
		}
		prv = w[i];
	}
	if (ck) {
		if (S[0] == C[0] && S[1] == C[1] && S[2] == C[2] && S[3] == C[3])res++;
	}
}
void Pro(char *a, int ck) {
	int i;
	for (i = 0; a[i]; i++);
	n = i;
	for (i = 0; i < n; i++)w[n - i - 1] = a[i] - '0';
	res = 0;
	Do(ck);
}
int main() {
	int i, j;
	F[0] = 1;
	for (i = 1; i <= 300000; i++)F[i] = F[i - 1] * i%Mod;
	InvF[i - 1] = Pow(F[i - 1], Mod - 2);
	for (i = 300000; i >= 1; i--)InvF[i - 1] = InvF[i] * i%Mod;
	scanf("%s%s", p, q);
	scanf("%d%d%d%d", &C[0], &C[1], &C[2], &C[3]);
	Pro(p, 0);
	res2 = res;
	Pro(q, 1);
	printf("%lld\n", (res - res2 + Mod) % Mod);
}