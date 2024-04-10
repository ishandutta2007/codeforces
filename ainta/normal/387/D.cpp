#pragma warning(disable:4996)
#include<stdio.h>
int n, m, w[501][501], Mat[1010];
bool chk[501], v[1010];
bool DFS(int a){
	v[a] = true;
	if (a > n){
		if (!Mat[a])return true;
		if (!v[Mat[a]])return DFS(Mat[a]);
	}
	int i;
	for (i = n + 1; i <= 2 * n; i++){
		if (!chk[i - n] && w[a][i - n] && Mat[a] != i && !v[i]){
			if (DFS(i)){
				Mat[a] = i, Mat[i] = a;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	int a, b, i, j, S, r = 999999999, Match = 0;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; i++){
		scanf("%d%d", &a, &b);
		w[a][b] = 1;
	}
	for (i = 1; i <= n; i++){
		S = (n-1)*3 + 1 + m;
		for (j = 1; j <= n; j++){
			if (w[i][j])S -= 2;
			if (w[j][i])S -= 2;
		}
		if (w[i][i]) S += 2;
		chk[i] = true;
		if (Mat[i])Mat[Mat[i]] = 0, Mat[i] = 0, Match--;
		if (Mat[n + i])Mat[Mat[n + i]] = 0, Mat[n + i] = 0, Match--;
		while (1){
			for (j = 1; j <= 2 * n; j++)v[j] = false;
			for (j = 1; j <= n; j++){
				if (!Mat[j] && !v[j] && !chk[j]){
					if (DFS(j))break;
				}
			}
			if (j == n + 1) break;
			Match++;
		}
		if (r > S - Match * 2)r = S - Match * 2;
		chk[i] = false;
	}
	printf("%d\n", r);
}