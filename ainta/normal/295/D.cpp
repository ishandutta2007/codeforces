#pragma warning(disable:4996)
#include<stdio.h>
long long D[2010][2010], Mod = 1000000007, Res, D2[2010][2010], D3[2010][2010], S;
int n, m;
int main()
{
	int i, j;
	scanf("%d%d", &n, &m);
	for (i = 2; i <= m; i++){
		D2[0][i] = 1;
		D[1][i] = i - 1;
		D3[1][i] = 1;
	}
	for (i = 2; i <= n; i++){
		S = 0;
		for (j = 2; j <= m; j++){
			D3[i][j] = S + D[i - 1][j - 1];
			S = (S+D[i - 1][j])%Mod;
			D[i][j] = (D[i][j - 1] + S)%Mod;
		}
	}
	for (i = 2; i <= n; i++){
		for (j = 2; j <= m; j++){
			D3[i][j] = (D3[i - 1][j] + D3[i][j]) % Mod;
		}
	}
	for (i = 1; i <= n; i++){
		S = 0;
		for (j = 1; j <= m; j++){
			S += D[i][j];
			D2[i][j] = (D2[i - 1][j] + S + Mod) % Mod;
		}
	}
	for (i = 1; i <= n; i++){
		for (j = 1; j <= m; j++){
			Res = (Res + D3[i][j] * D2[n - i][j]%Mod * (m-j+1))%Mod;
		}
	}
	printf("%lld\n", Res);
}