#pragma warning(disable:4996)
#include<stdio.h>
int n, w[510][510], D[510][510], ord[510];
long long Res[510], S;
bool v[510], ck[510];
void Dijk(int a){
	int i, j;
	for (i = 1; i <= n; i++){
		if (ck[i]){
			D[a][i] = w[a][i];
			D[i][a] = w[i][a];
		}
	}
	for (i = 1; i <= n; i++){
		if (!ck[i])continue;
		for (j = 1; j <= n; j++){
			if (!ck[j])continue;
			if (D[a][j] > D[a][i] + D[i][j]) D[a][j] = D[a][i] + D[i][j];
			if (D[j][a] > D[j][i] + D[i][a]) D[j][a] = D[j][i] + D[i][a];
		}
	}
}
int main()
{
	int i, j, x, k;
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		for (j = 1; j <= n; j++){
			scanf("%d", &w[i][j]);
		}
	}
	for (i = 1; i <= n; i++){
		scanf("%d", &ord[i]);
	}
	for (i = n; i >= 1; i--){
		x = ord[i];
		ck[x] = true;
		Dijk(x);
		S = 0;
		for (j = 1; j <= n; j++){
			if (!ck[j])continue;
			for (k = 1; k <= n; k++){
				if (!ck[k])continue;
				if (D[j][x] + D[x][k] < D[j][k])D[j][k] = D[j][x] + D[x][k];
				S += D[j][k];
			}
		}
		Res[i] = S;
	}
	for (i = 1; i <= n; i++)printf("%lld ", Res[i]);
}