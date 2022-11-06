#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 100000 + 5

int n, Fa[N], A[N];
LL ans;
bool Flag[N];

int main()
{
	scanf("%d", &n);
	for (int i = 2, p; i <= n; i ++)
	{
		scanf("%d", &p);
		Fa[i] = p;
	}
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", A + i);
		if (A[i] == -1)
			Flag[i] = 1;
	}
	for (int i = 2; i <= n; i ++)
		if (Flag[Fa[i]])
			A[Fa[i]] = A[Fa[i]] == -1 ? A[i] : min(A[Fa[i]], A[i]);
	ans = A[1];
	for (int i = 2; ans != -1 && i <= n; i ++)
	{
		if (A[i] == -1) continue ;
		if (A[Fa[i]] > A[i])
			ans = -1;
		else ans += A[i] - A[Fa[i]];
	}
	printf("%lld\n", ans);
	return 0;
}