#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<vector>
#define INF 999999999
using namespace std;
vector<int>E[101000];
int n, m, S, e, w[101000];
int D[301][101000], R[301];
int Do(int a, int b, int e, int x){
	int M, i, R = INF;
	while (b <= e){
		M = (b + e) >> 1;
		if (E[a][M] > x)R = E[a][M], e = M - 1;
		else b = M + 1;
	}
	return R;
}
int main()
{
	int i, j, a, K, tp;
	scanf("%d%d%d%d", &n, &m, &S, &e);
	for (i = 1; i <= n; i++){
		R[i] = INF;
		scanf("%d", &w[i]);
	}
	for (i = 1; i <= m; i++){
		scanf("%d", &a);
		E[a].push_back(i);
	}
	K = S / e;
	D[1][0] = INF;
	for (j = 1; j <= n; j++){
		D[1][j] = D[1][j - 1];
		if (!E[w[j]].empty()){
			if (D[1][j] > E[w[j]][0])D[1][j] = E[w[j]][0];
			if (R[1] > j + D[1][j])R[1] = j + D[1][j];
		}
	}
	for (i = 2; i <= K && i <= n; i++){
		D[i][i - 1] = INF;
		for (j = i; j <= n; j++){
			D[i][j] = D[i][j - 1];
			if (D[i - 1][j - 1] != INF){
				tp = Do(w[j], 0, E[w[j]].size() - 1, D[i - 1][j - 1]);
				if (D[i][j] > tp)D[i][j] = tp;
			}
			if (D[i][j] + j < R[i]) R[i] = D[i][j] + j;
		}
		if (R[i] + e * i > S)break;
	}
	if (R[1] + 1 * e > S)i = 1;
	printf("%d\n", i - 1);
}