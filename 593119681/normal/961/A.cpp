#include <cstdio>
#include <algorithm>
using namespace std;
#define N 1000 + 5

int k, n, T[N];

int main()
{
	scanf("%d%d", &k, &n);
	for (int i = 1, x; i <= n; i ++)
	{
		scanf("%d", &x);
		T[x] ++;
	}
	for (int i = 2; i <= k; i ++)
		T[i] = min(T[i], T[i - 1]);
	printf("%d\n", T[k]);
	return 0;
}