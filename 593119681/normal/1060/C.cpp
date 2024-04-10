#include <cstdio>
#include <algorithm>
using namespace std;
#define N 2000 + 5
#define M 4000000 + 5

int n, m, x, ans, A[N], B[N], Max[M];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", A + i);
		for (int j = i, sum = 0; j; j --)
		{
			sum += A[j];
			Max[sum] = max(Max[sum], i - j + 1);
		}
	}
	for (int i = 1; i < M; i ++)
		Max[i] = max(Max[i], Max[i - 1]);
	for (int i = 1; i <= m; i ++)
		scanf("%d", B + i);
	scanf("%d", &x);
	for (int i = 1; i <= m; i ++)
		for (int j = i, sum = 0; j; j --)
		{
			sum += B[j];
			ans = max(ans, (i - j + 1) * Max[min(x / sum, M - 1)]);
		}
	printf("%d\n", ans);
	return 0;
}