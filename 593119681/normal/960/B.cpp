#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 100000 + 5

int n, k_1, k_2, A[N], B[N];
LL ans;

int main()
{
	scanf("%d%d%d", &n, &k_1, &k_2);
	k_1 += k_2;
	for (int i = 1; i <= n; i ++)
		scanf("%d", A + i);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", B + i);
		if (A[i] > B[i]) swap(A[i], B[i]);
	}
	while (k_1 --)
	{
		int Max = 1;
		for (int i = 1; i <= n; i ++)
			if (B[i] - A[i] > B[Max] - A[Max])
				Max = i;
		int i = Max;
		if (A[i] == B[i]) B[i] ++;
		else B[i] --;
	}
	for (int i = 1; i <= n; i ++)
		ans += 1LL * (B[i] - A[i]) * (B[i] - A[i]);
	printf("%lld\n", ans);
	return 0;
}