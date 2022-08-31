#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;
int n, Q, w[100010], C[501], P[501][100010], cnt;
map<int, int>Map;
int main()
{
	int n, i, j, a, b, r;
	scanf("%d%d", &n, &Q);
	for (i = 1; i <= n; i++){
		scanf("%d", &w[i]);
		Map[w[i]]++;
		if (Map[w[i]] == w[i])C[++cnt] = w[i];
	}
	for (i = 1; i <= cnt; i++){
		for (j = 1; j <= n; j++){
			P[i][j] = P[i][j - 1];
			if (w[j] == C[i])P[i][j]++;
		}
	}
	while (Q--){
		scanf("%d%d", &a, &b);
		r = 0;
		for (i = 1; i <= cnt; i++){
			if (P[i][b] - P[i][a - 1] == C[i])r++;
		}
		printf("%d\n", r);
	}
}