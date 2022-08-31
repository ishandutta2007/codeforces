#pragma warning(disable:4996)
#include<stdio.h>
#include<vector>
#include<algorithm>
#define N_ 100010
#define B_SZ 100
#define INF 99999999
using namespace std;
vector<int>E[N_];
int n, m, par[18][N_], dep[N_], w[B_SZ], cnt, D[N_], Q[N_];
void DFS(int a, int p){
	par[0][a] = p;
	dep[a] = dep[p] + 1;
	int i;
	for (i = 0; par[i][a]; i++)par[i + 1][a] = par[i][par[i][a]];
	for (i = 0; i != E[a].size(); i++){
		if (E[a][i] != p)DFS(E[a][i], a);
	}
}
void BFS(){
	int h = 0, t = 0, i, x;
	while (cnt--)D[w[cnt]] = 0, Q[++t] = w[cnt];
	while (h < t){
		x = Q[++h];
		for (i = 0; i < E[x].size(); i++){
			if (D[E[x][i]] > D[x] + 1)D[E[x][i]] = D[x] + 1, Q[++t] = E[x][i];
		}
	}
}
int dis(int a, int b){
	if (dep[a] < dep[b])return dis(b, a);
	int d = dep[a] - dep[b], i;
	for (i = 0; i != 17; i++)if (d&(1 << i))a = par[i][a];
	for (i = 16; i >= 0; i--){
		if (par[i][a] != par[i][b]) d += 1 << i + 1, a = par[i][a], b = par[i][b];
	}
	return a != b ? d + 2 : d;
}
int main(){
	int i, a, b, res;
	scanf("%d%d", &n, &m);
	for (i = 1; i < n; i++){
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	dep[0] = -1;
	DFS(1, 0);
	for (i = 1; i <= n; i++)D[i] = INF;
	w[cnt++] = 1;
	while (m--){
		scanf("%d%d", &a, &b);
		if (a == 1){
			w[cnt++] = b;
			if (cnt == B_SZ){
				BFS();
				cnt = 0;
			}
			continue;
		}
		res = D[b];
		for (i = 0; i < cnt; i++)res = min(res, dis(w[i], b));
		printf("%d\n", res);
	}
}