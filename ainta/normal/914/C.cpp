#include<cstdio>
#include<algorithm>
using namespace std;
char p[1010];
int w[1010], K, D[1010], Comb[1010][1010], n;
int Num(int a) {
	if (!a)return 0;
	return Num(a / 2) + a % 2;
}
long long Mod = 1000000007;
long long Calc(int d) {
	int i;
	long long r = 0;
	int c = 0;
	for (i = n - 1; i >= 0; i--) {
		if (w[i]) {
			if (0 <= d - c && d - c <= i) r = (r + Comb[i][d - c]) % Mod;
			c++;
		}
	}
	if (c == d)r++;
	return r;
}
int main() {
	int i, j;
	scanf("%s", p);
	for (i = 0; p[i]; i++);
	n = i;
	for (i = 0; i < n; i++)w[i] = p[n - i - 1] - '0';
	scanf("%d", &K);
	for (i = 0; i <= n; i++) {
		Comb[i][0] = 1;
		for (j = 1; j <= i; j++)Comb[i][j] = (Comb[i - 1][j] + Comb[i - 1][j - 1]) % Mod;
	}
	int mx = 0;
	for (i = 2; i <= 1000; i++) {
		D[i] = D[Num(i)] + 1;
		mx = max(mx, D[i]);
	}
	if (K == 0) {
		printf("1\n");
		return 0;
	}
	if (K == 1) {
		printf("%d\n", n-1);
		return 0;
	}
	long long res = 0;
	for (i = 1; i <= 1000; i++) {
		if (D[i] == K - 1) {
			res = (res + Calc(i)) % Mod;
		}
	}
	printf("%lld\n", res);
}