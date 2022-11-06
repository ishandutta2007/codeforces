#include <bits/stdc++.h>
using namespace std;
#define N 100000 + 5

int n, m, A[N];
double Max = -1;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
		scanf("%d", A + i);
	for (int i = 1, t = 1; i < n - 1; i ++)
	{
		for (; t <= n && A[t] - A[i] <= m; t ++) ;
		int x = t - 1;
		if (x <= i + 1) continue ;
		Max = max(Max, (double) (A[x] - A[i + 1]) / (A[x] - A[i]));
	}
	if (Max < 0) puts("-1");
	else printf("%.10f\n", Max);
	return 0;
}