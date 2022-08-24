#include<stdio.h>
#include<algorithm>
using namespace std;
bool P[20100], v[210];
int F[210][210], n, w[210], Flow;
int Res[210][210], cnt, C[210];
int DFS(int a, int ff){
	if (a == n + 1){
		Flow += ff;
		return ff;
	}
	int i, t;
	v[a] = true;
	for (i = 0; i <= n + 1; i++){
		if (!v[i] && F[a][i]){
			t = DFS(i, min(ff, F[a][i]));
			if (!t)continue;
			F[a][i] -= t; F[i][a] += t;
			return t;
		}
	}
	return 0;
}
void Do(int a){
	int i;
	while (1){
		v[a] = true;
		Res[cnt][++C[cnt]] = a;
		for (i = 1; i <= n; i++){
			if (v[i])continue;
			if (w[a] % 2 == 0 && w[i] % 2 == 1 && F[i][a])break;
			if (w[a] % 2 == 1 && w[i] % 2 == 0 && F[a][i])break;
		}
		if (i == n + 1)break;
		a = i;
	}
}
int main()
{
	int i, c=0, j;
	for (i = 2; i <= 20000; i++){
		if (!P[i]){
			for (j = i + i; j <= 20000; j += i)P[j] = true;
		}
	}
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		scanf("%d", &w[i]);
		if (w[i] % 2 == 0){
			c++;
			F[0][i] = 2;
		}
		else{
			F[i][n + 1] = 2;
		}
	}
	if (c * 2 != n){
		printf("Impossible\n");
		return 0;
	}
	for (i = 1; i <= n; i++){
		for (j = 1; j <= n; j++){
			if (w[i] % 2 == 0 && w[j] % 2 == 1 && !P[w[i] + w[j]])F[i][j] = 1;
		}
	}
	while (1){
		for (i = 0; i <= n + 1; i++)v[i] = false;
		if (!DFS(0, 2))break;
	}
	if (Flow != n){
		printf("Impossible\n");
		return 0;
	}
	for (i = 1; i <= n; i++)v[i] = false;
	for (i = 1; i <= n; i++){
		if (!v[i]){
			++cnt;
			Do(i);
		}
	}
	printf("%d\n", cnt);
	for (i = 1; i <= cnt; i++){
		printf("%d ", C[i]);
		for (j = 1; j <= C[i]; j++)printf("%d ", Res[i][j]);
		printf("\n");
	}
}