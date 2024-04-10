#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[1010];
int n, m, C[1010], cnt, M[1010], Num[1010], D[1010], Q[1010];
bool v[1010];
void DFS(int a, int c){
	C[a] = c;
	Num[a] = cnt;
	int i;
	for (i = 0; i < E[a].size(); i++){
		if (!C[E[a][i]]){
			DFS(E[a][i], 3 - c);
		}
	}
}
void Do(int a){
	int i, h = 0, t = 0, x;
	for (i = 1; i <= n; i++)v[i] = false;
	v[a] = true, Q[++t] = a, D[a] = 0;
	while (h < t){
		x = Q[++h];
		for (i = 0; i < E[x].size(); i++){
			if (!v[E[x][i]]){
				Q[++t] = E[x][i];
				v[Q[t]] = true;
				D[Q[t]] = D[x] + 1;
			}
		}
	}
	M[Num[a]] = max(M[Num[a]], D[Q[t]]);
}
int main(){
	int i, a, b, j, Res = 0;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; i++){
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	for (i = 1; i <= n; i++){
		if (!C[i]){
			cnt++;
			DFS(i, 1);
		}
	}
	a = 0;
	for (i = 1; i <= n; i++){
		for (j = 0; j < E[i].size(); j++){
			if (C[i] + C[E[i][j]] != 3)a = 1;
		}
	}
	if (a == 1){
		printf("-1\n");
		return 0;
	}
	for (i = 1; i <= n; i++){
		Do(i);
	}
	for (i = 1; i <= cnt; i++)Res += M[i];
	printf("%d\n", Res);
}