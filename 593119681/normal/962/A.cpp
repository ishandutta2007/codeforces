#include <cstdio>
#include <algorithm>
using namespace std;
#define N 200000 + 5

int n, A[N], Sum[N];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", A + i);
		Sum[i] = Sum[i - 1] + A[i];
	}
	printf("%d\n", lower_bound(Sum + 1, Sum + n + 1, Sum[n] + 1 >> 1) - Sum);
	return 0;
}