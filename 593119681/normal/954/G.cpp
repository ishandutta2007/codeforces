#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 500000 + 5
#define LIM 4000000000000000000LL

int n, r, T[N];
LL k, A[N << 1];

bool Check(LL lim)
{
	for (int i = 1; i <= n; i ++)
		A[i] = T[i];
	for (int i = n + 1; i <= n + r; i ++)
		A[i] = 0;
	LL sum = 0, ret = k;
	for (int i = 1; i <= r; i ++)
		sum += A[i];
	for (int i = r + 1; i <= n + r; i ++)
	{
		sum += (i <= n ? A[i] : 0) - (i > 2 * r + 1 ? A[i - 2 * r - 1] : 0);
		if (sum < lim)
		{
			A[i] += lim - sum;
			ret -= lim - sum;
			sum = lim;
		}
		if (ret < 0) return 0;
	}
	return 1;
}

int main()
{
	scanf("%d%d%lld", &n, &r, &k);
	r = min(r, n - 1);
	for (int i = 1; i <= n; i ++)
		scanf("%d", T + i);
	LL le = 0, ri = LIM;
	while (le < ri)
	{
		LL mid = le + ri + 1 >> 1;
		if (Check(mid)) le = mid;
		else ri = mid - 1;
	}
	printf("%lld\n", le);
	return 0;
}