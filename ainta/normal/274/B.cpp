#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[100010];
long long D[100010][2];
int n, C[100010];
void DFS(int a, int pp){
	int i;
	long long x = 0, y = 0, cc;
	for (i = 0; i < E[a].size(); i++){
		if (E[a][i] != pp){
			DFS(E[a][i], a);
			if (D[E[a][i]][0] > x)x = D[E[a][i]][0];
			if (D[E[a][i]][1] > y)y = D[E[a][i]][1];
		}
	}
	cc = C[a];
	cc -= x, cc += y;
	if (cc > 0)x += cc;
	else y -= cc;
	D[a][0] = x, D[a][1] = y;
}
int main()
{
	int i, a, b;
	scanf("%d", &n);
	for (i = 1; i < n; i++){
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	for (i = 1; i <= n; i++)scanf("%d", &C[i]);
	DFS(1, 0);
	printf("%lld\n", D[1][0] + D[1][1]);
}