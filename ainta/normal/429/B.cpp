#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
int D[4][1010][1010], n, m, w[1010][1010], R;
int main()
{
	int i, j;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++){
		for (j = 1; j <= m; j++){
			scanf("%d", &w[i][j]);
		}
	}
	for (i = 1; i <= n; i++){
		for (j = 1; j <= m; j++){
			D[0][i][j] = max(D[0][i - 1][j], D[0][i][j - 1]) + w[i][j];
		}
	}
	for (i = n; i >= 1; i--){
		for (j = m; j >= 1; j--){
			D[1][i][j] = max(D[1][i + 1][j], D[1][i][j + 1]) + w[i][j];
		}
	}
	for (i = n; i >= 1; i--){
		for (j = 1; j <= m; j++){
			D[2][i][j] = max(D[2][i + 1][j], D[2][i][j - 1]) + w[i][j];
		}
	}
	for (i = 1; i <= n; i++){
		for (j = m; j >= 1; j--){
			D[3][i][j] = max(D[3][i - 1][j], D[3][i][j + 1]) + w[i][j];
		}
	}
	for (i = 2; i < n; i++){
		for (j = 2; j < m; j++){
			R = max(R, max(D[0][i - 1][j] + D[1][i + 1][j] + D[2][i][j - 1] + D[3][i][j + 1], D[0][i][j - 1] + D[1][i][j + 1] + D[2][i + 1][j] + D[3][i - 1][j]));
		}
	}
	printf("%d\n", R);
}