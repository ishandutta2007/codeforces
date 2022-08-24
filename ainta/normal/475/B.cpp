#include<stdio.h>
bool E[401][401];
int n, m, ord[401], cnt, SCC[401];
char p[22], q[22];
bool v[401];
int Num(int x, int y){
	return m*x + y;
}
void DFS(int a){
	v[a] = true;
	int i;
	for (i = 0; i < n*m; i++){
		if (E[a][i] && !v[i])DFS(i);
	}
	ord[++cnt] = a;
}
void DFS2(int a){
	SCC[a] = 1;
	int i;
	for (i = 0; i < n*m; i++){
		if (E[i][a] && !SCC[i])DFS2(i);
	}
}
int main()
{
	int i, j;
	scanf("%d%d", &n, &m);
	scanf("%s", p);
	scanf("%s", q);
	for (i = 0; i < n; i++){
		if (p[i] == '>'){
			for (j = 0; j < m - 1; j++){
				E[Num(i, j)][Num(i, j + 1)] = true;
			}
		}
		else{
			for (j = 0; j < m - 1; j++){
				E[Num(i, j + 1)][Num(i, j)] = true;
			}
		}
	}
	for (i = 0; i < m; i++){
		if (q[i] == 'v'){
			for (j = 0; j < n - 1; j++){
				E[Num(j, i)][Num(j + 1, i)] = true;
			}
		}
		else{
			for (j = 0; j < n - 1; j++){
				E[Num(j + 1, i)][Num(j, i)] = true;
			}
		}
	}
	for (i = 0; i < n*m; i++){
		if(!v[i])DFS(i);
	}
	DFS2(ord[cnt]);
	for (i = 0; i < n*m; i++){
		if (!SCC[i])break;
	}
	if (i == n*m)printf("YES\n");
	else printf("NO\n");
}