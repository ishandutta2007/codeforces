#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, d, D[100010], Q[100010], D2[100010];
bool chk[100010];
vector<int>E[100010];
int BFS(int a){
	int i, h = 0, t = 0, x, M;
	for (i = 1; i <= n; i++)D[i] = -1;
	Q[++t] = a;
	D[a] = 0;
	while (h < t){
		x = Q[++h];
		for (i = 0; i < E[x].size(); i++){
			if (D[E[x][i]] == -1){
				D[E[x][i]] = D[x] + 1;
				Q[++t] = E[x][i];
			}
		}
	}
	M = -1;
	for (i = 1; i <= n; i++){
		if (chk[i] && M < D[i])M = D[i], x = i;
	}
	return x;
}
int main()
{
	int i, a, b, c, t;
	scanf("%d%d%d", &n, &m, &d);
	for (i = 1; i <= m; i++){
		scanf("%d", &a);
		chk[a] = true;
	}
	for (i = 1; i < n; i++){
		scanf("%d%d", &b, &c);
		E[b].push_back(c);
		E[c].push_back(b);
	}
	b = BFS(a);
	a = BFS(b);
	for (i = 1; i <= n; i++)D2[i] = D[i];
	b = BFS(a);
	int r = 0;
	for (i = 1; i <= n; i++){
		if (D[i] <= d&&D2[i] <= d)r++;
	}
	printf("%d\n", r);
}