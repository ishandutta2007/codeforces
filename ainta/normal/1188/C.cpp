#include<cstdio>
#include<algorithm>
using namespace std;
int n, K, w[1010], S[1010][1010], Mod = 998244353;
int Z[101000];
int Calc(int KK) {
	int i, j;
	int prev = 0;
	for (i = 1; i <= n; i++) {
		while (prev+1 < i && w[prev + 1] + KK <= w[i])prev++;
		for (j = 1; j <= K; j++) {
			S[i][j] = S[i-1][j];
		}
		S[i][1]=(S[i][1]+1)%Mod;
		for (j = 2; j <= K; j++) {
			S[i][j] = (S[i][j] + S[prev][j - 1]) % Mod;
		}
	}
	return S[n][K];
}
int main() {
	int i;
	scanf("%d%d", &n, &K);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}
	sort(w + 1, w + n + 1);
	for (i = 0; i <= 100000 / (K-1); i++) {
		Z[i] = Calc(i);
	}
	long long res = 0;
	for (i = 0; i <= 100000 / (K - 1); i++) {
		Z[i] = Z[i] - Z[i + 1];
		res=(res+1ll * Z[i] * i)%Mod;
	}
	printf("%lld\n", res);
}