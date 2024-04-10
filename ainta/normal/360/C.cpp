#include<stdio.h>
int n, k, i, j, ii, t;
char p[2010], tp;
long long D[2010][2010], L[2010][2010], W[2010][2010], Mod = 1000000007;
int main()
{
	scanf("%d%d", &n, &k);
	scanf("%s", p + 1);
	for (i = 1; i <= n / 2; i++){
		tp = p[i];
		p[i] = p[n - i + 1];
		p[n - i + 1] = tp;
	}
	for (i = 1; i <= n; i++)p[i] -= 'a';
	D[0][0] = L[0][0] = 1;
	D[1][0] = L[1][0] = p[1] + 1;
	D[1][1] = W[1][1] = 25 - p[1];
	for (i = 2; i <= n; i++){
		for (j = 0; j <= k; j++){
			L[i][j] = (D[i - 1][j] * (long long)p[i] + L[i - 1][j])%Mod;
		}
		for (j = i; j <= k; j++){
			W[i][j] = D[i - 1][j - i] * (long long)(25 - p[i]);
		}
		for (j = i - 1; j >= 1; j--){
			t = j*(i - j + 1);
			for (ii = t ; ii <= k; ii++){
				W[i][ii] += D[j - 1][ii - t] * (25 - p[j]);
			}
		}
		for (j = 0; j <= k; j++){
			W[i][j] %= Mod;
			D[i][j] = L[i][j] + W[i][j];
			if (D[i][j] >= Mod)D[i][j] -= Mod;
		}
	}
	printf("%lld\n", D[n][k]);
}