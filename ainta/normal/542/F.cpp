#include<stdio.h>
#include<algorithm>
using namespace std;
int n, T, D[110][1100], w[110][1100], C[101];
int main(){
	int i, a, b, j, k;
	scanf("%d%d", &n, &T);
	for (i = 1; i <= n; i++){
		scanf("%d%d", &a, &b);
		w[T - a][C[T - a]++] = b;
	}
	for (i = T; i >= 0; i--){
		for (j = 1; j <= 500; j++){
			D[i][j] = max(D[i + 1][j * 2], D[i + 1][j * 2 - 1]);
		}
		for (j = 0; j < C[i]; j++){
			for (k = n - 1; k >= 0; k--){
				D[i][k + 1] = max(D[i][k + 1], D[i][k] + w[i][j]);
			}
		}
	}
	printf("%d\n", D[0][1]);
}