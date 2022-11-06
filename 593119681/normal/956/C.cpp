#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 100000 + 5

int n, A[N], Mark[N];
LL sum;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", A + i);
		Mark[i] = max(Mark[i - 1], A[i] + 1);
	}
	for (int i = n - 1; i; i --)
		Mark[i] = max(Mark[i], Mark[i + 1] - 1);
	for (int i = 1; i <= n; i ++)
		sum += Mark[i] - A[i] - 1;
	printf("%lld\n", sum);
	return 0;
}