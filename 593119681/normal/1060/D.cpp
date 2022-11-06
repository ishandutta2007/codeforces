#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 100000 + 5

int n, A[N], B[N];
LL ans;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d%d", A + i, B + i);
	sort(A + 1, A + n + 1);
	sort(B + 1, B + n + 1);
	for (int i = 1; i <= n; i ++)
		ans += max(A[i], B[i]);
	printf("%lld\n", ans + n);
	return 0;
}