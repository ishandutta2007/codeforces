#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[300010];
int n, m, X, M, par[300010], D[300010];
void DFS(int a, int pp, int d){
	if (M < d){
		M = d;
		X = a;
	}
	int i;
	for (i = 0; i < E[a].size(); i++){
		if (E[a][i] != pp){
			DFS(E[a][i], a, d + 1);
		}
	}
}
int find(int a){
	if (a == par[a])return a;
	return par[a] = find(par[a]);
}
int main()
{
	int a, b, i, x, y, Q;
	scanf("%d%d%d", &n, &m, &Q);
	for (i = 1; i <= n; i++){
		par[i] = i;
		D[i] = -1;
	}
	while (m--){
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
		x = find(a), y = find(b);
		if (x != y)par[y] = x;
	}
	for (i = 1; i <= n; i++){
		if (D[find(i)] == -1){
			M = -1;
			DFS(i, 0, 0);
			M = -1;
			DFS(X, 0, 0);
			D[find(i)] = M;
		}
	}
	while (Q--){
		scanf("%d%d", &i, &a);
		if (i == 1){
			printf("%d\n", D[find(a)]);
		}
		else{
			scanf("%d", &b);
			x = find(a), y = find(b);
			if (x != y){
				par[y] = x;
				D[x] = max(max(D[x], D[y]), (D[x] + 1) / 2 + (D[y] + 1) / 2 + 1);
			}
		}
	}
}