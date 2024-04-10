#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
int n, K;
long long Mod = 1000000007, D[2][501][501], po[510], Gap[501][501], Res;
int main()
{
	scanf("%d%d", &n, &K);
	if (!K){
		printf("1\n");
		return 0;
	}
	int i, j, k, pv = 0;
	po[0] = 1;
	for (i = 1; i <= n; i++)po[i] = po[i - 1] * 2 % Mod;
	for (i = 1; i <= n; i++){
		for (j = 1; j <= n; j++){
			Gap[i][j] = po[j] * (po[i - j] - 1 + Mod) % Mod;
		}
	}
	for (i = 1; i <= n; i++){
		pv = !pv;
		D[pv][1][i] = (po[i] - 1 + Mod) % Mod;
		for (j = 1; j < i; j++){
			for (k = j; k < i; k++){
				D[pv][j][k] = (D[pv][j][k] + D[!pv][j][k] * po[k]) % Mod;
				D[pv][j + 1][i] = (D[pv][j + 1][i] + D[!pv][j][k] * Gap[i][k]) % Mod;
				D[!pv][j][k] = 0;
			}
		}
	}
	for (i = 1; i <= n; i++){
		Res = (Res + D[pv][K][i]) % Mod;
	}
	printf("%lld\n", Res);
}