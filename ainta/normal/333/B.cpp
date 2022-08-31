#pragma warning(disable:4996)
#include<stdio.h>
bool X[1010], Y[1010];
int n, m, R;
int main()
{
	int i, x, y, j;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++){
		scanf("%d%d", &x, &y);
		X[x] = true, Y[y] = true;
	}
	if (n % 2 == 1){
		if (!X[(n + 1) / 2] || !Y[(n + 1) / 2]){
			R++;
		}
	}
	for (i = 2; i <= n / 2; i++){
		if (!X[i])R++;
		if (!X[n + 1 - i])R++;
		if (!Y[i])R++;
		if (!Y[n + 1 - i])R++;
	}
	printf("%d\n", R);
}