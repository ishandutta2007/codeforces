#include <cstdio>
#include <algorithm>
using namespace std;
#define N 300000 + 5
#define mp make_pair

int n, x_1, x_2, k_1, k_2, A[N], Ord[N];

bool Check(int u, int v)
{
	for (int i = n; i; i --)
		if (1LL * A[Ord[i]] * (n - i + 1) >= v)
		{
			for (int j = i - 1; j; j --)
				if (1LL * A[Ord[j]] * (i - j) >= u)
				{
					k_1 = i - j, k_2 = n - i + 1;
					return 1;
				}
			break ;
		}
	return 0;
}

int main()
{
	scanf("%d%d%d", &n, &x_1, &x_2);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", A + i);
		Ord[i] = i;
	}
	sort(Ord + 1, Ord + n + 1, [&](int u, int v) {
		return mp(A[u], u) < mp(A[v], v);
	});
	if (Check(x_1, x_2))
	{
		puts("Yes");
		printf("%d %d\n", k_1, k_2);
		for (int i = n - k_1 - k_2 + 1, j = 1; j <= k_1; i ++, j ++)
			printf("%d%c", Ord[i], j == k_1 ? '\n' : ' ');
		for (int i = n - k_2 + 1; i <= n; i ++)
			printf("%d%c", Ord[i], i == n ? '\n' : ' ');
	}
	else if (Check(x_2, x_1))
	{
		puts("Yes");
		printf("%d %d\n", k_2, k_1);
		for (int i = n - k_2 + 1; i <= n; i ++)
			printf("%d%c", Ord[i], i == n ? '\n' : ' ');
		for (int i = n - k_1 - k_2 + 1, j = 1; j <= k_1; i ++, j ++)
			printf("%d%c", Ord[i], j == k_1 ? '\n' : ' ');
	}
	else puts("No");
	return 0;
}