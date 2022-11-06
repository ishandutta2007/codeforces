#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100000 + 5

int Case, n, A[N];

int main()
{
	for (scanf("%d", &Case); Case; Case --)
	{
		scanf("%d", &n);
		bool has_0 = false, has_1 = false, has_con = false;
		for (int i = 1, x; i <= n; i ++)
		{
			scanf("%d", A + i);
			x = A[i];
			if (x == 0)
				has_0 = true;
			if (x == 1)
				has_1 = true;
		}
		sort(A + 1, A + n + 1);
		for (int i = 1; i < n; i ++)
			if (A[i] == A[i + 1] - 1)
				has_con = true;
		if (!has_1 || (!has_0 && !has_con))
			puts("YES");
		else puts("NO");
	}
	return 0;
}