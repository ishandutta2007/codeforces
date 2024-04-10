#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
char p[15][500020];
char q[500020];
int L[15], n, num, Mx;
int w[500010], C[10], P[15][500020];
int D[32768][120];
bool Same(int a){
	int i;
	for (i = 0; p[a][i]; i++){
		if (p[a][i] != q[i])return false;
	}
	return true;
}
void Do(int Numb, int m)
{
	int i, j, k, c, t;
	for (i = 1; i <= m + 1; i++){
		for (j = 0; j < n; j++)P[j][i] = -1;
		if (i != m + 1 && w[i] != -1)P[w[i]][i] = i;
	}
	for (i = m; i >= 1; i--){
		for (j = 0; j < n; j++){
			if (P[j][i] == -1)P[j][i] = P[j][i + 1];
		}
	}
	for (i = 0; i < (1 << n); i++){
		for (j = 0; j < 120; j++)D[i][j] = 999999999;
	}
	D[0][0] = 0;
	for (i = 0; i < (1 << n); i++){
		for (j = 0; j < 120; j++){
			if (D[i][j] == 999999999)continue;
			c = 0;
			for (k = 0; k < n; k++){
				if (i&(1 << k)){
					c++;
					continue;
				}
				t = P[k][D[i][j] + 1];
				if (t == -1)continue;
				D[i ^ (1 << k)][j + c] = min(D[i ^ (1 << k)][j + c], t);
			}
		}
	}
	t = (1 << n) - 1;
	for (i = 119; i >= 0; i--){
		if (D[t][i] != 999999999)break;
	}
	if (Mx < i + 1){
		Mx = i + 1;
		num = Numb;
	}
}
int main()
{
	int i, j, t, k, l, m;
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%s", p[i]);
		for (j = 0; p[i][j]; j++);
		L[i] = j;
	}
	scanf("%d", &m);
	for (i = 0; i < m; i++){
		scanf("%d", &C[i]);
		for (j = 1; j <= C[i]; j++){
			scanf("%s", q);
			for (k = 0; q[k]; k++);
			l = k;
			w[j] = -1;
			for (k = 0; k < n; k++){
				if (L[k] == l){
					if (Same(k)){
						w[j] = k;
						break;
					}
				}
			}
		}
		Do(i+1, C[i]);
	}
	if (!num){
		printf("Brand new problem!\n");
	}
	else{
		printf("%d\n", num);
		printf("[:");
		for (i = 0; i < Mx; i++)printf("|");
		printf(":]\n");
	}
	return 0;
}