#include<stdio.h>
long long w[128][128], D[128], TD[128], tw[128][128];
long long Mod = 1000000007;
int p[7];
void Do(int n, int C){
	int i, m = 1<<n, j, k, t, l;
	for (i = 0; i < m; i++){
		for (j = 0; j < m; j++){
			w[i][j] = 0;
			for (k = 0; k < m / 2; k++){
				t = k * 2 + 1 + m;
				for (l = 1; l != m; l *= 2){
					if (!(l&i) && !(l&j) && (((l * 3) & t) == l * 3)){
						break;
					}
				}
				if (l == m)w[i][j]++;
			}
		}
	}
	while (C){
		if (C & 1){
			for (i = 0; i < m; i++){
				TD[i] = D[i];
				D[i] = 0;
			}
			for (i = 0; i < m; i++){
				for (j = 0; j < m; j++){
					D[j] = (D[j] + w[i][j] * TD[i]) % Mod;
				}
			}
		}
		C >>= 1;
		for (i = 0; i < m; i++){
			for (j = 0; j < m; j++){
				tw[i][j] = w[i][j]; w[i][j] = 0;
			}
		}
		for (i = 0; i < m; i++)for (j = 0; j < m; j++)for (k = 0; k < m; k++)w[i][j] = (w[i][j] + tw[i][k] * tw[k][j]) % Mod;
	}
}
int main()
{
	int i;
	D[0] = 1;
	for (i = 1; i <= 7; i++){
		scanf("%d", &p[i]);
		Do(i, p[i]);
	}
	printf("%lld\n", D[0]);
}