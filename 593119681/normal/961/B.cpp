#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100000 + 5

int n, k, ans, Max, A[N], Sum[N];

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i ++)
		scanf("%d", A + i);
	for (int i = 1, x; i <= n; i ++)
	{
		scanf("%d", &x);
		if (x) ans += A[i], A[i] = 0;
		Sum[i] = Sum[i - 1] + A[i];
		if (i >= k) Max = max(Max, Sum[i] - Sum[i - k]);
	}
	printf("%d\n", ans + Max);
	return 0;
}