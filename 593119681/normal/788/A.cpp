#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 100000 + 5

int n, A[N];
LL ans, Sum[N], Max[N], Min[N];

inline int Abs(int x)
{
	return x > 0 ? x : -x;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", A + i);
	for (int i = 1, op = 1; i < n; i ++, op = -op)
		Sum[i] = Sum[i - 1] + Abs(A[i] - A[i + 1]) * op;
	Max[n - 1] = Min[n - 1] = Sum[n - 1];
	for (int i = n - 2; i; i --)
	{
		Max[i] = max(Max[i + 1], Sum[i]);
		Min[i] = min(Min[i + 1], Sum[i]);
	}
	for (int i = 0; i + 1 < n; i += 2)
		ans = max(ans, Max[i + 1] - Sum[i]);
	for (int i = 1; i + 1 < n; i += 2)
		ans = max(ans, Sum[i] - Min[i + 1]);
	printf("%I64d\n", ans);
	return 0;
}