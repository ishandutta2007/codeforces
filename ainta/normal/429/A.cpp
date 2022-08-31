#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int n, w[100010], res[100010], cnt;
vector<int>E[100010];
void DFS(int a, int b, int c, int dep, int pp){
	if (dep & 1){
		if (w[a] ^ c){
			c ^= 1;
			res[cnt++] = a;
		}
	}
	else{
		if (w[a] ^ b){
			b ^= 1;
			res[cnt++] = a;
		}
	}
	int i;
	for (i = 0; i < E[a].size(); i++){
		if (pp != E[a][i]){
			DFS(E[a][i], b, c, dep + 1, a);
		}
	}
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
	for (i = 1; i <= n; i++)scanf("%d", &w[i]);
	for (i = 1; i <= n; i++){
		scanf("%d", &a);
		w[i] ^= a;
	}
	DFS(1, 0, 0, 0, -1);
	printf("%d\n", cnt);
	for (i = 0; i < cnt; i++)printf("%d\n", res[i]);
}