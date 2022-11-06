#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 200000 + 5
#define INF 3000000000000000000LL

int n, X[N], Flag[N];
LL t, A[N], B[N];
bool ok = 1;

int main()
{
	scanf("%d%lld", &n, &t);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%lld", A + i);
		B[i] = INF - (n - i);
	}
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", X + i);
		ok &= (X[i] >= i);
		if (X[i] < n) B[X[i]] = min(B[X[i]], A[X[i] + 1] + t - 1);
		Flag[i + 1] ++, Flag[X[i] + 1] --;
	}
	if (!ok) puts("No");
	else
	{
		for (int i = n - 1; i; i --)
			B[i] = min(B[i], B[i + 1] - 1);
		for (int i = 1; ok && i <= n; i ++)
		{
			ok &= (B[i] >= A[i] + t);
			Flag[i] += Flag[i - 1];
			if (Flag[i])
				ok &= (B[i - 1] >= A[i] + t);
		}
		if (!ok) puts("No");
		else
		{
			puts("Yes");
			for (int i = 1; i <= n; i ++)
				printf("%lld%c", B[i], i == n ? '\n' : ' ');
		}
	}
	return 0;
}