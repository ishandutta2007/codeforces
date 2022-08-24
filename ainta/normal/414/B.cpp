#pragma warning(disable:4996)
#include<stdio.h>
int D[2010][2010], Mod = 1000000007, R;
int main(){
	int i, j, n, K, k, t;
	scanf("%d%d", &n, &K);
	D[0][1] = 1;
	for (i = 1; i <= K; i++){
		for (j = 1; j <= n; j++){
			if (!D[i - 1][j])continue;
			t = D[i - 1][j];
			for (k = j; k <= n; k += j){
				D[i][k] = (D[i][k] + t) % Mod;
			}
		}
	}
	for (i = 1; i <= n; i++) R = (R + D[K][i]) % Mod;
	printf("%d\n", R);
}