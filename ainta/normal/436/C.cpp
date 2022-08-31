#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
int X, Y, n, m;
char p[1010][11][11];
int w[1010][1010], D[1010], Res, par[1010];
int Ans[1010][2];
bool v[1010];
int main()
{
	int i, j, k, l, Mn, x;
	scanf("%d%d%d%d", &X, &Y, &n, &m);
	for (i = 1; i <= n; i++){
		for (j = 0; j < X; j++){
			scanf("%s", p[i][j]);
		}
		w[0][i] = w[i][0] = X*Y;
	}
	for (i = 1; i <= n; i++){
		for (j = i + 1; j <= n; j++){
			for (k = 0; k < X; k++){
				for (l = 0; l < Y; l++){
					if (p[i][k][l] != p[j][k][l])w[i][j] += m;
				}
			}
		}
		for (j = 1; j < i; j++)w[i][j] = w[j][i];
	}
	for (i = 1; i <= n; i++)D[i] = 999999999;
	for (i = 0; i <= n; i++){
		Mn = 999999999;
		for (j = 0; j <= n; j++){
			if (!v[j] && Mn > D[j])Mn = D[j], x = j;
		}
		v[x] = true;
		if (i){
			Ans[i][0] = x;
			Ans[i][1] = par[x];
		}
		Res += D[x];
		for (j = 0; j <= n; j++){
			if (D[j] > w[x][j]){
				D[j] = w[x][j];
				par[j] = x;
			}
		}
	}
	printf("%d\n", Res);
	for (i = 1; i <= n; i++){
		printf("%d %d\n", Ans[i][0], Ans[i][1]);
	}
	return 0;
}