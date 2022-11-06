#include <cstdio>
#include <algorithm>
using namespace std;
#define N 5000 + 5

int n, q, A[N], Val[N][N], Max[N][N];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", A + i);
		Val[i][1] = A[i];
	}
	for (int l = 2; l <= n; l ++)
		for (int i = 1; i + l - 1 <= n; i ++)
			Val[i][l] = Val[i][l - 1] ^ Val[i + 1][l - 1];
	for (int l = 1; l <= n; l ++)
		for (int i = 1; i + l - 1 <= n; i ++)
			Max[i][i + l - 1] = max(Val[i][l], max(Max[i][i + l - 2], Max[i + 1][i + l - 1]));
	scanf("%d", &q);
	for (int i = 1, l, r; i <= q; i ++)
	{
		scanf("%d%d", &l, &r);
		printf("%d\n", Max[l][r]);
	}
	return 0;
}